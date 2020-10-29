

#include "deposit_service.h"

vector<DepositDto> DepositService::get_all_by_user(const SessionDto &sessionDto) const {
    const string card_number = _token_service.get_card_number(sessionDto._token);
    const Optional<Account> optionalAccount = _account_repository.get_by_card_number(card_number);
    if (optionalAccount.is_empty()) {
        throw Exception("Illegal token");
    }

    const Account account = *optionalAccount.get();
    const vector<Account> accounts = _account_repository.get_list(
            Specification<Account>([&](const Account &acc) { return acc._user_id == account._user_id; }));

    const vector<Deposit> deposits = _deposit_repository.get_list(Specification<Deposit>([&](const Deposit &d) {
        for (const Account &acc : accounts) {
            if (acc._card_number == d._account_card_number) {
                return true;
            }
        }
        return false;
    }));

    vector<DepositDto> depositDtos;

    depositDtos.reserve(deposits.size());
    for (const Deposit& d : deposits) {
        depositDtos.push_back(DepositDto{d._id, d._period_sec, d._start_date, d._end_date, d._percentage, d._sum});
    }

    return depositDtos;
}

vector<DepositVariantDto> DepositService::get_possible_variants() const {
    vector<DepositVariantDto> all_variants;
    all_variants.push_back(DepositVariantDto{100, 9});
    all_variants.push_back(DepositVariantDto{1000, 10});
    all_variants.push_back(DepositVariantDto{10000, 10.5});
    return all_variants;
}

void DepositService::add(const DepositCreateDto &depositCreateDto) const {
    const string card_number = _token_service.get_card_number(depositCreateDto._token);
    const time_t currDate = time(nullptr);
    Deposit deposit{0, card_number,  depositCreateDto._percentage, depositCreateDto._period_sec, currDate, currDate+depositCreateDto._period_sec, depositCreateDto._sum};
    _deposit_repository.add(deposit);
}

void DepositService::remove(const int id) const {
    _deposit_repository.remove(id);
}

vector<Deposit> DepositService::get_to_be_paid() const {
    time_t current_time = time(nullptr);
    return _deposit_repository.get_list(Specification<Deposit>([&](const Deposit& d){return d._end_date <= current_time;}));
}



