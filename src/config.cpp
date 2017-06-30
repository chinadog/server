#include <TLogger/TLogger>
#include <QSettings>
#include "config.h"

//------------------------------------------------------------------------------
//                               Конструкторы
//------------------------------------------------------------------------------

Config::Config()
{

}

Config::Config(const QString &confPath)
{
    load(confPath);
}

//------------------------------------------------------------------------------
//                                  Методы
//------------------------------------------------------------------------------

void Config::load(const QString &confPath)
{
    QSettings settings(confPath+"trifecta.conf",QSettings::NativeFormat);
    // Загрузка блока конфигурации подключения к БД
    db.setDatabaseName( settings.value("databaseName","Syslog").toString() );
    db.setHostName( settings.value("hostName","localhost").toString() );
    db.setPassword( settings.value("password","postgres").toString() );
    db.setUserName( settings.value("userName","postgres").toString() );
    db.setPort( settings.value("port",5432).toInt() );
    //
    setPath(confPath);
}

QString Config::path() const
{
    return m_path;
}

void Config::setPath(const QString &path)
{
    m_path = path;
}


//------------------------------------------------------------------------------
//                     Блок конфигурации подключения к БД
//------------------------------------------------------------------------------

QString Config::DB::databaseName() const
{
    return m_databaseName;
}

QString Config::DB::hostName() const
{
    return m_hostName;
}

QString Config::DB::password() const
{
    return m_password;
}

int Config::DB::port() const
{
    return m_port;
}

QString Config::DB::userName() const
{
    return m_userName;
}

void Config::DB::setDatabaseName(const QString &databaseName)
{
    m_databaseName = databaseName;
}

void Config::DB::setHostName(const QString &hostName)
{
    m_hostName = hostName;
}

void Config::DB::setPassword(const QString &password)
{
    m_password = password;
}

void Config::DB::setPort(int value)
{
    m_port = value;
}

void Config::DB::setUserName(const QString &userName)
{
    m_userName = userName;
}

//------------------------------------------------------------------------------
//                       Блок
//------------------------------------------------------------------------------


