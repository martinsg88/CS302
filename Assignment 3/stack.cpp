#ifndef STACKTYPE_CPP
#define STACKTYPE_CPP
#include "node.h"
#include <iostream>

using namespace std;

class stacktype
{
	friend class nodetype;
	
	public:
		
		stacktype();
		void push(int,int);
		void pop(int&, int&);
		void makeEmpty();
		bool isEmpty();
		bool isFull();
		~stacktype();

	private:
		nodetype* top;
	
};
//------------------------------------------------------------------------------
stacktype::stacktype()
{
	top = NULL;
}
//------------------------------------------------------------------------------
void stacktype::push(int pushi, int pushj)
{
	nodetype* newnode;
	newnode = new nodetype;
	
	newnode->i = pushi;
	newnode->j = pushj;
	
	newnode->next = top;

	top = newnode;
}
//------------------------------------------------------------------------------
void stacktype::pop(int& popi, int& popj)
{
	nodetype* newnode;
	
	popi = top->i;
	popj = top->j;
	
	newnode = top;
	top = top->next;
	
	delete newnode;
}
//------------------------------------------------------------------------------
bool stacktype::isEmpty()
{
	return(top == NULL);
}
//------------------------------------------------------------------------------
bool stacktype::isFull()
{
	nodetype *location;
	
	location = new nodetype;
	
	if(location == NULL)
		return true;
	else
		delete location;
		return false;
}
//------------------------------------------------------------------------------
void stacktype::makeEmpty()
{
	nodetype* temp;
	
	while(top !=NULL)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}
//------------------------------------------------------------------------------
stacktype::~stacktype()
{
	makeEmpty();
}
#endif
