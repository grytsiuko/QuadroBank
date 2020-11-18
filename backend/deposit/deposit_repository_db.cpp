
#include <string>
#include <vector>
#include <sstream>
#include <backend/utils/string_convert.h>
#include "deposit_repository_db.h"

using std::string;
using std::vector;
using std::stringstream;

const string DepositRepositoryDb::TABLE = "deposits";

const vector<string> DepositRepositoryDb::COLUMNS{
        "id", "account_card_number", "percentage", "period_sec", "start_date", "end_date", "sum"
};

const vector<string> DepositRepositoryDb::COLUMNS_NO_ID{
        "account_card_number", "percentage", "period_sec", "start_date", "end_date", "sum"
};

const vector<string> DepositRepositoryDb::COLUMNS_EXTENDED{
        "id INTEGER PRIMARY KEY AUTOINCREMENT",
        "account_card_number VARCHAR(255) NOT NULL",
        "percentage REAL NOT NULL",
        "period_sec INTEGER NOT NULL",
        "start_date INTEGER NOT NULL",
        "end_date INTEGER NOT NULL",
        "sum INTEGER NOT NULL"
};

DepositRepositoryDb::DepositRepositoryDb() : _db_service(DBService::get_instance()) {
    _db_service.create_table_if_not_exists(TABLE, COLUMNS_EXTENDED);
    _seed_data();
}

void DepositRepositoryDb::_seed_data() const {
    int count = _db_service.count(TABLE);
    if (count > 0) {
        return;
    }
    // empty seed
}

void DepositRepositoryDb::_add(const Deposit& deposit) const {
    _db_service.insert(TABLE, COLUMNS_NO_ID, {
        "'" + deposit._account_card_number + "'",
        to_param(deposit._percentage),
        std::to_string(deposit._period_sec),
        std::to_string(deposit._start_date),
        std::to_string(deposit._end_date),
        std::to_string(deposit._sum)
    });
}

void DepositRepositoryDb::_remove(int id) const {
    _db_service.remove(TABLE, "id=%0", {std::to_string(id)});
}

vector<Deposit> DepositRepositoryDb::_get_list(const Specification<Deposit> &deposit_specification) const {
    vector<map<string, QVariant>> deposit_maps = _db_service.select_many(
            TABLE, COLUMNS, deposit_specification.get_where(), deposit_specification.get_params()
    );
    vector<Deposit> res;
    for (const auto &deposit_map : deposit_maps) {
        res.emplace_back(_get_entity_from_map(deposit_map));
    }
    return res;
}

Deposit DepositRepositoryDb::_get_entity_from_map(const map<string, QVariant> &data) const {
    return Deposit{
            data.at("id").toInt(),
            data.at("account_card_number").toString().toStdString(),
            data.at("percentage").toDouble(),
            data.at("period_sec").toInt(),
            data.at("start_date").toInt(),
            data.at("end_date").toInt(),
            data.at("sum").toInt()
    };
}

