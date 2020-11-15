
#include <string>
#include <vector>
#include "regular_payment_repository_db.h"

using std::string;
using std::vector;

const string RegularPaymentRepositoryDb::TABLE = "regular_payments";

const vector<string> RegularPaymentRepositoryDb::COLUMNS{
    "id", "account_card", "period_sec", "target_card", "next_time", "sum"
};

const vector<string> RegularPaymentRepositoryDb::COLUMNS_NO_ID{
    "account_card", "period_sec", "target_card", "next_time", "sum"
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

Optional<RegularPayment> RegularPaymentRepositoryDb::_get_by_id(int id) const {
    Optional<map<string, QVariant>> res_optional = _db_service.select_one(
            TABLE, COLUMNS, "id=%0", {std::to_string(id)}
    );
    if (res_optional.is_empty()) {
        return Optional<RegularPayment>::empty();
    }
    return Optional<RegularPayment>::of(_get_entity_from_map(res_optional.get()));
}

void RegularPaymentRepositoryDb::_add(const RegularPayment& regular_payment) const {
    _db_service.insert(TABLE, COLUMNS_NO_ID, {
            "'" + regular_payment._account_card + "'",
            std::to_string(regular_payment._period_sec),
            "'" + regular_payment._target_card + "'",
            std::to_string(regular_payment._next_time),
            std::to_string(regular_payment._sum)
    });
}

int RegularPaymentRepositoryDb::_update(const RegularPayment& regular_payment) const {
    _db_service.update(
            TABLE,
            {
                    "account_card=%0",
                    "period_sec=%1",
                    "target_card=%2",
                    "next_time=%3",
                    "sum=%4"
            },
            "id=%5",
            {
                    "'" + regular_payment._account_card + "'",
                    std::to_string(regular_payment._period_sec),
                    "'" + regular_payment._target_card + "'",
                    std::to_string(regular_payment._next_time),
                    std::to_string(regular_payment._sum),
                    std::to_string(regular_payment._id)
            }
    );
}

int RegularPaymentRepositoryDb::_remove(int id) const {
    _db_service.remove(TABLE, "id=%0", {std::to_string(id)});
}

vector<RegularPayment> RegularPaymentRepositoryDb::_get_list(const Specification<RegularPayment> &regular_payment_specification) const {
    vector<map<string, QVariant>> rp_maps = _db_service.select_many(
            TABLE, COLUMNS, regular_payment_specification.get_where(), regular_payment_specification.get_params()
    );
    vector<RegularPayment> res;
    for (const auto &rp_map : rp_maps) {
        res.emplace_back(_get_entity_from_map(rp_map));
    }
    return res;
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

