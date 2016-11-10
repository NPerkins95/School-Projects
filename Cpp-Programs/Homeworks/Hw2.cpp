#include <iostream>
using namespace std;

int main()
{
	int userNum;
	char more = 'y';
	
	while(more == 'y' || more == 'Y')
	{
		cout << "Please input an integer: ";
		cin >> userNum;
		cout << endl;
		
		if(userNum % 2 == 0)
		{
			cout << "Even" << endl;
		}
		else
		{
			cout << "Odd" << endl;
		}
		
		cout << "Do more (Y/N) ?  ";
		cin >> more;
		cout << endl << endl;
	}
}
