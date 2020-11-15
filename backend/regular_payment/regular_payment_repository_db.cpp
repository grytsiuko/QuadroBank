
#include <string>
#include <vector>
#include "regular_payment_repository_db.h"

using std::string;
using std::vector;

const string RegularPaymentRepositoryDb::TABLE = "regular_payments";

const vector<string> RegularPaymentRepositoryDb::COLUMNS{
    "id", "account_card", "period_sec", "target_card", "next_time", "sum"
};

const vector<string> RegularPaymentRepositoryDb::COLUMNS_EXTENDED{
        "id INTEGER PRIMARY KEY AUTOINCREMENT",
        "account_card VARCHAR(255) NOT NULL",
        "period_sec INTEGER NOT NULL",
        "target_card VARCHAR(255) NOT NULL",
        "next_time INTEGER NOT NULL",
        "sum INTEGER NOT NULL"
};

RegularPaymentRepositoryDb::RegularPaymentRepositoryDb() : _db_service(DBService::get_instance()) {
    _db_service.create_table_if_not_exists(TABLE, COLUMNS_EXTENDED);
    _seed_data();
}

void RegularPaymentRepositoryDb::_seed_data() const {
    int count = _db_service.count(TABLE);
    if (count > 0) {
        return;
    }
    // empty seed
}

RegularPayment RegularPaymentRepositoryDb::_get_entity_from_map(const map<string, QVariant> &data) const {
    return RegularPayment{
            data.at("id").toInt(),
            data.at("account_card").toString().toStdString(),
            data.at("period_sec").toInt(),
            data.at("target_card").toString().toStdString(),
            data.at("next_time").toInt(),
            data.at("sum").toInt()
    };
}

