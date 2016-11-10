#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char more = 'y';
	vector< vector<int> > table;
	vector<int> row;
	int number, i, j;
	
	while(more == 'y' || more == 'Y')
	{
		cout << "Enter the numbers for multiplication table (1-9): ";
		cin >> number;
		cout << endl;
		
		if (number > 1 && number < 10) // Bounds testing
		{
			for (i = 1; i <= number; i++)
			{
				for(j = 1; j <= number; j++)
				{
					row.push_back(i * j);
				}
				table.push_back(row);
				row.clear();
			}
			//Printing table 1, lines through line 61
			cout << "   |  ";
			for (i = 1; i < number + 1; i++)
			{
				cout << i << "  ";
			}
			cout << endl;
			
			cout << " - |  ";
			for (i = 1; i < number + 1; i++)
			{
				cout << "-  ";
			}
			cout << endl;
			
			for (i = 0; i < number; i++)
			{
				cout << " " << i + 1 << " |  ";
				for (j = 0; j < number; j++)
				{
					if (table[i].at(j) < 10)
					{
						cout << table[i].at(j) << "  ";
					}
					else
					{
						cout << table[i].at(j) << " ";
					}
				}
				cout << endl;
			}
			cout << endl;
			
			//Printing table 2, lines through line 94
			cout << "   |  ";
			for (i = number; i > 0; i--)
			{
				cout << i << "  ";
			}
			cout << endl;
			
			cout << " - |  ";
			for (i = number; i > 0; i--)
			{
				cout << "-  ";
			}
			cout << endl;
			
			for (i = number; i > 0; i--)
			{
				cout << " " << i << " |  ";
				for (j = number; j > 0; j--)
				{
					if (table[i - 1].at(j - 1) < 10)
					{
						cout << table[i - 1].at(j - 1) << "  ";
					}
					else
					{
						cout << table[i - 1].at(j - 1) << " ";
					}
				}
				cout << endl;
			}
			cout << endl;
			
			cout << "Do you want to do another? (y/n) ";
			cin >> more;
			cout << endl;
		}
		else if (number == 1)
		{
			cout << "   |  1" << endl << " - |  -" << endl << " 1 |  1" << endl << endl;
			cout << "   |  1" << endl << " - |  -" << endl << " 1 |  1" << endl << endl;
			
			cout << "Do you want to do another? (y/n) ";
			cin >> more;
			cout << endl;
			table.clear();
			row.clear();
		}
	}
	return 0;
}
