#include "UnsortedType.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType()	//Class constructor
{
	length = 0;
	listData = NULL;
}

UnsortedType::~UnsortedType()	 //Destructor
{
	MakeEmpty();
}

bool UnsortedType::IsFull() const
//Returns True if there is no room for another ItemType
//		on the free store; false otherwise.
{
	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch(std::bad_alloc exception)
	{
		return true;
	}
}

int UnsortedType::GetLength() const
//Post: Number of items in the list is returned.
{
	return length;
}

void UnsortedType::MakeEmpty()
//Post: List is empty; all items have been deallocated.
{
	NodeType* tempPtr;
	while(listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

void UnsortedType::PutItem(ItemType item)
//item is in the list; length has been incrememnted.
{
	NodeType* location;				//Declare a pointer to a node
	
	location = new NodeType;		//Get a new node
	location -> info = item;		//Store the item in the node
	location -> next = listData;	/*Store address of first node in
									   next field of new node*/
	listData = location;			/*Store address of new node into
									  external pointer*/
	length++; 						//increment length of the list
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
//Pre:	key member(s) of item is initialized.
/*Post:	If found, item's key matches an element's key in the
		list and a copy of that element has been returned;
		otherwise, item is returned.*/
{
	bool moreToSearch;
	NodeType* location;
	
	location = listData;
	found = false;
	
	moreToSearch = (location != NULL);
	
	while(moreToSearch && !found)
	{
		switch (item.ComparedTo(location -> info))
		{
			case LESS	:
			case GREATER:	location = location -> next;
							moreToSearch = (location != NULL);
							break;
			case EQUAL	:	found = true;
							item = location -> info;
							break;
		}
	}
	return item;
}

void UnsortedType::DeleteItem(ItemType item)
//Pre:	Item's key has been initialized.
//		An element in the list has a key that matches item's.
//Post:	No element in the list has a key that matches item's.
{
	NodeType* location = listData;
	NodeType* tempLocation;
	
	//Locate node to be deleted.
	if(item.ComparedTo(listData -> info) == EQUAL)
	{
		tempLocation = location;
		listData = listData -> next;
	}
	else
	{
		while(item.ComparedTo((location -> next) -> info) != EQUAL)
		{
			location = location -> next;
		}
		
		//Delete node at location -> next
		tempLocation = location -> next;
		location -> next = (location -> next) -> next;
	}
	delete tempLocation;
	length--;
}

void UnsortedType::ResetList()
//post:	Current position has been initialized
{
	currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
//Post:	A copy of the next item in the list is returned
//		When the end of the list is reached. currentPos
//		is reset to begin again.
{
	if (currentPos == NULL)
	{
		currentPos = listData;
	}
	else
	{
		currentPos = currentPos -> next;
	}
	return currentPos -> info;
}

void UnsortedType::SplitList(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2)
//Pre:	list has been initialized and is not empty
//post:	list1 contains all items of list whose keys are <= item's key
//		list2 contains all items of list whose keys are >= item's key
{
	ItemType location;
	list.ResetList();
	for (int i = 1, length = list.GetLength(); i <= length; i++)
	{
		location = list.GetNextItem();
		
		cout << "Parsing Item: ";
		location.Print();
		cout << endl;
		
		switch (location.ComparedTo(item))
		{
			case LESS	:
			case EQUAL	:	list1.PutItem(location);
							break;
			case GREATER:	list2.PutItem(location);
							break;
		};
	};
}
