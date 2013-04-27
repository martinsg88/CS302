//TreeType.h
#ifndef TREETYPE_H
#define TREETYPE_H

#include <string>
#include <fstream>

#include "QueType.h"
#include "TreeNode.h"

using namespace std;

//typedef char ItemType;
//enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
public:
	void PrintPost(std::ofstream& fout) const;
	~TreeType();										// destructor
//	bool IsFull() const;
//	void operator= (const TreeType& originalTree);
//	void ResetTree(OrderType order);
//	void PreOrderTraversal(TreeNode*, QueType&);
//	void InOrderTraversal(TreeNode*, QueType&);
//	void PostOrderTraversal(TreeNode*, QueType&);