#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
#include "Node/node.h"

using namespace std;

class queuetype
{
	public:
		queuetype();
		~queuetype();
		void enqueue(const int&,const int&);
		void dequeue(int&,int&);
		void dequeue();
		bool isFull();
		bool isEmpty();
		void makeEmpty();

	private:
		nodetype* qFront;
		nodetype* qRear;
};
#endif
