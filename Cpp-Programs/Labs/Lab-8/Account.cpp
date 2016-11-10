#include "Account.h"
#include <iostream>

Account::Account(int accountNumber, string name) :
	owner(name), accountNumber(accountNumber), balance(0) {}

void Account::makeDeposit(double amount) {
	if (amount < 0) {
		throw runtime_error("Deposit amount cannot be negative.");
	}
	balance += amount;
}

void Account::doWithdrawal(double amount) {
	if (amount < 0) {
		throw runtime_error("Withdrawl amount cannot be negative.");
	}
	if (balance < amount) {
		throw runtime_error("You cannot withdraw more than your balance.");
	}
	balance -= amount;
}

void Account::setBalance(double balance) {
	this->balance = balance; // whis is this-> used here?
}

double Account::getBalance() {
	return balance; // why is this-> not used here?
}

void Account::setAccountNumber(int accountNumber) {
	this->accountNumber = accountNumber;
}

int Account::getAccountNumber() {
	return accountNumber;
}

void Account::setOwner(string ownerName) {
	owner = ownerName;
}

string Account::getOwner() {
	return owner;
}

void Account::printAccount() {
	cout << "-- " << this->getType() << " Account --" << endl;
	cout << "Account Number: " << getAccountNumber() << endl;
	cout << "Balance: " << getBalance() << endl;
	this->printDetails();
	cout << "---------------------" << endl;
}

void Account::printDetails() {
}
