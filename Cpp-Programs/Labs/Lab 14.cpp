#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string wd) {
	if (wd.length() == 1) { // first base case
		return true;
	}
	else if (wd.length() == 2) { // second base case
		return tolower(wd.at(0)) == tolower(wd.at(1));
	}
	else { // compare first and last letters and recurse if they are the same
  
    return (tolower(wd.at(0)) == tolower(wd.at(wd.length() - 1))) 
              && isPalindrome(wd.substr(1, wd.length() - 2));
	}
}

int main(int argc, char *argv[]) 
{
	string str = argv[1];
	cout << endl;
	
	if (isPalindrome(str)) 
	{
		cout << "\"" << str << "\" is a palindrome." << endl;
	}
	else 
	{
		cout << "\"" << str << "\" is NOT a palindrome." << endl;
	}
	cout << endl;
}   
