#include <TDB/TDB>
#include <TLogger/TLogger>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QThread>
#include "server.h"
#include <unistd.h>

//--------------------------------------------------------------------------------------
//                                  Конструкторы
//--------------------------------------------------------------------------------------

Server::Server(const QString &configPath)
{
    // Загрузка конфигурации
    m_config.load(configPath);
    m_filter.setRules(configPath);
}

Server::~Server()
{
    delete m_tdb;
}

//--------------------------------------------------------------------------------------
//                                     Методы
//--------------------------------------------------------------------------------------

void Server::start()
{
    m_tdb = new TDB;
    m_tdb->setConnectionName("connectionName",
                             m_config.db.databaseName(),
                             m_config.db.hostName(),
                             m_config.db.userName(),
                             m_config.db.password(),
                             m_config.db.port()
                             );
    m_tdb->subscribeToNotificationEvents();
    connect(m_tdb,SIGNAL(eventUpdated(int)),this,SLOT(updateFilter(int)));

}

void Server::updateFilter(int i)
{
    ResultAsync<Event> *res = m_tdb->messageAsync(i);
    connect(res,SIGNAL(ready(Event)),&m_filter,SLOT(doWork(Event)));
}

void Server::updateCorrel(int i)
{
    TDEBUG() << "CORREL " << i << "1sjfh jshdfjkhsdjkfh jkshd fjkhsdkfh ksjdh fkdsf" << i;
    TDEBUG() << "CORREL " << i << "2sjfh jshdfjkhsdjkfh jkshd fjkhsdkfh ksjdh fkdsf" << i;
}

void Server::updateCorrel2(int i)
{
    TDEBUG() << "CORREL2" << i << "1sjfh jshdfjkhsdjkfh jkshd fjkhsdkfh ksjdh fkdsf" << i;
    TDEBUG() << "CORREL2" << i << "2sjfh jshdfjkhsdjkfh jkshd fjkhsdkfh ksjdh fkdsf" << i;
}

