#ifndef HEAP_H
#define HEAP_H

//#include <cstdlib>

//struct HeapType
template<class ItemType>class HeapType
{
	public:

	ItemType* elements;	// Array to be allocated dynamically	int numElements;
	void ReheapUp(int root, int bottom);
	void ReheapDown(int root, int bottom);
	void Swap(ItemType& itemOne, ItemType& itemTwo);
};
//#include "Heap.cpp"
//------------------------------------------------------------------------------
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;
  
  if (bottom > root)
  {
    parent = (bottom - 1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);
      ReheapUp(root, parent);
    }
  }
}
//------------------------------------------------------------------------------
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(maxChild, bottom);
    }
  }
}
//------------------------------------------------------------------------------
template <class ItemType>
void Swap(ItemType& itemOne, ItemType& itemTwo)
{
  ItemType tempItem;
  tempItem = itemOne;
  itemOne = itemTwo;
  itemTwo = tempItem;
}
#endif
