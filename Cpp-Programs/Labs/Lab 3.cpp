#include <iostream>
using namespace std;
int main() 
{
	int i = 0;
	cout << "Loop A (for version)" << endl;
	for (int i=0;i<5;i++) {
		cout << i << endl;
	}
	
	i = 0;
	cout << "Loop A (while version)" << endl;
	while (i < 5)
	{
		cout << i << endl;
		i++;
	}
	
    i = 0;
	cout << "Loop A (do while version)" << endl;
	do
	{
		cout << i << endl;
		i++;
	} while (i < 5);

	cout << "Loop B (do while version)" << endl;
	do {
		cout << "Enter a number less than 100 (Greater than or equal to 100 to exit):" << endl;
		cin >> i;
		cout << i << endl;
	} while (i<100);
	
	cout << "Loop B (for version)" << endl;
	for (i = 0; i < 100;)
	{
		cout << "Enter a number less than 100 (Greater than or equal to 100 to exit):" << endl;
		cin >> i;
		cout << i << endl;
	}
  	
  	i = 0;
	cout << "Loop B (while version)" << endl;
	while (i < 100)
	{
		cout << "Enter a number less than 100 (Greater than or equal to 100 to exit):" << endl;
		cin >> i;
		cout << i << endl;
	}

	cout << "Loop C (while version)" << endl;
    i = 20;
    while (i>10) {
		cout << i*2 << " ";
		i-=2;
    }
    cout << endl << endl;

	i = 20;
	cout << "Loop C (do while version)" << endl;
	do
	{
		cout << i*2 << " ";
		i -= 2;
	} while (i > 10);
	cout << endl << endl;

	cout << "Loop C (for version)" << endl;
	for(i = 20; i > 10; i -= 2)
	{
		cout << i*2 << " ";
	}
}
