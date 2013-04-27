#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP
#include "BDFSNode/BDFSNode.h"
#include <iostream>

using namespace std;

class stacktype
{
	private:
		BDFSNodeType* top;
	
	public:
		
		stacktype();
		void push(int,int);
		void pop(int&, int&);
		void makeEmpty();
		bool isEmpty();
		bool isFull();
		~stacktype();	
};
#endif
