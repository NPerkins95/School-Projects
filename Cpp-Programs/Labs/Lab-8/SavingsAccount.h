#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"
#include <string>
using namespace std;

class SavingsAccount : public Account {
	double interestRate;
public:
	SavingsAccount(int accountNumber = 0, string name = "", double interestRate = 0.0);
	string getType();
	void printDetails();
	void processInterest();
};

#endif
