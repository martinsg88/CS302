//TreeNode.cpp
#include <iostream>
#include <iomanip>

#include "TreeNode.h"

//------------------------------------------------------------------------------
TreeNode::TreeNode()
{
	cout << "TreeNode constructor called...\n";
}
//------------------------------------------------------------------------------
TreeNode::TreeNode(string UID, string  pWord)
{
	//cout << "\nNew TreeNode created... ";
	userID = UID;
	//cout << userID << " set ... n";
	passWord = pWord;
	//cout << pWord << " set ... ";
	left = NULL;
	//cout << "left set to " << left << "... ";
	right = NULL;
	//cout << "right set to " << right << "... ";
}
//------------------------------------------------------------------------------
TreeNode::~TreeNode()
{
	cout << " Deleting TreeNode...\n";
}
//------------------------------------------------------------------------------
