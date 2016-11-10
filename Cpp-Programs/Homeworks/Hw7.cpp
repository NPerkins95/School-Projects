#include <iostream>
using namespace std;

bool Palindrome(string x)
{
	bool test = true;
	for(int i = 0; i < (x.size() / 2); i++)
	{
		if (x.at(i) != x.at(x.size() - 1 - i))
		{
			test = false;
		}
	}
	
	if(test == false)
	{
		return test;
	}
	else
	{
		return true;
	}
}

int main()
{
	string x;
	bool palin;
	char more = 'y';
	
	while(more == 'y' || more == 'Y')
	{
		cout << "Enter a word: ";
		cin >> x;
		cout << endl << endl;
		palin = Palindrome (x);
		
		if(palin == true)
			cout << "\"" << x << "\"" << " is a palindrome" << endl << endl;
		else
			cout << "\"" << x << "\"" << " is NOT a palindrome" << endl << endl;
		
		cout << "Do you want to check another? (y/n)" << endl;
		cin >> more;
		cout << endl << endl;
	}
	
}
