//HeapType.h
#ifndef HEAPTYPE_H
#define HEAPTYPE_H

{
	public:

	int* elements;	// Array to be allocated dynamically
	void ReheapUp(int root, int bottom);
	void ReheapDown(int root, int bottom);
	void Swap(int& itemOne, int& itemTwo);
};
#endif