//TreeType.h
#ifndef TREETYPE_H
#define TREETYPE_H

#include <string>
#include <fstream>#include <iostream>

#include "QueType.h"
#include "TreeNode.h"

using namespace std;

//typedef char ItemType;
//enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType{protected:	TreeNode* root;//	QueType preQue;//	QueType inQue;//	QueType postQue;
public:	TreeType();											// constructor	TreeType(const TreeType& originalTree);	// copy constructor	void MakeEmpty();//	bool IsEmpty() const;	int  LengthIs() const;	void RetrieveItem(string& item, bool& found);	void InsertItem(string userID, string pWord);	void DeleteItem(string userID);	void PrintPre (std::ofstream& fout) const;	void Print	  (std::ofstream& fout) const;
	void PrintPost(std::ofstream& fout) const;
	~TreeType();										// destructor
//	bool IsFull() const;
//	void operator= (const TreeType& originalTree);
//	void ResetTree(OrderType order);//	void GetNextItem (ItemType& item, OrderType order, bool& finished);
//	void PreOrderTraversal(TreeNode*, QueType&);
//	void InOrderTraversal(TreeNode*, QueType&);
//	void PostOrderTraversal(TreeNode*, QueType&);};#endif
