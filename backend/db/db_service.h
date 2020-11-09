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

    DBService() {
        QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
        sdb.setDatabaseName("db.sqlite");
        assert_done(sdb.open());
    }

    void assert_done(bool flag) const {
        if (!flag) {
            throw Exception("Unable to connect to db");
        }
    }

    bool exec(const string &sql) const {
        return QSqlQuery().exec(sql.c_str());
    }

    ~DBService() override = default;

public:

    void create_table_if_not_exists(const string &name, const vector<string> &fields) const {
        string sql = "CREATE TABLE IF NOT EXISTS " + name + " (";
        if (!fields.empty()) {
            sql += fields[0];
        }
        for (size_t i = 1; i < fields.size(); i++) {
            sql += "," + fields[i];
        }
        sql += ")";

        QSqlQuery query;
        assert_done(exec(sql));
    }
};

#endif //QUADROBANK_DB_SERVICE_H
