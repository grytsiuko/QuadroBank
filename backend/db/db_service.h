#ifndef QUADROBANK_DB_SERVICE_H
#define QUADROBANK_DB_SERVICE_H

#include "../utils/singleton.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include "../utils/exception.h"

using std::cout;

class DBService : public Singleton<DBService> {

private:

    friend Singleton;

    const string CREATE_USERS_TABLE_SQL = "CREATE TABLE IF NOT EXISTS users ("
                                          "  id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                          "  name VARCHAR(255) NOT NULL"
                                          ");";

    DBService() {
        QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
        sdb.setDatabaseName("db.sqlite");
        assert_done(sdb.open());

        QSqlQuery a_query;
        assert_done(a_query.exec(CREATE_USERS_TABLE_SQL.c_str()));
    }

    void assert_done(bool flag) const {
        if (!flag) {
            throw Exception("Unable to connect to db");
        }
    }

    ~DBService() override = default;

public:
};

#endif //QUADROBANK_DB_SERVICE_H
