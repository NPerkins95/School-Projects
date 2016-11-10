#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accountNumber, string name, double interestRate) :
	Account(accountNumber, name) {
	if (interestRate < 0) {
		throw runtime_error("Interest Rate must be positive.");
	}
	this->interestRate = interestRate;
}

string SavingsAccount::getType() {
	return "Savings";
}

void SavingsAccount::printDetails() {
	cout << "Interest Rate: " << interestRate << "%" << endl;
}

void SavingsAccount::processInterest() {
	setBalance(getBalance()*(1 + (interestRate / 100)));
}