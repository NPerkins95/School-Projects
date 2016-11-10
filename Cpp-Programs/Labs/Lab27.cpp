#include <iostream>
#include <vector>
#include <string>
using namespace std;

void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(vector<int>& v) { // bubble sort

	for (int i = 1; i < (v.size()); ++i) {
		for (int j = 0; j < (v.size() - i); ++j) {
			if (v.at(j+1) < v.at(j)) { // swap
				mySwap(v.at(j + 1), v.at(j));
			}
		}
	}
}

void print(vector<int> v, string label = "") {
	if (!label.empty()) {
		cout << label << endl;
	}

	if (v.size() == 0) {
		cout << "Empty List" << endl;
	}
	else {
		for (int i = 0; i < v.size(); ++i) {
			cout << v.at(i) << " ";
		}
		cout << endl;
	}
}

int main() {

	vector<int> vInt { 7, 3, 2, 9, 5 };
	vector<double> vDouble { 2.3, 9.5, 4.2, 8.7 };
	vector<string> vString { "happy","sad","_sad", "don't", "care" };

	// Integers
	print(vInt, "Unsorted Integers: ");

	cout << "Sorting Integers... " << endl;
	sort(vInt);

	print(vInt, "Sorted Integers: ");
	cout << endl;

  /*
	// Doubles
	print(vDouble, "Unsorted Doubles: ");

	cout << "Sorting Doubles... " << endl;
	sort(vDouble);

	print(vDouble, "Sorted Doubles: ");
	cout << endl;

	// Strings
	print(vString, "Unsorted Strings: ");

	cout << "Sorting Strings... " << endl;
	sort(vString);

	print(vString, "Sorted Strings: ");
  */
}      


