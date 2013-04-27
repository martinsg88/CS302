
#ifndef NODETYPE2_H
#define NODETYPE2_H

template <class ItemType>
struct NodeType2
{
  ItemType info;
  NodeType2* next;
};
#endif

#ifndef UNSORTEDTYPE_CPP
#define UNSORTEDTYPE_CPP
template <class ItemType>
class UnsortedType{
	public:
	  UnsortedType();
	  ~UnsortedType();
	  void MakeEmpty();
	  bool IsFull()const;
	  int Lengthls()const;
	  void RetrieveItem(ItemType&, bool&);
	  void InsertItem(ItemType);
	  void DeleteItem(ItemType);
	  void ResetList();
	  bool IsLastItem()const;
	  void GetNextItem(ItemType&);
	private:
	  int length;
	  NodeType2<ItemType>* listData;
	  NodeType2<ItemType>* currentPos;
};
#endif
#ifndef UNSORTEDLIST_CPP
#define UNSORTEDLIST_H
#include <iostream>
using namespace std;

/*****************************************************************
CONSTRUCTOR
*****************************************************************/
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData ='\0';

}
/*****************************************************************
DESTRUCTOR
*****************************************************************/
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
  MakeEmpty();
}
/*****************************************************************
MAKE EMPTY
*****************************************************************/
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{	 
  NodeType2<ItemType>* tempPtr;
  
  while(listData != '\0')
  {
     tempPtr = listData;
     listData = listData->next;
     delete tempPtr;
  }
}
/*****************************************************************
IS FULL
*****************************************************************/
template <class ItemType>
bool UnsortedType<ItemType>::IsFull()const
{
   return false;
}
/*****************************************************************
LENGTH
*****************************************************************/
template <class ItemType>
int UnsortedType<ItemType>::Lengthls()const
{
   return length;
}
/*****************************************************************
RETRIEVE ITEM
*****************************************************************/
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
   NodeType2<ItemType>* location;
   
   location = listData;
   found = false;
   
   while((location !='\0')&& !found)
   {
      cout<<"Not Found\n";
      if(item == location->info)
      {
        cout<<"FOUND\n";
	found = true;
 	item = location->info;
      }
      else 
	location = location->next;
   }
}
/*****************************************************************
INSERT ITEM
*****************************************************************/
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType newItem)
{
   NodeType2<ItemType>* location;

   location = new NodeType2<ItemType>;
   location->info = newItem;
   location->next = listData;
   listData = location;
   length++;
}
/*****************************************************************
DELETE ITEM
*****************************************************************/
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
   NodeType2<ItemType>* location=listData;
   NodeType2<ItemType>* tempLocation;

   if(item ==listData->info)
   {
     tempLocation = listData;
     listData = listData->next;
   }   
   else 
   {
     while(!(item =(location->next)->info))
	location = location->next;

     tempLocation = location->next;	
     location->next = tempLocation->next;
   }
   delete tempLocation;
   length--;
}
/*****************************************************************
RESET LIST
*****************************************************************/
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
   currentPos = listData;
}
/*****************************************************************
IS LAST ITEM
*****************************************************************/
template <class ItemType>
bool UnsortedType<ItemType>::IsLastItem()const
{
   return (currentPos = '\0');
}
/*****************************************************************
GET NEXT ITEM
*****************************************************************/
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
{
   item = currentPos->info;
   currentPos = currentPos->next;
}

#endif
