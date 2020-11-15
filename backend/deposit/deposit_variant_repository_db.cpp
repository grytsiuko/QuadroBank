
#include <string>
#include <vector>
#include <backend/utils/time_intervals.h>
#include "deposit_variant_repository_db.h"

using std::string;
using std::vector;

const string DepositVariantRepositoryDb::TABLE = "deposit_variants";

const vector<string> DepositVariantRepositoryDb::COLUMNS{"period_sec", "percentage"};

const vector<string> DepositVariantRepositoryDb::COLUMNS_EXTENDED{
        "period_sec INTEGER PRIMARY KEY",
        "percentage REAL PRIMARY KEY"
};

DepositVariantRepositoryDb::DepositVariantRepositoryDb() : _db_service(DBService::get_instance()) {
    _db_service.create_table_if_not_exists(TABLE, COLUMNS_EXTENDED);
    _seed_data();
}

void DepositVariantRepositoryDb::_seed_data() const {
    int count = _db_service.count(TABLE);
    if (count > 0) {
        return;
    }
    _db_service.insert(TABLE, COLUMNS, {std::to_string(10 * TimeIntervals::SECOND), std::to_string(0.01)});
    _db_service.insert(TABLE, COLUMNS, {std::to_string(TimeIntervals::MINUTE), std::to_string(0.1)});
    _db_service.insert(TABLE, COLUMNS, {std::to_string(2 * TimeIntervals::MINUTE), std::to_string(0.3)});
}

DepositVariant DepositVariantRepositoryDb::_get_entity_from_map(const map<string, QVariant> &data) const {
    return DepositVariant{
            data.at("period_sec").toInt(),
            data.at("percentage").toDouble(),
    };
}

