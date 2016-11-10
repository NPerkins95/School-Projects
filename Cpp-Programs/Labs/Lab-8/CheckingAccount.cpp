#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int accountNumber, string name) :
	Account(accountNumber, name) {
}

string CheckingAccount::getType() {
	return "Checking";
}
