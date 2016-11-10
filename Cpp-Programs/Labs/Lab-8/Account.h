#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <string>
using namespace std;

class Account {
protected:
	double balance;
	int accountNumber;
	string owner;
public:
	enum type
	{
		CHECKING, SAVINGS
	};
	Account(int accountNumber = 0, string name = "");
	void makeDeposit(double amount);
	void doWithdrawal(double amount);
	void setBalance(double balance);
	double getBalance();
	void setAccountNumber(int accountNumber);
	int getAccountNumber();
	void setOwner(string ownerName);
	string getOwner();
	void printAccount();
	virtual string getType() = 0;
	virtual void printDetails();
};

#endif
