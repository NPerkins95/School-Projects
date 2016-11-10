#include "MoneyMarket.h"

MoneyMarket::MoneyMarket(double lowBalFee, double minBal, double interest, int accountNumber, string name)
	: Account(accountNumber, name)
{
	this->lowBalFee = lowBalFee;
	this->minBal = minBal;
	this->interest = interest;
}

string MoneyMarket::getType()
{
	return "";
}

void MoneyMarket::printDetails()
{
	
}

void MoneyMarket::processFessAndInterest()
{
	if (balance < minBal)
	{
		balance -= lowBalFee;
	}
	else
	{
		balance += balance * interest;
	}
}
