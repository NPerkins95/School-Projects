#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int i = 0;
	vector <int> squares(0);
	int grainsInput = 1;
	int grainsOrig = 1;
	int grainsMath = 1;
	
	cout << "Input number of grains of wheat: ";
	cin >> grainsInput;
	cout << endl;
	grainsOrig = grainsInput;
	
	squares.push_back(grainsMath);
	while(grainsInput >= 0)
	{	
		grainsInput = grainsInput - grainsMath;
		grainsMath = grainsMath * 2;
		squares.push_back(grainsMath);
		i++;
	}
	
	squares.pop_back();
	grainsMath = (grainsMath / 2) + grainsInput;
	
	if(grainsInput <= 0)
	{
		squares.pop_back();
	}

	cout << endl;
	cout << squares.size() + 1 << " squares for " << grainsOrig << " grains of wheat." << endl;
	sort(squares.begin(), squares.end());
	cout << "Which square would you like to see? ";
	cin >> i;
	
	if(i <= squares.size())
	{
		cout << squares.at((i - 1)) << " Grains at square " << i;
	}
	else if (i == squares.size() + 1)
	{
		if(grainsMath != 0)
		{
			cout << grainsMath << " Grains at square " << i;
		}
	}
}
