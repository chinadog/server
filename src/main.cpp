#include <QCommandLineParser>
#include <QCoreApplication>
#include <QFile>
#include <QTranslator>
#include "server.h"
#include <TLogger/TLogger>
#include <QDebug>

QString getConfigPath(int argc, char *argv[])
{
    QStringList args;
    for(int i=0;i<argc;i++)
    {
        args.append(argv[i]);
    }
    QCommandLineParser parser;
    QString configPath = CONFIG_PATH;
    QList<QCommandLineOption> options;
    QCommandLineOption targetDirectoryOption(
        QStringList() << "c" << "config-path",
        QCoreApplication::translate("main", "Set config path <directory>."),
        QCoreApplication::translate("main", "directory"));
    options.append(targetDirectoryOption);
    parser.addOptions(options);

    parser.parse(args);

    QString targetDir = parser.value(options[0]);
    if(!targetDir.isEmpty())
    {
        configPath = targetDir;
    }
    return configPath;
}

bool configIsValid(QString configPath)
{
    QFile f(configPath+"trifecta.conf");
    if(f.exists())
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString configPath = getConfigPath(argc,argv);
    Server *server;
    if( configIsValid(configPath) )
    {
        TLogger::get().init(configPath.toStdString()+"trifecta.conf");
        // Загрузка переводов
        QTranslator myTranslator;
        QString translationPath = RESOURCES_PATH;
        translationPath += "translation/";
        myTranslator.load("trifecta_ru",translationPath);
        a.installTranslator(&myTranslator);
        TINFO() << "Start the server with the" << configPath <<
                   "configuration path";
        server = new Server(configPath);
        server->start();
    }
    else
    {
        TERROR() << "Configuration file doesn't exist in folder - " <<
                    configPath;
        TERROR() << "Closing application";
        return 1;
    }

    int r = a.exec();
    delete server;
    return r;
}

