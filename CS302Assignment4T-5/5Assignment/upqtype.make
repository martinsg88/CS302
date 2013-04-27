upqtype.bin: UPQmain.o PQType.o UPQType.o HeapType.o
	g++ -o upqtype.bin UPQmain.o PQType.o UPQType.o HeapType.o

UPQmain.o: UPQmain.cpp UPQType.h
	g++ -c UPQmain.cpp

UPQType.o: UPQType.h UPQType.cpp PQType.h
	g++ -c UPQType.cpp

PQType.o: PQType.h PQType.cpp HeapType.h
	g++ -c PQType.cpp

HeapType.o: HeapType.h HeapType.cpp
	g++ -c HeapType.cpp
