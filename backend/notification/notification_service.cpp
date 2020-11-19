#include "notification_service.h"

void NotificationService::notify(const User &user, const Account &account, const string &text) const {
    cout << "### Notification to " << user._name
         << " on card " << account._card_number
         << ": " << text << "\n";
}
