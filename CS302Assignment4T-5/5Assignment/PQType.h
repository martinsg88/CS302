#ifndef PQTYPE_H
#define PQTYPE_H

#include "HeapType.h"

class PQType
		protected:

		void Enqueue(int);
		void Print();
		void Copy(PQType&);
		virtual ~PQType();	// class destructor
#endif