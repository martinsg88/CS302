#include <iostream>
#include "UPQType.h"

using namespace std;

//Contstructor------------------------------------------------------------------
UPQType::UPQType(int max) : PQType(max)
{
		cout << "\nExecuting and departing Inherited Class Constructor...\n";
}//------------------------------------------------------------------------------
void UPQType::Remove(int item)
{
	cout << "\nAttempting to remove " << item << " from inherited class ... \n";
	bool found = false;
	int i = 0;

	while(!found && (i != numItems))
	{
		if(heapType.elements[i] == item)
		{
			found = true;
			heapType.elements[i] = heapType.elements[numItems - 1];
			numItems--;
			heapType.ReheapDown(i, numItems - 1);
		}
		i++;
	}

	if(!found)
		cout << item << " not found.\n";
	else
		cout << "\n " << item << " removed from inherited class ... \n";
}
//------------------------------------------------------------------------------
void UPQType::Update(int oldItem, int newItem)
{
	cout << "\nAttempting to update " << oldItem << " to " << newItem << " in";
	cout << " inherited class ... \n";
	bool found = false;
	int i = 0;

	while(!found && (i != numItems))
	{
		if(heapType.elements[i] == oldItem)
		{
			found = true;
			heapType.elements[i] = newItem;
			heapType.ReheapUp(0, i);
		}
		i++;
	}

	if(!found)
		cout << oldItem << " not found. Enter another item.\n";
	else
	{
		cout << "\n" << oldItem << " updated to " << newItem << " in inherited ";
		cout << "class ... \n";
	}
}
//Destructor--------------------------------------------------------------------UPQType::~UPQType(){
			cout << "\nExecuting and departing Inherited Class Destructor...\n";}
//------------------------------------------------------------------------------
