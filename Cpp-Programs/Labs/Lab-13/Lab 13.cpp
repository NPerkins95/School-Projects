#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	vector<int> v;
	int userIn = 0;

	//cout << "Enter integers and enter a letter when done." << endl;
	
	ifstream myInput;
	myInput.open("input.txt");
	if (!myInput.is_open())
	{
		cout << "Could not open file input.txt." << endl;
		return 1;
	}
	else
	{
		while (!myInput.eof())
		{
			myInput >> userIn;
			v.push_back(userIn);
		}
	}
	myInput.close();
	
	/*while (cin >> userIn) {
		v.push_back(userIn);
	}*/

	sort(v.begin(), v.end());

	int minVal = v.at(0);
	int maxVal = v.at(v.size() - 1);
	int sum = v.at(0);
	double median;
	
	if (v.size() % 2 == 0) 
	{
		median = (v.at(v.size() / 2 - 1) + v.at(v.size() / 2)) / 2.0;
	}
	else 
	{
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

	ofstream myOutput;
	myOutput.open("output.txt");
	if (!myOutput.is_open())
	{
		cout << "Could not open file output.txt." << endl;
		return 1;
	}
	else
	{
		myOutput << "Your numbers are:" << endl;
		for (i = 0; i < v.size(); i++)
		{
			myOutput << v.at(i) << " ";
		}
		myOutput << endl;
		myOutput << "Max: " << maxVal << endl;
		myOutput << "Min: " << minVal << endl;
		myOutput << "Average: " << (static_cast<double>(sum) / v.size()) << endl;
		myOutput << "Median: " << median << endl;
		myOutput << "Mode: ";
		for(i = 0; i < mode.size(); i++)
		{
			myOutput << mode.at(i) << " ";
		}
		myOutput << "(" << modeCount << ")" << endl;
	}
	myOutput.close();
	
	// Output results
	/*cout << "Your numbers are: ";
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
	cout << "(" << modeCount << ")" << endl;*/
	system("pause");
}      


