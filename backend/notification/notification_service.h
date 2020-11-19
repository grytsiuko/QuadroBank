#ifndef QUADROBANK_NOTIFICATION_SERVICE_H
#define QUADROBANK_NOTIFICATION_SERVICE_H

#include <string>
#include <iostream>
#include <backend/account/model/account.h>
#include <backend/user/model/user.h>
#include "../utils/singleton.h"

using std::string;
using std::cout;

class NotificationService : public Singleton<NotificationService> {

private:

    friend Singleton;

    NotificationService() = default;

public:

    void notify(const User &user, const Account &account, const string &text) const;
};

#endif //QUADROBANK_NOTIFICATION_SERVICE_H
