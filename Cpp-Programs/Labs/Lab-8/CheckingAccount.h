#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <string>
using namespace std;

class CheckingAccount : public Account {
public:
	CheckingAccount(int accountNumber = 0, string name = "");
	string getType();
};


#endif
