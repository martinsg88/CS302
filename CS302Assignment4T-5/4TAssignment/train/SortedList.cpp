

#ifndef NODETYPE_H
#define NODETYPE_H

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};
#endif
#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

template <class ItemType>
class SortedType{
	public:
	  SortedType();
	  ~SortedType();
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
	  NodeType<ItemType>* listData;
	  NodeType<ItemType>* currentPos;
};
#endif
#include <iostream>
using namespace std;

/*****************************************************************
CONSTRUCTOR
*****************************************************************/
template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData ='\0';

}
/*****************************************************************
DESTRUCTOR
*****************************************************************/
template <class ItemType>
SortedType<ItemType>::~SortedType()
{
  NodeType<ItemType>* tempPtr;
  
  while(listData !='\0')
  {
     tempPtr = listData;
     listData = listData->next;
     delete tempPtr;
  }
}
/*****************************************************************
MAKE EMPTY
*****************************************************************/
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{	 
  NodeType<ItemType>* tempPtr;
  
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
bool SortedType<ItemType>::IsFull()const
{
   return false;
}
/*****************************************************************
LENGTH
*****************************************************************/
template <class ItemType>
int SortedType<ItemType>::Lengthls()const
{
   return length;
}
/*****************************************************************
RETRIEVE ITEM
*****************************************************************/
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
   NodeType<ItemType>* location;
   
   location = listData;
   found = false;
   
   while((location !='\0')&& !found)
   {
      cout<<"Not found\n";
      if(location->info<item)
	location = location->next;
      else if(location->info == item)
      {
	cout<<"FOUND\n";
 	found = true;
	item = location->info;
      }
      else 
	location = '\0';
   }
}
/*****************************************************************
INSERT ITEM
*****************************************************************/
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType newItem)
{
   NodeType<ItemType>* newNode;
   NodeType<ItemType>* predLoc;
   NodeType<ItemType>* location;
   bool stop;
  
   stop = false;
   location = listData;
   predLoc = '\0';
  
   while(location != '\0' && !stop)
   {
      if(location->info < newItem)
      {
        predLoc = location;
	location = location->next;
      }
      else
	stop = true;
   }
   
   newNode = new NodeType<ItemType>;
   newNode->info = newItem;

   if(predLoc == '\0')
   {
      newNode->next = listData;
      listData = newNode;
   }
   else
   {
      newNode->next = location;
      predLoc->next = newNode;
   }
   length++;
}
/*****************************************************************
DELETE ITEM
*****************************************************************/
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
   NodeType<ItemType>* location=listData;
   NodeType<ItemType>* tempLocation;

   if(item ==listData->info)
   {
     tempLocation = listData;
     listData = listData->next;
   }   
   else 
   {
     while((item !=(location->next)->info))
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
void SortedType<ItemType>::ResetList()
{
   currentPos = listData;
}
/*****************************************************************
IS LAST ITEM
*****************************************************************/
template <class ItemType>
bool SortedType<ItemType>::IsLastItem()const
{
   return (listData->next = '\0');
}
/*****************************************************************
GET NEXT ITEM
*****************************************************************/
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
   item = currentPos->info;
   currentPos = currentPos->next;
}
