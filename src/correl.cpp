#include <TLogger/TLogger>
#include "correl.h"
#include <unistd.h> //tmp

//------------------------------------------------------------------------------
//                               Конструкторы
//------------------------------------------------------------------------------

Correl::Correl(const QString &/*connectionName*/)
{
    m_tdb = new TDB(/*connectionName*/);
}

//------------------------------------------------------------------------------
//                                  Методы
//------------------------------------------------------------------------------

void Correl::doWork()
{
    TDEBUG() << "START COREL THRED";
    for(int i=0;i<2;i++)
    {
        //emit send(i);
        TDEBUG() << "CORREL" << i << "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                 "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                 "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                 "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                 "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                 "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n"
                    "jshfksdhfjsdh fhsdhfksjdh fhdsjkhf s \n";
//        usleep(10); // 100000
    }
}

