
#include <string>
#include <vector>
#include <backend/utils/time_intervals.h>
#include <sstream>
#include "deposit_variant_repository_db.h"

using std::string;
using std::vector;
using std::stringstream;

const string DepositVariantRepositoryDb::TABLE = "deposit_variants";

const vector<string> DepositVariantRepositoryDb::COLUMNS{"period_sec", "percentage"};

const vector<string> DepositVariantRepositoryDb::COLUMNS_EXTENDED{
        "period_sec INTEGER NOT NULL",
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

string double_string(const double a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

Optional<DepositVariant> DepositVariantRepositoryDb::_get_by_percentage(double percentage) const {
    string tes = double_string(percentage);
    Optional<map<string, QVariant>> res_optional = _db_service.select_one(
            TABLE, COLUMNS, "percentage=%0", {double_string(percentage)}
    );
    if (res_optional.is_empty()) {
        return Optional<DepositVariant>::empty();
    }
    return Optional<DepositVariant>::of(_get_entity_from_map(res_optional.get()));
}

vector<DepositVariant> DepositVariantRepositoryDb::_get_list(const Specification<DepositVariant> &deposit_variant_specification) const {
    vector<map<string, QVariant>> deposit_variants_maps = _db_service.select_many(
            TABLE, COLUMNS, deposit_variant_specification.get_where(), deposit_variant_specification.get_params()
    );
    vector<DepositVariant> res;
    for (const auto &deposit_variant_map : deposit_variants_maps) {
        res.emplace_back(_get_entity_from_map(deposit_variant_map));
    }
    return res;
}

DepositVariant DepositVariantRepositoryDb::_get_entity_from_map(const map<string, QVariant> &data) const {
    return DepositVariant{
            data.at("period_sec").toInt(),
            data.at("percentage").toDouble(),
    };
}

