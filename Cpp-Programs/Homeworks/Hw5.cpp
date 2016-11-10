#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int userIn = 0;

	cout << "Enter integers and enter a letter when done." << endl;
	// get input from user
	// cin >> userIn will evaluate to false to exit loop
	while (cin >> userIn) {
		v.push_back(userIn);
	}

	sort(v.begin(), v.end()); // Sort

							  // set min to first element in list since list is sorted
	int minVal = v.at(0);
	// set max to last element in list since list is sorted (note the -1)
	int maxVal = v.at(v.size() - 1);
	// since the loop starts looking at index 1, 
	//   initialize sum to the first element in list
	int sum = v.at(0);

	double median;
	// don't forget this is integer division
	if (v.size() % 2 == 0) { // even
		median = (v.at(v.size() / 2 - 1) + v.at(v.size() / 2)) / 2.0;
		//        ^index of first      ^index of second
	}
	else { // odd
		median = v.at(v.size() / 2);
	}
	
	int curMode = v.at(0);
	int curCount = 1;

	vector<int> mode(1);
	mode.at(0) = v.at(0);
	int modeCount = 1;
	int i;
	int j;


	for (j = 0, i = 1; i < v.size(); ++i) 
	{
		sum += v.at(i);
		if (curMode == v.at(i)) 
		{
			curCount++;
		}
		else 
		{
			if (curCount > modeCount) 
			{
				mode.clear();
				mode.push_back(curMode); 
				modeCount = curCount;
			}
			else if(curCount == modeCount)
			{
				j++;
				mode.push_back(curMode);
				modeCount = curCount;
			}
			curMode = v.at(i);
			curCount = 1;
		}
	}
	
	if (curCount > modeCount) 
	{
		mode.at(j) = curMode; 
		modeCount = curCount; 
	}
	else if (curCount == modeCount)
	{
		j++;
		mode.push_back(curMode);
		modeCount = curCount;	
	}
	

	// Output results
	cout << "Your numbers are: ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	cout << "Max: " << maxVal << endl;
	cout << "Min: " << minVal << endl;
	cout << "Average: " << (static_cast<double>(sum) / v.size()) << endl;
	cout << "Median: " << median << endl;
	cout << "Mode: ";
	for(i = 0; i < mode.size(); i++)
	{
		cout << mode.at(i) << " ";
	}
	cout << "(" << modeCount << ")" << endl;

	system("pause");
}      


