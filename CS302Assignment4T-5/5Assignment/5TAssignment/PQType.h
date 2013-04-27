#ifndef PQTYPE_H
#define PQTYPE_H

#include "Heap.h"
class FullPQ{};class EmptyPQ{};

template<class ItemType>class PQType	{
		protected:		int length;		HeapType<ItemType> items;		int maxItems;
		public:		PQType(int);          // parameterized class constructor		~PQType();            // class destructor    
		void Enqueue(ItemType newItem);		void Dequeue(ItemType& item);		bool IsEmpty() const;		bool IsFull() const;		void MakeEmpty();};
//#include "PQType.h"//Constructor-------------------------------------------------------------------template<class ItemType>PQType<ItemType>::PQType(int max){  maxItems = max;  items.elements = new ItemType[max];  length = 0;}
//------------------------------------------------------------------------------template<class ItemType>void PQType<ItemType>::Enqueue(ItemType newItem)// Post: newItem is in the queue.{  if (length == maxItems)    throw FullPQ();  else  {    length++;    items.elements[length-1] = newItem;    items.ReheapUp(0, length-1);  }}//------------------------------------------------------------------------------template<class ItemType>void PQType<ItemType>::Dequeue(ItemType& item)// Post: element with highest priority has been removed from the queue;
// a copy is returned in item.{  if (length == 0)    throw EmptyPQ();  else  {    item = items.elements[0];    items.elements[0] = items.elements[length-1];    length--;    items.ReheapDown(0, length-1);  }}
//------------------------------------------------------------------------------template<class ItemType>bool PQType<ItemType>::IsFull() const// Post: Returns true if the queue is full; false, otherwise.{  return length == maxItems;}//------------------------------------------------------------------------------template<class ItemType>bool PQType<ItemType>::IsEmpty() const// Post: Returns true if the queue is empty; false, otherwise.{  return length == 0;}
//------------------------------------------------------------------------------template<class ItemType>void PQType<ItemType>::MakeEmpty(){  length = 0;}
//Destructor--------------------------------------------------------------------
template<class ItemType>PQType<ItemType>::~PQType(){  delete [] items.elements;}
//------------------------------------------------------------------------------
#endif
