/* ---------------------------------------------------------------------------
 * Copyright © 2017 The trifecta Company Ltd.
 * Contact: http://www.trifecta.ru/licensing/
 * Author: BM
 *
 * This file is part of the Trifecta.
 *
 * Trifecta is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Trifecta is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 * ---------------------------------------------------------------------------
 */

#ifndef FILTERTHREAD_H
#define FILTERTHREAD_H

#include <TDB/TDB>
#include <QObject>
#include <QThread>
#include <TRules/TRules>


/**
 * @brief Класс Filter
 * @details Предназначен для фильтрации (обнаружения значимых) событиями и
 * записи их в БД. Обнаруживает новые события в БД, проводит фильтрацию по
 * заданным правилам и записывает обнаруженные значимые события в БД.
 */
class Filter : public QThread
{
    Q_OBJECT
public:
    // Конструкторы
    Filter();
    Filter(const QString &confPath);
    void setRules(const QString &configPath);
public slots:
    void doWork(const Event& event);
signals:
    void send(int);
private:
    TDB m_tdb;
    int m_id;
    QVector<Event> m_events;
    Rules m_rules;

    void run() override;
};

#endif // FILTERTHREAD_H
