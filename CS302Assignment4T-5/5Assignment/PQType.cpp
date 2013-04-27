#include <iostream>

using namespace std;

#include "PQType.h"

//Parameterized Constructor-----------------------------------------------------PQType::PQType(int max){
	cout << "\nExecuting Base Class Constructor... ";
	maxItems = max;	heapType.elements = new int[max];	numItems = 0;

	cout << "\n Departing Base Class Constructor... \n";}
//------------------------------------------------------------------------------void PQType::Enqueue(int newHeapItem){
	//cout << "\nEnqueing " << newHeapItem << " in the base class ... ";
	if (numItems != maxItems)	{		numItems++;		heapType.elements[numItems-1] = newHeapItem;		heapType.ReheapUp(0, numItems-1);
		cout << "\n " << newHeapItem << " enqueued in the base class ... ";
		cout << "\n Number of items is " << numItems << " .\n";	}
	else
		cout << "\nItem not enqueued. Queue is full.\n";}//------------------------------------------------------------------------------void PQType::Dequeue(int& heapItem){	//cout << "\nDequeing in the base class ... ";
	if(numItems == 0)
		cout << "\n" << heapItem << " not dequeued; Queue is empty.\n";
	else	{		heapItem = heapType.elements[0];		heapType.elements[0] = heapType.elements[numItems - 1];		numItems--;		heapType.ReheapDown(0, numItems - 1);
		cout << "\n " << heapItem << " dequeued in the base class ... ";	}}
//------------------------------------------------------------------------------bool PQType::IsFull() const{  return numItems == maxItems;}//------------------------------------------------------------------------------bool PQType::IsEmpty() const{  return numItems == 0;}
//------------------------------------------------------------------------------void PQType::MakeEmpty(){  numItems = 0;}
//------------------------------------------------------------------------------void PQType::Print()
{
	PQType copyQ(maxItems);
	Copy(copyQ);
	int item;

	if(numItems == 0)
		cout << "\nNo items to display; Queue is empty.\n";

	else
	{
		for(int i = 0; i < numItems - 1; i++)
		{
			copyQ.Dequeue(item);
			cout << item << "  ";
		}
	}
}
//------------------------------------------------------------------------------
void PQType::Copy(PQType& copyQ)
{
	copyQ.maxItems = maxItems;
	copyQ.numItems = numItems;
	copyQ.heapType.elements = new int[maxItems];
	
	for(int i = 0; i < numItems; i++)
	{
		copyQ.heapType.elements[i] = heapType.elements[i];
	}
}
//Destructor--------------------------------------------------------------------PQType::~PQType(){
	cout << "\nExecuting Base Class Destructor... ";	delete [] heapType.elements;
	cout << "\n Departing Base Class Destructor... \n";}
//------------------------------------------------------------------------------
