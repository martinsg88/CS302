//HeapType.cpp
#include <iostream>
#include "HeapType.h"

using namespace std;

//------------------------------------------------------------------------------
void HeapType::ReheapUp(int root, int bottom)
{
	//cout << "\nHeaping up ... ";
	int parent;
  
	if(bottom > root)
	{
		parent = (bottom - 1) / 2;
		if(elements[parent] < elements[bottom])
		{
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
	//cout << "\n Done Heaping up ...\n";
}
//------------------------------------------------------------------------------
void HeapType::ReheapDown(int root, int bottom)
{
	//cout << "\nHeaping down ... ";
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2 + 1;
	rightChild = root*2 + 2;

	if(leftChild <= bottom)
	{
		if(leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if(elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		if(elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
	//cout << "\n Done Heaping down ...\n";
}
//------------------------------------------------------------------------------
void HeapType::Swap(int& itemOne, int& itemTwo)
{
	//cout << "\nSwapping items ...";
	int tempHeap;
	tempHeap = itemOne;
	itemOne = itemTwo;
	itemTwo = tempHeap;
	//cout << "\n Done Swapping ...\n";
}
