//UPQmain.cpp
#include <iostream>
#include <fstream>

#include "UPQType.h"

using namespace std;

const int FILENAMESIZE = 25;

void populateQ(UPQType&);

//prototype to open a data file
void openFile(ifstream &fin, char *textFileName);

//prototype to call a menu system
int displayMenu();

//prototype to validate user's numerical choice
int validateChoice(int choice);

//prototype to execute case statements
void executeCases(UPQType&, int);

//prototype to validate user's character response
char validateResponse();

//==============================================================================
int main()
{
	int choice;			//variable for user's menu choice
	char response;		//variable for user's response (Y/y or N/n)
	UPQType UPQ(16);	//instantiate a UPQType object
	populateQ(UPQ);	//populate the UPQType object

	do
		{
			choice = displayMenu();

			executeCases(UPQ, choice);

			response = validateResponse();
		}
	
	while(response == 'Y' || response == 'y');//repeat do loop if Y/y	

	return 0;
}
//==============================================================================
void populateQ(UPQType& UPQ)
{
	ifstream fin;
	char textFileName[FILENAMESIZE] = "TextFiles/PQFile.txt";
	int PQitem;

	openFile(fin, textFileName);		//open a textfile

	fin >> PQitem;						//read in first item

	while(!fin.eof())
	{	
		UPQ.Enqueue(PQitem);
		fin >> PQitem;
	}

	fin.close();						//close text file

	cout << endl << textFileName << " is closed...\n";
}
//------------------------------------------------------------------------------
void openFile(ifstream &fin, char *textFileName)
{
	fin.open(textFileName);//open file

	cout << endl << textFileName << " is open...\n";
	
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

		cout << "	(1) Dequeue top item"	<< endl;
		cout << "	(2) Enqueue an item"	<< endl;
		cout << "	(3) Remove an item"	<< endl;
		cout << "	(4) Update an item"	<< endl;
		cout << "	(5) Print PQ items"	<< endl;
		cout << "	(6) Exit"				<< endl;

		cout << "\nSelection: ";
		cin >> choice;

	selection = validateChoice(choice);

	return selection;
}
//------------------------------------------------------------------------------
int validateChoice(int choice)
{
	while(choice < 1 || choice > 6)//check the selection
		{
			cout << "Selection must be between 1 and 6. Enter again.";
			cin >> choice;
		}

	if(choice == 6)
		{
			cout << "\nThanks for using the system." << endl;
		}

	return choice;
}
//------------------------------------------------------------------------------
char validateResponse()
{
	char response;//variable to hold user's response

	cout << "\nMake another selection (Y/y or N/n)? ";
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
void executeCases(UPQType& UPQ, int choice)
{
	int item, newItem;

	switch (choice)
	{
		case 1://Dequeue an item
				UPQ.Dequeue(item);
				//cout << "\n" << item << " dequeued. \n";
		break;

		case 2://Enqueue an item
				cout << "\nEnter item to enqueue: ";
				cin >> item;
				UPQ.Enqueue(item);
		break;

		case 3://Remove an item
				cout << "\nEnter item to remove: ";
				cin >> item;
				UPQ.Remove(item);
		break;

		case 4://Update an item
				cout << "\nEnter item to update: ";
				cin >> item;
				cout << "\nEnter new item: ";
				cin >> newItem;
				UPQ.Update(item, newItem);
				cout << endl;
		break;

		case 5://Display items
				cout << "\nItems in Queue (from highest to lowest priority):\n";
				UPQ.Print();
		break;

		case 6://Exit
				cout << "Queueing and Heaping Complete!" << endl;
		break;

		default:

			cout << "Invalid input. Try again!" << endl;
	}
}
//------------------------------------------------------------------------------