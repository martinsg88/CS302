//TreeNode.h
#ifndef TREENODE_H
#define TREENODE_H

#include <string>
//#include <cstring>

using namespace std;

class TreeNode
{
	public:
	char info;
	string userID;
	string passWord;
	TreeNode* left;
	TreeNode* right;

	public:
	TreeNode();
	TreeNode(string, string);
	~TreeNode();
};
#endif
