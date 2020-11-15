
#include <string>
#include <vector>
#include "deposit_repository_db.h"

using std::string;
using std::vector;

const string DepositRepositoryDb::TABLE = "deposits";

const vector<string> DepositRepositoryDb::COLUMNS{
        "id", "account_card_number", "percentage", "period_sec", "start_date", "end_date", "sum"
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

Deposit DepositRepositoryDb::_get_entity_from_map(const map<string, QVariant> &data) const {
    return Deposit{
            data.at("id").toInt(),
            data.at("account_card").toString().toStdString(),
            data.at("percentage").toDouble(),
            data.at("period_sec").toInt(),
            data.at("start_date").toInt(),
            data.at("end_date").toInt(),
            data.at("sum").toInt()
    };
}

