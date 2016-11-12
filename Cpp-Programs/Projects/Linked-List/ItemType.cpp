#include <iostream>
#include <string>
#include "ItemType.h"
using namespace std;

ItemType::ItemType()	//ItemType default constructor
{
	value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
	if (value < otherItem.value)
	{
		return LESS;
	}
	else if (value > otherItem.value)
	{
		return GREATER;
	}
	else
	{
		return EQUAL;
	}
}

void ItemType::Initialize(int number)
{
	value = number;
}

void ItemType::Print() const
//pre:	File has been opened
//post: value sent to cout
{
	cout << value;
}
