#ifndef PQTYPE_H
#define PQTYPE_H

#include "HeapType.h"

class PQType	{
		protected:		int numItems;		HeapType heapType;		int maxItems;
		public:		PQType(int);			// parameterized constructor    
		void Enqueue(int);		void Dequeue(int&);		bool IsEmpty() const;		bool IsFull() const;		void MakeEmpty();
		void Print();
		void Copy(PQType&);
		virtual ~PQType();	// class destructor	};
#endif
