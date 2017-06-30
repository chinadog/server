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

#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QString>
#include "config.h"
#include <TDB/TDB>
#include "correl.h"
#include "filter.h"
/**
 * @brief Класс Server
 * Основной класс приложения. В соответствии с установленной конфигурацией
 * приложения, подключается к заданной БД и запускает потоки фильтрации,
 * нормализации и корреляции для обнаруженных в БД событий.
 */
class Server : public QObject
{
    Q_OBJECT
public:
    // Конструкторы
    Server(const QString& configPath);
    ~Server();

    // Метод
    void start();
private slots:
    void updateFilter(int i);
    void updateCorrel(int i);
    void updateCorrel2(int i);
private:
    Config m_config;
    TDB* m_tdb;
    Filter m_filter;
};

#endif // SERVER_H
