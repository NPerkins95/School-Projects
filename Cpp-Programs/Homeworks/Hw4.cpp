#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int min, max, numGen, seed, random, i, j;
	//vector<int> recur;
	vector<int> counts;
	char more = 'y';
	
	while(more == 'y' || more == 'Y')
	{
		cout << "Enter the Minimum Value: ";
		cin >> min;
		
		cout << "Enter the Maximum Value: ";
		cin >> max;
		
		cout << "Enter the number of random numbers to generate: ";
		cin >> numGen;
		
		cout << "Enter the random seed: ";
		cin >> seed;
		cout << endl;
		
		vector<int> recur(max - min + 1);
		
		srand(seed);
		cout << "First 10: ";
		for (i = 0; i < numGen; i++)
		{
			random = rand() % (max - min + 1) + min;
			if (i < 10)
			{
				cout << random << " ";
			}
			
			if (i == 10)
			{
				cout << endl << endl;
			}
			
			counts.push_back(random);
		}
		
		sort(counts.begin(), counts.end());
		for(j = 0, i = 0; i < counts.size(); i++)
		{
			if(i == counts.size() - 1)
			{
			}
			else if(counts.at(i) == counts.at(i + 1))
			{
				recur.at(j) += 1;
			}
			else
			{
				j++;
			}
		}
		
		cout << "Counts:" << endl;
		for(j = 0, i = min; i < max + 1; i++, j++)
		{
			cout << i << ": " << recur.at(j) + 1 << endl;
		}
		
		
		cout << endl << "Do you want to run another set of tests? Enter 'y' or 'n'" << endl;
		cin >> more;
		counts.clear();
		recur.clear();
	}
	return 0;
}
