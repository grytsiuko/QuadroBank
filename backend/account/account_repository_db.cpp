#include <string>
#include <backend/account/account_repository_db.h>
#include <backend/utils/string_convert.h>
#include <backend/utils/cypher/xor_cypher.h>

using std::string;

const string AccountRepositoryDb::TABLE = "accounts";
const vector<string> AccountRepositoryDb::COLUMNS{
        "card_number", "user_id", "pin", "is_blocked", "balance", "credit_limit", "credit_start"
};
const vector<string> AccountRepositoryDb::COLUMNS_EXTENDED{
        "card_number VARCHAR(255) PRIMARY KEY",
        "user_id INT NOT NULL",
        "pin VARCHAR(255) NOT NULL",
        "is_blocked BOOLEAN NOT NULL",
        "balance INT NOT NULL",
        "credit_limit INT NOT NULL",
        "credit_start INT NOT NULL"
};

AccountRepositoryDb::AccountRepositoryDb() : _db_service(DBService::get_instance()) {
    _db_service.create_table_if_not_exists(TABLE, COLUMNS_EXTENDED);
    _seed_data();
}

vector<Account> AccountRepositoryDb::_get_list(const Specification<Account> &account_specification) const {
    vector<map<string, QVariant>> account_maps = _db_service.select_many(
            TABLE, COLUMNS, account_specification.get_where(), account_specification.get_params()
    );
    vector<Account> res;
    for (const auto &account_map : account_maps) {
        res.emplace_back(_get_entity_from_map(account_map));
    }
    return res;
}

Optional<Account> AccountRepositoryDb::_get_by_card_number(const string &card_number) const {
    Optional<map<string, QVariant>> res_optional = _db_service.select_one(
            TABLE, COLUMNS, "card_number=%0", {to_param(card_number)}
    );
    if (res_optional.is_empty()) {
        return Optional<Account>::empty();
    }
    return Optional<Account>::of(_get_entity_from_map(res_optional.get()));
}

void AccountRepositoryDb::_update(const Account &account) const {
    _db_service.update(
            TABLE,
            {
                    "user_id=%0",
                    "pin=%1",
                    "is_blocked=%2",
                    "balance=%3",
                    "credit_limit=%4",
                    "credit_start=%5",
            },
            "card_number=%6",
            {
                    to_param(account._user_id),
                    to_param(account._pin),
                    to_param(account._is_blocked),
                    to_param(account._balance),
                    to_param(account._credit_limit),
                    to_param(account._credit_start),
                    to_param(account._card_number)
            }
    );
}

void AccountRepositoryDb::_seed_data() const {
    const CypherInterface& cypher = XORCypher::get_instance();
    int count = _db_service.count(TABLE);
    if (count > 0) {
        return;
    }
    _db_service.insert(
            TABLE, COLUMNS, vector<string>{"'1111111111111111'", "15", "'" + cypher.encrypt("1111") + "'", "0", "15000", "5000", "0"}
    );
    _db_service.insert(
            TABLE, COLUMNS, vector<string>{"'2222222222222222'", "15", "'" + cypher.encrypt("2222") + "'", "0", "20000", "0", "0"}
    );
    _db_service.insert(
            TABLE, COLUMNS, vector<string>{"'3333333333333333'", "20", "'" + cypher.encrypt("3333") + "'", "0", "0", "3000", "0"}
    );
    _db_service.insert(
            TABLE, COLUMNS, vector<string>{"'1234123412341234'", "20", "'" + cypher.encrypt("3333") + "'", "0", "52000", "0", "0"}
    );
    _db_service.insert(
            TABLE, COLUMNS, vector<string>{"'4321432143214321'", "20", "'" + cypher.encrypt("3333") + "'", "0", "7400", "0", "0"}
    );
}

Account AccountRepositoryDb::_get_entity_from_map(const map<string, QVariant> &data) const {
    return Account{
            data.at("card_number").toString().toStdString(),
            data.at("user_id").toInt(),
            data.at("pin").toString().toStdString(),
            data.at("is_blocked").toBool(),
            data.at("balance").toInt(),
            data.at("credit_limit").toInt(),
            data.at("credit_start").toInt()
    };
}
