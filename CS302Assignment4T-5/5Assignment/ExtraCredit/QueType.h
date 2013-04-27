#ifndef QUETYPE_H
#define QUETYPE_H

#include <cstdlib>
#include "QueNode.h"

class FullQueue
{};  

class EmptyQueue
{};

typedef char ItemType;

class QueType
{
protected:

  QNode* front;
  QNode* rear;

public: 
	QueType();									// Default constructor
	QueType(int max);							// Parameterized class constructor.
	QueType(const QueType& anotherQue);	// Copy constructor
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	~QueType();									// Class destructor.
};
#endif
