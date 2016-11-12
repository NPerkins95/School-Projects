#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <string>
#include <iostream>
using namespace std;

const int MAX_ITEM = 25;
enum RelationType 
{
	LESS, EQUAL, GREATER
};

class ItemType
{
	public:
		ItemType();
		RelationType ComparedTo(ItemType) const;
		void Print() const;
		void Initialize(int number);		
	private:
		int value;
};

#endif
