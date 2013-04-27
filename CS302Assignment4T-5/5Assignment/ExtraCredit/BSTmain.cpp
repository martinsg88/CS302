//BSTmain.cpp
#include <iostream>
#include <fstream>
#include <iomanip>

#include "TreeType.h"

using namespace std;

const int FILENAMESIZE = 25;

void populateBST(TreeType&);

//prototype to open a data file
void openFile(ifstream &fin, char *textFiles);

//prototype to call a menu system
int displayMenu();

//prototype to validate user's menu choice
int validateChoice(int choice);

//prototype to execute case statements
void executeCases(TreeType&, int);

//prototype to validate user's response
char validateResponse();

//==============================================================================
int main()
{
	int choice;			//variable for user's menu choice
	char response;		//variable for user's response (Y/y or N/n)
	TreeType BST;		//instantiate a UPQType object
	populateBST(BST);	//populate the UPQType object

	do
		{
			choice = displayMenu();

			executeCases(BST, choice);

			response = validateResponse();
		}
	
	while(response == 'Y' || response == 'y');//repeat do loop if Y/y	

	return 0;
}
//==============================================================================
void populateBST(TreeType& BST)
{
	ifstream fin;
	char textFile[FILENAMESIZE] = "UIDPwords.txt";
	string userID;
	string password;

	openFile(fin, textFile);				//open a textfile

	fin >> userID;								//read in first name
	fin >> password;							//and password

	while(!fin.eof())
	{
		BST.InsertItem(userID, password);//insert and 
		fin >> userID;							//read in remaining userIDs
		fin >> password;						//and passwords
	}

	fin.close();						//close text file

	cout << endl << textFile << " is closed...\n";
}
//------------------------------------------------------------------------------
void openFile(ifstream &fin, char *textFile)
{
	fin.open(textFile);//open file

	cout << endl << textFile << " is open...\n\n";
	
	if(!fin)//if it doesn't...
		{ 
			cout << "Input file open error!" << endl;
			exit(-1);
		}
}
//------------------------------------------------------------------------------
int displayMenu()
{
	int choice, selection;

	cout << "\nPlease choose from the following menu options:\n\n";

	cout << "	(1) Add New User\n";
	cout << "	(2) Delete User\n";
	cout << "	(3) Verify User\n";
	cout << "	(4) Print User\n";
	cout << "	(5) Store data (Inorder)\n";
	cout << "	(6) Store data (Preorder)\n";
	cout << "	(7) Store data (Postorder)\n";
	cout << "	(8) Exit\n";

	cout << "\nSelection: ";
	cin >> choice;
	selection = validateChoice(choice);

	return selection;
}
//------------------------------------------------------------------------------
int validateChoice(int choice)
{
	while(choice < 1 || choice > 8)//check the selection
		{
			cout << "Selection must be between 1 and 8. Enter again.";
			cin >> choice;
		}

	if(choice == 8)
		{
			cout << "\nThanks for using the system." << endl;
		}

	return choice;
}
//------------------------------------------------------------------------------
char validateResponse()
{
	char response;//variable to hold user's response

	cout << "\n\nMake another selection (Y/y or N/n)? ";
	cin >> response;

	while(response != 'Y' && response != 'y' &&
			response != 'N' && response != 'n')//validate enty
				{
					cout << "\nResponse must be Y/y or N/n. Enter again: ";
					cin >> response;//get input again
				}

	return response;
}
//------------------------------------------------------------------------------
void executeCases(TreeType& BST, int choice)
{
	string userID;
	string password;
	bool found;
	ofstream fout;

	switch (choice)
	{
		case 1://Add a user
				cout << "\nEnter new user name: ";
				cin >> userID;
				BST.RetrieveItem(userID, found);
				if(found)
					cout << userID << " is already in the system.\n";
				else
				{
					cout << "\nEnter new user password: ";
					cin >> password;
					BST.InsertItem(userID, password);
					cout << userID << " added to the system.";
				}
		break;

		case 2://Delete a user
				cout << "\nEnter user name to delete: ";
				cin >> userID;
				BST.RetrieveItem(userID, found);
				if(!found)
					cout << userID << " not in the system.\n";
				else
				{
					BST.DeleteItem(userID);
					cout << userID << " removed from the system.";
				}
		break;

		case 3://Verify user
				cout << "\nEnter user's name to verify: ";
				cin >> userID;
				BST.RetrieveItem(userID, found);
				if(found)
					cout << userID << " found.\n";
				else
					cout << userID << " not found.\n";
		break;

		case 4://Display users
		{
				fout.open("inorder.txt");

				if(!fout)//Check if the input file opened successfully; if not...
				{//open if
	  				cout << "Your output file did not open successfully! " << endl;
	  				exit(-1);
				}//close if

				BST.Print(fout);
				fout.close();
		}
		break;

		case 5://Store data using inorder traversal
		{
				fout.open("inorder.txt");

				if(!fout)//Check if the input file opened successfully; if not...
				{//open if
	  				cout << "Your output file did not open successfully! " << endl;
	  				exit(-1);
				}//close if

				BST.Print(fout);
				fout.close();
		}
		break;

		case 6://Store data using preorder traversal
		{
				fout.open("preorder.txt");
				if(!fout)//Check if the input file opened successfully; if not...
				{//open if
	  				cout << "Your output file did not open successfully! " << endl;
	  				exit(-1);
				}//close if

				BST.PrintPre(fout);
				fout.close();
		}
		break;

		case 7://Store data using postorder traversal
		{
				ofstream fout;
				fout.open("postorder.txt");
				if(!fout)//Check if the input file opened successfully; if not...
				{//open if
	  				cout << "Your output file did not open successfully! " << endl;
	  				exit(-1);
				}//close if

				BST.PrintPost(fout);
				fout.close();
		}
		break;

		case 8://
		break;

		default:

			cout << "Invalid input. Try again!" << endl;

		}
}
//------------------------------------------------------------------------------
