#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

class UnsortedType
{
	private:
		struct NodeType
		{
			ItemType info;
			NodeType* next;
		};
		
		NodeType* listData;
		int length;
		NodeType* currentPos;
		
	public:
		UnsortedType();
		~UnsortedType();
		void MakeEmpty();
		bool IsFull() const;
		int GetLength() const;
		ItemType GetItem(ItemType item, bool& found);
		void PutItem(ItemType item);
		void DeleteItem(ItemType item);
		void ResetList();
		ItemType GetNextItem();
		void SplitList(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2);
};

#endif
