#ifndef BDFSNODETYPE_H
#define BDFSNODETYPE_H
#include <iostream>

//using namespace std;

class BDFSNodeType
{

	public:
		BDFSNodeType() {i = 0; j = 0; next = NULL; }
		int i;
		int j;
		BDFSNodeType *next;
};

#endif
