#include <iostream>

using namespace std;

#include "PQType.h"

//Parameterized Constructor-----------------------------------------------------
	cout << "\nExecuting Base Class Constructor... ";
	maxItems = max;

	cout << "\n Departing Base Class Constructor... \n";
//------------------------------------------------------------------------------
	//cout << "\nEnqueing " << newHeapItem << " in the base class ... ";

		cout << "\n " << newHeapItem << " enqueued in the base class ... ";
		cout << "\n Number of items is " << numItems << " .\n";
	else
		cout << "\nItem not enqueued. Queue is full.\n";
	if(numItems == 0)
		cout << "\n" << heapItem << " not dequeued; Queue is empty.\n";
	else
		cout << "\n " << heapItem << " dequeued in the base class ... ";
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
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
//Destructor--------------------------------------------------------------------
	cout << "\nExecuting Base Class Destructor... ";
	cout << "\n Departing Base Class Destructor... \n";
//------------------------------------------------------------------------------