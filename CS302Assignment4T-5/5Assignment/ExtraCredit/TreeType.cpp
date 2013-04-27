//TreeType.cpp
#include <iomanip>
#include <fstream>

#include "TreeType.h"

//prototypes
int  CountNodes(TreeNode* tree);
void Retrieve(TreeNode* tree, string& item, bool& found);
void Delete(TreeNode*& tree, string item);
void GetPredecessor(TreeNode* tree, string& data);
void CopyTree(TreeNode*& copy, const TreeNode* originalTree);
void Destroy(TreeNode*& tree);

//Constructor-------------------------------------------------------------------
TreeType::TreeType()
{
  root = NULL;
}
//Copy Constructor--------------------------------------------------------------
TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree into root.
{
  CopyTree(root, originalTree.root);
}
	//---------------------------------------------------------------------------
	void CopyTree(TreeNode*& copy, const TreeNode* originalTree)
	// Post: copy is the root of a tree that is a duplicate of originalTree.
	{
		if (originalTree == NULL)
			copy = NULL;
		else
		{
			copy = new TreeNode;
			copy->userID = originalTree->userID;
			copy->passWord = originalTree->passWord;
			CopyTree(copy->left, originalTree->left);
			CopyTree(copy->right, originalTree->right);
		}
}
//------------------------------------------------------------------------------
/*bool TreeType::IsFull() const
{
  TreeNode* location;
//  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
//  catch(std::bad_alloc exception)
  {
    return true;
  }
}
//------------------------------------------------------------------------------
bool TreeType::IsEmpty() const
{
  return root == NULL;
}
//------------------------------------------------------------------------------
int TreeType::LengthIs() const
// Calls recursive function CountNodes to count the nodes in the tree.
{
	return CountNodes(root);
}
	//---------------------------------------------------------------------------
	int CountNodes(TreeNode* tree)
	// Post: returns the number of nodes in the tree.
	{
		if (tree == NULL)
			return 0;
		else 
			return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}*/
//------------------------------------------------------------------------------
void TreeType::RetrieveItem(string& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
	Retrieve(root, item, found);
}
	//---------------------------------------------------------------------------
	void Retrieve(TreeNode* tree, string& item, bool& found)
	{
		if (tree == NULL)
			found = false;                     // item is not found.
		else if (item < tree->userID)      
			Retrieve(tree->left, item, found); // Search left subtree.
		else if (item > tree->userID)
			Retrieve(tree->right, item, found);// Search right subtree.
		else
		{
			item = tree->userID;                 // item is found.
			cout << item << " found...\n";
			found = true;
		}
}
//------------------------------------------------------------------------------
bool FindNode(TreeNode* tree, string userID, TreeNode*& nodePtr,
																			TreeNode*& parentPtr)
{
  nodePtr = tree;
  parentPtr = NULL;
  bool found = false;

  while (nodePtr != NULL && !found)
  {
	//if (userID.compare(nodePtr->userID) < 0)
	if (userID < (nodePtr->userID))
    {
      parentPtr = nodePtr;
      nodePtr = nodePtr->left;
    }
    //else if (userID.compare(nodePtr->userID) > 0)
	else if (userID > (nodePtr->userID))
    {
      parentPtr = nodePtr;
      nodePtr = nodePtr->right;
    }
    else
      found = true;
  }
  return found;	
}
//------------------------------------------------------------------------------
void TreeType::InsertItem(string userID, string passWord)
{
	TreeNode* newNode = new TreeNode(userID, passWord);
	TreeNode* nodePtr;
	TreeNode* parentPtr;
	bool found;

	newNode->userID = userID;
	newNode->passWord = passWord;

	found = FindNode(root, userID, nodePtr, parentPtr);

	if(!found)
	{
		if (parentPtr == NULL)		// Insert as root.
			root = newNode;			//else if (userID.compare(parentPtr->userID) < 0)
		else if (userID < (parentPtr->userID))
		{
			cout << "In the left node... ";
			parentPtr->left = newNode;
		}
		else
		{
			parentPtr->right = newNode;
			cout << "In the right node... ";
		}
	}
	else
		cout << userID << " is already in the system.\n";
}
//------------------------------------------------------------------------------
	void DeleteNode(TreeNode*& tree)
	{
		cout << " Attempting to delete Node... " << endl;
		string data;
		TreeNode* tempPtr = tree;

		if (tree->left == NULL)
		{
			tree = tree->right;
			cout << " Checking Tree->right " << tree << endl;
			delete tempPtr;
		}
		else if (tree->right == NULL)
		{
			tree = tree->left;
			cout << " Checking Tree->left " << tree << endl;
			delete tempPtr;
		}
		else
		{
			cout << " Getting predecessor " << tree << endl;
			GetPredecessor(tree->left, data);
			tree->userID = data;
			Delete(tree->left, data);
		}
	}
	//---------------------------------------------------------------------------
	void Delete(TreeNode*& tree, string item)
	{
		if (item < tree->userID)
		{
			cout << " Left Node deleted.\n";
			Delete(tree->left, item);   // Look in left subtree.
		}
		else if (item > tree->userID)
		{
			cout << " Right Node deleted.\n";
			Delete(tree->right, item);  // Look in right subtree.
		}
		else
		{
			cout << " Node deleted.\n";
			DeleteNode(tree);           // Node found; call DeleteNode.
		}
	}
	//---------------------------------------------------------------------------
	void GetPredecessor(TreeNode* tree, string& data)
	// Sets data to the info member of the right-most node in tree.
	{
		while (tree->right != NULL)
		{
			tree = tree->right;
			data = tree->userID;
		}
	}
//------------------------------------------------------------------------------
void TreeType::DeleteItem(string userID) 
{
	string tempID = userID;
	bool found;

	cout << "Deleting " << userID << endl;
	TreeNode* nodePtr;
	TreeNode* parentPtr;
	cout << " Finding " << userID << endl;
	
	found = FindNode(root, userID, nodePtr, parentPtr);

	if(found)
	{
		if (nodePtr == root)
			DeleteNode(root);
		else
			if (parentPtr->left == nodePtr)
	   	   DeleteNode(parentPtr->left);
   	 else DeleteNode(parentPtr->right);
		cout << " " << tempID << " deleted.\n";
	}
	//else cout << userID << " not found.\n";
}
//------------------------------------------------------------------------------
void PrintTree(TreeNode* tree, std::ofstream& fout) 
{


	if (tree != NULL)
	{
		PrintTree(tree->left, fout);   // Print left subtree.
		cout << left << setw(15) << tree->userID;
		fout << left << setw(15) << tree->userID;
		cout << tree->passWord << endl;		
		fout << tree->passWord << endl;
		PrintTree(tree->right, fout);  // Print right subtree.
	}
	
}
//------------------------------------------------------------------------------
void TreeType::Print(std::ofstream& fout) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, fout);
}
//------------------------------------------------------------------------------
void PrintTreePre(TreeNode* tree, std::ofstream& fout) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
		cout << left << setw(15) << tree->userID;
		fout << left << setw(15) << tree->userID;
		cout << tree->passWord << endl;		
		fout << tree->passWord << endl;
		PrintTreePre(tree->left, fout);   // Print left subtree.
		PrintTreePre(tree->right, fout);  // Print right subtree.
  }
}
//------------------------------------------------------------------------------
void TreeType::PrintPre(std::ofstream& fout) const
// Calls recursive function Print to print items in the tree.
{
  PrintTreePre(root, fout);
}
//------------------------------------------------------------------------------
void PrintTreePost(TreeNode* tree, std::ofstream& fout) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
	PrintTreePost(tree->left, fout);   // Print left subtree.
	PrintTreePost(tree->right, fout);  // Print right subtree.
	cout << left << setw(15) << tree->userID;
	fout << left << setw(15) << tree->userID;
	cout << tree->passWord << endl;		
	fout << tree->passWord << endl;
  }
}
//------------------------------------------------------------------------------
void TreeType::PrintPost(std::ofstream& fout) const
// Calls recursive function Print to print items in the tree.
{
  PrintTreePost(root, fout);
}
//Destructor--------------------------------------------------------------------
TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}
	//---------------------------------------------------------------------------
	void Destroy(TreeNode*& tree)
	// Post: tree is empty; nodes have been deallocated.
	{
  	if (tree != NULL)
  	{
    	Destroy(tree->left);
    	Destroy(tree->right);
    	delete tree;
  	}
	}
//------------------------------------------------------------------------------
void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}
/*
//------------------------------------------------------------------------------
void TreeType::operator= (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree into root.
{
  {
  if (&originalTree == this)
    return;			// Ignore assigning self to self
  Destroy(root);	// Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }
}
//------------------------------------------------------------------------------
void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in the desired order.
{
  switch (order)
  {
    case PRE_ORDER : PreOrderTraversal(root, preQue);
                     break;
    case IN_ORDER  : InOrderTraversal(root, inQue);
                     break;
    case POST_ORDER: PostOrderTraversal(root, postQue);
                     break;
  }
}
//------------------------------------------------------------------------------
void PreOrderTraversal(TreeNode* tree, QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrderTraversal(tree->left, preQue);
    PreOrderTraversal(tree->right, preQue);
  }
}
//------------------------------------------------------------------------------
void InOrderTraversal(TreeNode* tree, QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrderTraversal(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrderTraversal(tree->right, inQue);
  }
}
//------------------------------------------------------------------------------
void PostOrderTraversal(TreeNode* tree, QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrderTraversal(tree->left, postQue);
    PostOrderTraversal(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}
//------------------------------------------------------------------------------
void TreeType::GetNextItem(ItemType& item, OrderType order, bool& finished)
{
  finished = false;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
}
*/
