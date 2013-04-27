//Program:	processImageMain.cpp
//Author:

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "image.h"
#include "DFSstack.h"
#include "BFSqueue.h"

const float PI = 3.1415927;

using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);

int readImage(char[], ImageType&);

int writeImage(char[], ImageType&);

//prototype to execute case statements
void executeCases(int choice, int N, int M, int Q, bool type, ImageType& image);

void setPixelValues(int N, int M, ImageType& image);

void getPixelValues(int N, int M, ImageType& image);

void extractImage(int N, int M, ImageType& image);

void computeAvgGrayLevel();

void enlargeImage(ImageType&);

void shrinkImage(ImageType&);

void reflectImage(ImageType&);

void translateImage(ImageType&);

void rotateImage(int N, int M, ImageType& image);

void negateImage(ImageType&);

void countLabelRegions(int N, int M, int Q, bool type, ImageType&);

int connectedComponents(ImageType&, ImageType&, int);

void findComponentBFS(ImageType&, ImageType&);

void findComponentDFS(ImageType&, ImageType&);

void useOverloadPlus(ImageType&);

void useOverloadMinus(ImageType&);

//==============================================================================
int main(int argc, char *argv[])
{//open main

	int M, N, Q;	//row, column and max gray level value variables
	bool type;
	int choice;
	char inputName[25];

	cout << "\nEnter the name of the image file you would like to process:  ";
	cin >> inputName;

	// read image header
	readImageHeader(inputName, N, M, Q, type);

	// allocate memory for the image array
	ImageType image(N, M, Q);

	// read image
	readImage(inputName, image);

	while(choice != 16)
		{
			cout << "\nPlease choose from the following menu options:\n";

			cout << "\n (1) Save an image to a file";
			cout << "\n (2) Quit.\n";
			cout << "\nSelection: ";
			cin >> choice;
			if(choice == 16)
			{
				cout << "\nThanks for using this system." << endl;
			}

			executeCases(choice, N, M, Q, type, image);
		}

 return (1);

}//close main
//==============================================================================
void executeCases(int choice, int N, int M, int Q, bool type, ImageType& image)
{
	char outputName[25];


	switch (choice)
	{


		case 1://count and label regions
	
			countLabelRegions(N, M, Q, type, image);

		break;

		case 2:

		//this is to return to main and exit

		break;

		default:

			cout << "Invalid input. Try again!" << endl;

		}
}

//------------------------------------------------------------------------------
void useOverloadMinus(ImageType& image)
{
	int M, N, Q;
	char inputName[25],outputName[25];
	bool type;

	cout << "\nEnter the name of the file to be subtracted from your original ";
	cout << "image."  << endl;
	cin >> inputName;

	readImageHeader(inputName, N, M, Q, type);
	ImageType image6(N, M, Q);
	readImage(inputName, image6);

	ImageType image7(N, M, Q);
	
	image7 = image - image6;

	cout << "Enter the name of your subtracted output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image7);
}
//------------------------------------------------------------------------------
void countLabelRegions(int N, int M, int Q, bool type, ImageType& image)
{
	int threshold;		//variable for threshold
	int coincount,choice;
	char outputName[25], inputFile[80];	//char arrays to hold file names
	ImageType Histogram(256, 256, 255); //declare an object to hold a histogram
	ImageType outputImage(N, M, Q);

	//Histogram---------------------------------------------------------------
	cout << "\nCreating histogram...\n";
	Histogram = image.displayHistogram(image, threshold);

	cout << "\n Histogram created. Enter the name of your Histogram file: ";
	cin >> outputName;
	writeImage(outputName, Histogram);

	//Thresholding------------------------------------------------------------
	cout << "\nImage being thresholded...";
	image.threshold(threshold, image);
	cout << "\n Image has been auto-thresholded - Value is: ";
	cout << threshold << ".\n";	

	cout << "\nEnter the name of your Threshold image file: ";
	cin >> outputName;
	writeImage(outputName, image);

	//Dilating and Eroding----------------------------------------------------
	cout << "\nImage being Dilated and eroded...\n";
	image.dilate(image);
	image.erode(image);

	cout << "\n Image has been dilated and eroded. Enter the file name of your ";
	cout << "cleaned image: ";
	cin >> outputName;
	writeImage(outputName, image);
	
	cout << "\nImage ready from counting and labeling - choose algorithm: \n";
	cout << "\n(1) Breadth-First-Search (BFS)\n";
	cout << "(2) Depth-First-Search (DFS)\n";
	cout << "\nYour selection: ";
	cin >> choice;
	//cout << endl;

	switch (choice)
	{
		case 1:
			choice = 1;	//BFS
		break;		

		case 2:	
			choice = 2;	//DFS
		break;
		
		default:
			cout <<	"\nInvalid choice, BFS Defaulted." << endl;
			choice = 1;
		}
	
	//Connected Components----------------------------------------------------
	cout << "\nGetting ready to connect components...\n" << endl;
	coincount = connectedComponents(image, outputImage, choice);
}
//------------------------------------------------------------------------------
int connectedComponents(ImageType& image, ImageType& outputImage, int choice)
{
	int i = 0, j = 0, coinCount = 0, label = 0;
	int N = 0, M = 0, Q = 0, valin = 0, valout = 0;
	outputImage.getImageInfo(N,M,Q);

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			outputImage.setPixelVal(i,j,255);
		}
	}		
	
	if(choice == 1)
	{
		findComponentBFS(image, outputImage);			
	}
	if(choice == 2)
	{
		findComponentDFS(image, outputImage);
	}

return(coinCount);
}
//------------------------------------------------------------------------------
void findComponentBFS(ImageType& image, ImageType& outputImage)
{
	int vall, vali, valo, size=0;
	int popi, popj;
	int ni,nj;
	int N,M,Q; //get image info
	int marker = -1;
	char outputName[25];
	float sumx = 0;
	float sumy = 0;
	int total;
	
	
	PixelList pixelList;
	
	int coinComp = 0, label = 200;

	queuetype queue;//declare a queue
	
	queue.makeEmpty();
	
	outputImage.getImageInfo(N, M, Q);
		
		for(int i = 1; i < N-1; i++)//start checking the entire image
		{
			for(int j = 1; j < M-1; j++)
			{
				image.getPixelVal(i,j,vali);
				if(vali == 255)
				{
					image.setPixelVal(i,j,0);
					queue.enqueue(i,j);
					size = 1;
					pixelList.MakeEmpty();
					while(!queue.isEmpty())
					{
						queue.dequeue(popi,popj);//check neighbors
						pixelList.InsertItem(popi,popj);
						
						for(int k = popi-1; k<popi+2; k++)
						{
							for(int l = popj-1; l<popj+2; l++)
							{
								image.getPixelVal(k,l,vali);
								if(vali == 255)
								{
									sumx += popi;
						         sumy += popj;
									size++;
									queue.enqueue(k,l);
									image.setPixelVal(k,l,0);
								}
							}
						}
							outputImage.setPixelVal(popi,popj,label);	
							sumx = sumx/size;
							sumy = sumy/size;		
							//insert a pixel list to region here...	
					}
							if(size > 30 )
							{
								++coinComp;
								label = label - 30;
								cout << "Coin count: " << coinComp <<
																	 "   Label "<< label << endl;	
							}
				}
			}
		}
		//set the background to black
		for(int i = 1; i < N-1; i++)
		{
			for(int j = 1; j < M-1; j++)
			{
				outputImage.getPixelVal(i,j,valo);
				if(valo == 255)
				outputImage.setPixelVal(i,j,0);
			}
		}

	cout << "\nEnter the file name of your finished image: ";
	cin >> outputName;
	writeImage(outputName, outputImage);
}
