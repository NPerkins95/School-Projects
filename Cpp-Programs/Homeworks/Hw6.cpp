#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int input, i, j, seed;
	vector<int> userNum;
	vector<int> compNum;
	vector<int> userSplit(4);
	vector<int> compSplit(4);
	int k = 0;
	int cow = 0;
	int bull = 0;
	int test = 0;
	
	cout << "Enter a random number (favorite numbers discouraged)" << endl;
	cin >> seed;
	srand(seed);
	
	do
	{
		cow = 0;
		bull = 0;
		
		do 														// Test whether the users input is valid
		{
			test = 0;
			cout << "Enter a positive four digit number with no repeated values." << endl;
			cin >> input;
			userNum.push_back(input);
			
			userSplit.at(0) = userNum.at(k) / 1000 % 10;
			userSplit.at(1) = userNum.at(k) / 100 % 10;
			userSplit.at(2) = userNum.at(k) / 10 % 10;
			userSplit.at(3) = userNum.at(k) % 10;
			
			for(i = 0; i < 3; i++)
			{
				for(j = i + 1; j < 4; j++)
				{
					if(userSplit.at(i) == userSplit.at(j))
					{
						test += 1;
						userNum.clear();
					}
				}
			}
		} while(test > 0);
		
		if(k == 0)
		{
			do 													// Test whether the random input is valid
			{
				test = 0;
				input = rand() % (9999 - 1000) + 1000;
				compNum.push_back(input);
				
				compSplit.at(0) = compNum.at(k) / 1000 % 10;
				compSplit.at(1) = compNum.at(k) / 100 % 10;
				compSplit.at(2) = compNum.at(k) / 10 % 10;
				compSplit.at(3) = compNum.at(k) % 10;
	
				for(i = 0; i < 3; i++)
				{
					for(j = i + 1; j < 4; j++)
					{
						if(compSplit.at(i) == compSplit.at(j))
						{
							test += 1;
							compNum.clear();
						}
					}
				}
			} while(test > 0);
		}
		
		for(i = 0; i < 4; i++) 								// test for cows
		{
			for(j = 0; j < 4; j++)
			{
				if(userSplit.at(i) == compSplit.at(j))
				{
					cow += 1;
				}
			}
		}
		
		for(i = 0; i < 4; i++) 								// test for bulls
		{
			if(userSplit.at(i) == compSplit.at(i))
			{
				bull += 1;
				cow -= 1;
			}
		}
		
		cout << bull << " Bulls, and " << cow << " Cows." << endl;
		k++;
	} while(bull != 4);
}
