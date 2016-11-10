#include <iostream>
#include "Bank.h"
#include "SavingsAccount.h"
using namespace std;

void printMenu();
char getMenuSelection();
void addAccount(Bank& b, Account::type type);
void printAccount(Bank& b);
void processMenuSelection(char selection, Bank& b);
void makeDeposit(Bank& b);
void doWithdrawl(Bank& b);
void processInterest(Bank& b);

int main() {
	Bank bank;
	char choice = '0';
	while (choice != 'X') {
		printMenu();
		choice = getMenuSelection();
		try {
			processMenuSelection(choice, bank);
		}
		catch (runtime_error& e) {
			cout << endl << "Error: " << e.what() << endl;
		}
		catch (...) {
			cout << endl << "Unknown error..." << endl;
		}
	}
}

void printMenu() {
	cout << endl;
	cout << "1: Add Checking Account" << endl;
	cout << "2: Add Savings Account" << endl;
	cout << "3: Show Account" << endl;
	cout << "4: Show All Accounts" << endl;
	cout << "5: Make a Deposit" << endl;
	cout << "6: Make a Withdrawl" << endl;
	cout << "7: Process Interest" << endl;
	cout << "X: Exit" << endl;
	cout << endl << "Please enter choice: ";
}

void processMenuSelection(char selection, Bank& bank) {
	switch (selection) {
	case '1':
		addAccount(bank, Account::CHECKING);
		break;
	case '2':
		addAccount(bank, Account::SAVINGS);
		break;
	case '3':
		addAccount(bank, Account::MONEYMARKET);
		break;
	case '4':
		printAccount(bank);
		break;
	case '5':
		bank.printAccounts();
		break;
	case '6':
		makeDeposit(bank);
		break;
	case '7':
		doWithdrawl(bank);
		break;
	case '8':
		processInterest(bank);
	case '9';
		processFeesAndInterest(bank);
	}
}

char getMenuSelection() {
	char ch = '0';
	cin >> ch;
	cin.clear(); // unset failbit
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
	cout << endl;
	return toupper(ch);
}

int getAccountNumber() {
	int accountNumber = 0;
	cout << "Enter Account Number: ";
	cin >> accountNumber;
	cout << endl;
	cin.clear(); // unset failbit
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skip bad input 
	return accountNumber;
}

double getAmount() {
	double amount = 0;
	cout << "Enter Amount: ";
	cin >> amount;
	cout << endl;
	return amount;
}

void addAccount(Bank& b, Account::type type) {
	string ownerName;
	int accountNumber = 0;
	double interestRate = 0.0;
	int checkLimit = 0;

	accountNumber = getAccountNumber();

	cout << "Enter Account Owner's Name: ";
	getline(cin, ownerName);

	switch (type) {
	case Account::SAVINGS:
		cout << "Enter Interest Rate: ";
		cin >> interestRate;
		cout << endl;
		b.addSavingsAccount(accountNumber, ownerName, interestRate);
		break;
	case Account::CHECKING:
		b.addCheckingAccount(accountNumber, ownerName);
		break;
	case Account::MONEYMARKET:
		cout << "Enter Low balance fee: ";
		cin >> lowBalFee;
		cout << endl << "Enter Minimum balance to avoid fee: ";
		cin >> minBal;
		cout << "Enter interest rate when above minimum balance: ";
		cin >> interest;
		b.addMoneyMarketAccount(lowBalFee, minBal, interest, accountNumber, ownerName);
		break;
	}
}

void makeDeposit(Bank& b) {

	b.makeDeposit(getAccountNumber(), getAmount());

}

void doWithdrawl(Bank& b) {

	b.doWithdrawl(getAccountNumber(), getAmount());

}

void processInterest(Bank&  b) {
	try {
		Account* a = b.getAccount(getAccountNumber());
		SavingsAccount* s = dynamic_cast<SavingsAccount*>(a);
		s->processInterest();
	}
	catch (...) {
		cout << "Wrong Account Type" << endl;
	}
}

void printAccount(Bank& b) {
	int accountNumber = 0;

	cout << "Enter Account Number: ";
	cin >> accountNumber;
	cout << endl;

	b.printAccount(accountNumber);
}



