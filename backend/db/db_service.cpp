#include "db_service.h"

DBService::DBService() :
        _sdb(QSqlDatabase::addDatabase("QSQLITE", "main_connection")) {
    _sdb.setDatabaseName("test.sqlite");
    _assert_done(_sdb.open());
}

void DBService::_assert_done(bool flag) const {
    if (!flag) {
        _throw_db_exception();
    }
}

void DBService::_throw_db_exception() const {
    throw InternalDBError();
}

bool DBService::_exec(const string &sql) const {
    return QSqlQuery(_sdb).exec(sql.c_str());
}

string DBService::_generate_list(const vector<string> &values) const {
    string res;
    if (!values.empty()) {
        res += values[0];
    }
    for (size_t i = 1; i < values.size(); i++) {
        res += "," + values[i];
    }
    return res;
}

QString DBService::_set_params(const string &sql, const vector<string> &params) const {
    QString res = sql.c_str();
    for (const auto &param : params) {
        res = res.arg(param.c_str());
    }
    return res;
}

void DBService::create_table_if_not_exists(const string &name, const vector<string> &fields) const {
    string sql = "CREATE TABLE IF NOT EXISTS " + name + " (" + _generate_list(fields) + ")";

    QSqlQuery query(_sdb);
    _assert_done(_exec(sql));
}

int DBService::count(const string &table, const string &where, const vector<string> &params) const {
    string sql = "SELECT COUNT(*) AS val FROM " + table;
    if (!where.empty()) {
        sql += " WHERE " + where;
    }
    sql += ";";

    QSqlQuery query(_sdb);
    query.prepare(_set_params(sql, params));
    _assert_done(query.exec());
    QSqlRecord record = query.record();

    while (query.next()) {
        return query.value(record.indexOf("val")).toInt();
    }
    _throw_db_exception();
    return 0;
}

void DBService::insert(const string &table, const vector<string> &columns, const vector<string> &fields) const {
    string sql = "INSERT INTO " + table + " (" + _generate_list(columns) + ") VALUES (";
    if (!fields.empty()) {
        sql += "%0";
    }
    for (size_t i = 1; i < fields.size(); i++) {
        sql += ",%" + std::to_string(i);
    }
    sql += ");";

    QSqlQuery query(_sdb);
    query.prepare(_set_params(sql, fields));
    _assert_done(query.exec());
}

void DBService::update(
        const string &table,
        const vector<string> &expressions,
        const string &where,
        const vector<string> &params
) const {
    string sql = "UPDATE " + table + " SET " + _generate_list(expressions);
    if (!where.empty()) {
        sql += " WHERE " + where;
    }
    sql += ";";

    QSqlQuery query(_sdb);
    query.prepare(_set_params(sql, params));
    _assert_done(query.exec());
}

void DBService::remove(const string &table, const string &where, const vector<string> &params) const {
    string sql = "DELETE FROM " + table;
    if (!where.empty()) {
        sql += " WHERE " + where;
    }
    sql += ";";

    QSqlQuery query(_sdb);
    query.prepare(_set_params(sql, params));
    _assert_done(query.exec());
}

Optional<map<string, QVariant>> DBService::select_one(
        const string &table,
        const vector<string> &fields,
        const string &where,
        const vector<string> &params
) const {
    string sql = "SELECT " + _generate_list(fields) + " FROM " + table;
    if (!where.empty()) {
        sql += " WHERE " + where;
    }
    sql += ";";

    QSqlQuery query(_sdb);
    query.prepare(_set_params(sql, params));
    _assert_done(query.exec());
    QSqlRecord record = query.record();

    while (query.next()) {
        map<string, QVariant> res;
        for (const auto &field:fields) {
            res[field] = query.value(record.indexOf(field.c_str()));
        }
        return Optional<map<string, QVariant>>::of(res);
    }
    return Optional<map<string, QVariant>>::empty();
}

vector<map<string, QVariant>>
DBService::select_many(const string &table, const vector<string> &fields, const string &where,
                       const vector<string> &params) const {
    string sql = "SELECT " + _generate_list(fields) + " FROM " + table;
    if (!where.empty()) {
        sql += " WHERE " + where;
    }
    sql += ";";

    QSqlQuery query(_sdb);
    query.prepare(_set_params(sql, params));
    _assert_done(query.exec());
    QSqlRecord record = query.record();

    vector<map<string, QVariant>> res;
    while (query.next()) {
        map<string, QVariant> curr;
        for (const auto &field:fields) {
            curr[field] = query.value(record.indexOf(field.c_str()));
        }
        res.emplace_back(curr);
    }
    return res;
}

