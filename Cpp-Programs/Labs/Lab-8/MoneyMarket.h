#ifndef MONEYMARKET_H
#define MONEYMARKET_H
#include "Account.h"

class MoneyMarket : public Account
{
private:
	double lowBalFee;
	double minBal;
	double interest;
public:
	MoneyMarket(double lowBalFee, double minBal, double interest, int accountNumber = 0, string name = "");
	void processFessAndInterest();
	string getType();
	void printDetails();
};

#endif
