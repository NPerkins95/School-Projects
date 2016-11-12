#include <iostream>
#include <fstream>
#include <string>

#include "UnsortedType.h"
using namespace std;

void PrintList(UnsortedType&);

//Test Cases
int main()
{
	ifstream inFile;
	string command;
	
	int number;
	ItemType item;
	UnsortedType list;
	bool found;
	int numCommands;
	
	inFile.open("hw1.txt");
	if (!inFile)
	{
		cout << "Error openning input file." << endl;
		exit(1);
	}
	
	inFile >> command;
	numCommands = 0;
	while (command!= "Quit")
	{
		numCommands++;
		cout << "Command " << numCommands << ": " << command << "	";
		
		if (command == "PutItem")
		{
			inFile >> number;
			item.Initialize(number);
			list.PutItem(item);
			item.Print();
			cout << " was added to list" << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "GetItem")
		{
			inFile >> number;
			item.Initialize(number);
			item = list.GetItem(item, found);
			item.Print();
			if (found)
			{
				cout << " was found in the list." << endl;
			}
			else
			{
				cout << " was not in the list." << endl;
			}
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "DeleteItem")
		{
			inFile >> number;
			item.Initialize(number);
			list.DeleteItem(item);
			item.Print();
			cout << " was deleted from the list" << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "GetLength")
		{
			cout << "Length of list = " << list.GetLength() << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "IsFull")
		{
			if (list.IsFull())
			{
				cout << "The list is full." << endl;
			}
			else
			{
				cout << "The list is not full." << endl;
			}
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "MakeEmpty")
		{
			list.MakeEmpty();
			cout << "The list is now Empty." << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "ResetList")
		{
			list.ResetList();
			cout << "The list is now Reset." << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "PrintList")
		{
			cout << "\n\nList Values:" << endl;
			PrintList(list);
			cout << "-------------------------------------------------------" << endl;
		}
		else if (command == "SplitList")
		{
			cout << endl;
			UnsortedType list1, list2;
			inFile >> number;
			item.Initialize(number);
			list.SplitList(list, item, list1, list2);
			cout << "List1:" << endl;
			PrintList(list1);
			cout << "List2:" << endl;
			PrintList(list2);
			cout << "-------------------------------------------------------" << endl;
		}
		else
		{
			cout << "\"" << command << "\"" << " is not a valid command." << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		
		inFile >> command;
	};
	
	cout << "Testing Completed." << endl;
	inFile.close();
	return 0;
}

void PrintList(UnsortedType& list)
//Pre:	list initialized.
//Post:	Each component in list written.
{
	int length;
	ItemType item;
	
	list.ResetList();
	length = list.GetLength();
	for(int i = 1; i <= length; i++)
	{
		item = list.GetNextItem();
		item.Print();
		cout << endl;
	}
	cout << "Length of list = " << length << endl << endl;
}
