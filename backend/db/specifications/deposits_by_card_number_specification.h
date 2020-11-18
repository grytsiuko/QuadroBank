
#ifndef QUADROBANK_DEPOSITS_BY_CARD_NUMBER_SPECIFICATION_H
#define QUADROBANK_DEPOSITS_BY_CARD_NUMBER_SPECIFICATION_H


#include <backend/deposit/model/deposit.h>

#include <utility>
#include "specification.h"
#include <backend/utils/string_convert.h>

class DepositsByCardNumberSpecification: public Specification<Deposit> {

private:
    const string _card_number;
    const string _where = "account_card_number = %0";
    const vector<string> _params = {to_param(_card_number)};

public:
    explicit DepositsByCardNumberSpecification(const string& card_number): _card_number(card_number){}

private:
    bool _filter(const Deposit &d) const override {
        return _card_number == d._account_card_number;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};


#endif //QUADROBANK_DEPOSITS_BY_CARD_NUMBER_SPECIFICATION_H
