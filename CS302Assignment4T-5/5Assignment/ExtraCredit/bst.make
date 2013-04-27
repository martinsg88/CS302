bst.bin: BSTmain.o TreeType.o TreeNode.o QueType.o
	g++ -o bst.bin BSTmain.o TreeType.o TreeNode.o QueType.o

BSTmain.o: BSTmain.cpp TreeType.h
	g++ -c BSTmain.cpp

TreeType.o: TreeType.h TreeType.cpp TreeNode.h QueType.h
	g++ -c TreeType.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -c TreeNode.cpp

QueType.o: QueType.h QueType.cpp QueNode.h
	g++ -c QueType.cpp
