#ifndef QUADROBANK_DB_SERVICE_H
#define QUADROBANK_DB_SERVICE_H

#include "../utils/singleton.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QtSql/QSqlRecord>
#include <QtCore/QVariant>
#include <sstream>
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
            throw_db_exception();
        }
    }

    void throw_db_exception() const {
        throw Exception("Unable to connect to db");
    }

    bool exec(const string &sql) const {
        return QSqlQuery().exec(sql.c_str());
    }

    string generate_list(const vector<string> &values) const {
        string res;
        if (!values.empty()) {
            res += values[0];
        }
        for (size_t i = 1; i < values.size(); i++) {
            res += "," + values[i];
        }
        return res;
    }

    ~DBService() override = default;

public:

    void create_table_if_not_exists(const string &name, const vector<string> &fields) const {
        string sql = "CREATE TABLE IF NOT EXISTS " + name + " (" + generate_list(fields) + ")";

        QSqlQuery query;
        assert_done(exec(sql));
    }

    int count(const string &table, const string &where = "") const {
        string sql = "SELECT COUNT(*) AS val FROM " + table;
        if (!where.empty()) {
            sql += " WHERE " + where;
        }
        sql += ";";

        QSqlQuery query;
        assert_done(query.exec(sql.c_str()));
        QSqlRecord record = query.record();

        while (query.next()) {
            return query.value(record.indexOf("val")).toInt();
        }
        throw_db_exception();
    }

    void insert(const string &table, const vector<string> &columns, const vector<string> &fields) const {
        string sql = "INSERT INTO " + table + " (" + generate_list(columns) + ") VALUES (";
        if (!fields.empty()) {
            sql += "%0";
        }
        for(size_t i = 1; i < fields.size(); i++) {
            std::stringstream ss;
            ss << ",%" << i;
            sql += ss.str();
        }
        sql += ");";

        QString q_string = sql.c_str();
        for(const auto & field : fields) {
            q_string = q_string.arg(field.c_str());
        }

        QSqlQuery query;
        query.prepare(q_string);
        assert_done(query.exec());
    }
};

#endif //QUADROBANK_DB_SERVICE_H
