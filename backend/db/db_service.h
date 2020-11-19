#ifndef QUADROBANK_DB_SERVICE_H
#define QUADROBANK_DB_SERVICE_H

#include "../utils/singleton.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QtSql/QSqlRecord>
#include <QtCore/QVariant>
#include <backend/utils/exceptions/internal_db_error.h>
#include "backend/utils/exceptions/exception.h"
#include "../utils/optional.h"


using std::cout;
using std::map;
using std::vector;

class DBService : public Singleton<DBService> {

private:

    friend Singleton;
    QSqlDatabase _sdb;

    DBService();

    void _assert_done(bool flag) const;

    void _throw_db_exception() const;

    bool _exec(const string &sql) const;

    string _generate_list(const vector<string> &values) const;

    QString _set_params(const string &sql, const vector<string> &params) const;

    ~DBService() override = default;

public:


    void create_table_if_not_exists(const string &name, const vector<string> &fields) const;

    int count(const string &table, const string &where = "", const vector<string> &params = {}) const;

    void insert(const string &table, const vector<string> &columns, const vector<string> &fields) const;

    void update(
            const string &table,
            const vector<string> &expressions,
            const string &where,
            const vector<string> &params
    ) const;

    void remove(const string &table, const string &where, const vector<string> &params) const;

    Optional<map<string, QVariant>> select_one(
            const string &table,
            const vector<string> &fields,
            const string &where = "",
            const vector<string> &params = {}
    ) const;

    vector<map<string, QVariant>> select_many(
            const string &table,
            const vector<string> &fields,
            const string &where = "",
            const vector<string> &params = {}
    ) const;
};

#endif //QUADROBANK_DB_SERVICE_H
