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

#ifndef CORREL_H
#define CORREL_H

#include <TDB/TDB>
#include <QObject>

/**
 * @brief Класс Correl
 * @details Предназначен для корреляции (обнаружения зависимостей) между
 * событиями и записи их в БД. Обнаруживает новые события в БД, проводит анализ
 * по заданным правилам и записывает обнаруженные угрозы среди событий в БД.
 */
class Correl : public QObject
{
    Q_OBJECT
public:
    // Конструкторы
    Correl(const QString &connectionName);

public slots:
    void doWork();
signals:
    void send(int);
private:
    TDB *m_tdb;
};

#endif // CORREL_H
