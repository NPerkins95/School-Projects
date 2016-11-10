#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int checkNum;
	int i = 0;
	vector<int> tipPercent(0);
	int input;
	double tip;
	
	cout << "Enter check amount: ";
	cin >> checkNum;
	
	cout << "Enter tip percentages separated by spaces and then a letter when done: " << endl;
	do
	{
		cin >> input;
		tipPercent.push_back(input);
		i++;
	} while(tipPercent.at(i-1));
	
	cout << "For a $" << checkNum << " check" << endl;
	cout << "Tips:" << endl;
	
	sort(tipPercent.begin(), tipPercent.end());
	for (i = tipPercent.size() - 1; i > 0;  i--)
	{
		tip = tipPercent.at(i) * checkNum * .01;	
		cout << tipPercent.at(i) << "% $" << tip << endl;
	}
}
