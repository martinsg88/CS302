//stack.cpp

using namespace std;

#include "DFSstack.h"
//------------------------------------------------------------------------------
stacktype::stacktype()
{
	top = NULL;
}
//------------------------------------------------------------------------------
void stacktype::push(int pushi, int pushj)
{
	BDFSNodeType* newnode;
	newnode = new BDFSNodeType;
	
	newnode->i = pushi;
	newnode->j = pushj;
	
	newnode->next = top;

	top = newnode;
}
//------------------------------------------------------------------------------
void stacktype::pop(int& popi, int& popj)
{
	BDFSNodeType* newnode;
	
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
	BDFSNodeType *location;
	
	location = new BDFSNodeType;
	
	if(location == NULL)
		return true;
	else
		delete location;
		return false;
}
//------------------------------------------------------------------------------
void stacktype::makeEmpty()
{
	BDFSNodeType* temp;
	
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
