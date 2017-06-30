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

#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
/**
 * @brief Класс Config
 * @details Предназначен для загрузки и хранения конфигурации приложения.
 */
class Config
{
public:
    // Конструкторы
    Config();
    Config(const QString &confPath);

    // Методы
    void load(const QString &confPath);

    /**
     * @brief Структура DB
     * @details предназначена для хранения конфигурации подключения к БД
     */
    struct DB
    {
    private:
        QString m_databaseName;
        QString m_hostName;
        QString m_userName;
        QString m_password;
        int m_port;
    public:
        QString databaseName() const;
        QString hostName() const;
        QString userName() const;
        QString password() const;
        int port() const;
        void setDatabaseName(const QString &databaseName);
        void setHostName(const QString &hostName);
        void setPassword(const QString &password);
        void setPort(int value);
        void setUserName(const QString &userName);
    }db;
    QString path() const;
    void setPath(const QString &path);

private:
    QString m_path;
};

#endif // CONFIG_H
