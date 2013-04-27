#ifndef NODETYPE_H
#define NODETYPE_H
#include <iostream>

//using namespace std;

class nodetype
{

	public:
		nodetype() {i = 0; j = 0; next = NULL; }
		int i;
		int j;
		nodetype *next;
};

#endif
