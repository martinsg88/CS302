#ifndef NODETYPE_H
#define NODETYPE_H
#include <iostream>

//using namespace std;

class nodetype
{
	friend class stacktype;
	friend class queuetype;
	
	public:
		nodetype() {i = 0; j = 0; next = NULL; }
		int i;
		int j;
		nodetype *next;
};

#endif
