#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Account.h"
using namespace std;

class Bank {
	vector<Account*> accounts;
public:
	void addCheckingAccount(int accountNumber, string name);
	void addSavingsAccount(int accountNumber, string name, double interestRate);
	void addMoneyMarketAccount(double lowBalFee, double minBal, double interest, int accountNumber, string name);
	void printAccounts();
	void printAccount(int accountNumber);
	Account* getAccount(int accountNumber);
	void makeDeposit(int accountNumber, double amount);
	void doWithdrawl(int accountNumber, double amount);
};


#endif
