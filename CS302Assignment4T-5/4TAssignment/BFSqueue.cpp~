//queue.cpp

#include "BFSqueue.h"

//------------------------------------------------------------------------------
queuetype::queuetype()
{
	qFront = NULL;
	qRear  = NULL;
}
//------------------------------------------------------------------------------
void queuetype::enqueue(const int& enqi,const int& enqj)
{
	nodetype* newnode;
	newnode = new nodetype;
	newnode->i = enqi;
	newnode->j = enqj;
	newnode->next = NULL;

	if(qRear == NULL)
	{
		qFront = newnode;
	}
	else
		qRear->next = newnode;
	
	qRear = newnode;
}
//------------------------------------------------------------------------------
void queuetype::dequeue(int& deqi, int& deqj)
{
	nodetype* temp;

	temp = qFront;
	deqi = qFront->i;
	deqj = qFront->j;
	qFront = qFront->next;
	if(qFront == NULL)
	{
		qRear = NULL;
	}
	delete temp;
}
//------------------------------------------------------------------------------
void queuetype::makeEmpty()
{
	nodetype* temp;

	while(qFront !=NULL)
	{
		temp = qFront;
		qFront = qFront->next;
		delete temp;
	}

	qRear = NULL;
}
//------------------------------------------------------------------------------
bool queuetype::isEmpty()
{
	return(qFront==NULL);
}
//------------------------------------------------------------------------------
bool queuetype::isFull()
{
	nodetype* temp;
	temp = new nodetype;
	if(temp == NULL)
	{
		return true;
	}
	else
	{
		delete temp;
		return false;
	}
}
//------------------------------------------------------------------------------
void queuetype::dequeue()
{
	nodetype* temp;

	temp = qFront;
	//deqi = qFront->i;
	//deqj = qFront->j;
	qFront = qFront->next;
	if(qFront == NULL)
	{
		qRear = NULL;
	}
	delete temp;
}
//------------------------------------------------------------------------------
queuetype::~queuetype()
{
	makeEmpty();
}
