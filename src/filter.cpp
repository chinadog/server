#include <TLogger/TLogger>
#include "filter.h"
#include <unistd.h> //tmp
#include "QTime"

//------------------------------------------------------------------------------
//                             Конструкторы
//------------------------------------------------------------------------------

Filter::Filter()
{

}

Filter::Filter(const QString &confPath) :
    m_rules(confPath+"/rules/filter/win.rule")
{

}

void Filter::setRules(const QString &confPath)
{
    m_rules = Rules(confPath+"/rules/filter/win.rule");
    TDEBUG() << m_rules;
}

//------------------------------------------------------------------------------
//                                Методы
//------------------------------------------------------------------------------

void Filter::doWork(const Event& event)
{
    m_events.push_back( event );
    if(!isRunning())
    {
        start();
    }
}

void Filter::run()
{
    qDebug() << "Start run";
    while(m_events.size() > 0)
    {
        qDebug() << m_events[0].id << m_events[0].msg.left(10);
        Event event = m_events[0];
        m_rules.exec(event.msg, event.time.toMSecsSinceEpoch());
        m_events.removeFirst();

    }
    qDebug() << "end run";
}

