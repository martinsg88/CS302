//UPQType.h
#ifndef UPQTYPE_H
#define UPQTYPE_H

#include "PQType.h"
#include "HeapType.h"
class UPQType : public PQType{	public:	UPQType(int);          // parameterized class constructor
	void Remove(int);
	void Update(int, int);	~UPQType();            // class destructor};
#endif
