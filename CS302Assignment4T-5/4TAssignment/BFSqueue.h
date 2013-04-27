#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>
#include "BDFSNode/BDFSNode.h"

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
		BDFSNodeType* qFront;
		BDFSNodeType* qRear;
};
#endif
