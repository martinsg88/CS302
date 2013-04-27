//Program:	processImageMain.cpp
//Author:

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "image.h"
#include "stack.cpp"
#include "queue.cpp"

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
			cout << "\n (2) Get Image Information.";
			cout << "\n (3) Set the value of a pixel.";
			cout << "\n (4) Get the value of a pixel.";
			cout << "\n (5) Extract a subimage from an image.";
			cout << "\n (6) Compute the average gray-level of an image.";
			cout << "\n (7) Enlarge an image.";
			cout << "\n (8) Shrink an image.";
			cout << "\n (9) Reflect an image vertically or horizontally.";
			cout << "\n(10) Translate an image.";
			cout << "\n(11) Rotate an image.";
			cout << "\n(12) Add two images.";
			cout << "\n(13) Subtract two images.";
			cout << "\n(14) Compute the negative of an image.";
			cout << "\n(15) Count/Label Regions.";
			cout << "\n(16) Quit.\n";
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
		case 1://save an image to a file
			cout << "Enter the name of your output file: " << endl;
			cin >> outputName;

			writeImage(outputName, image);

		break;

		case 2://get image info
			
			image.getImageInfo(N, M, Q);

			cout << "\nThe image contains " << N << " rows, " << M << " columns ";
			cout << "and the maximum pixel value is " << Q << ".\n";

		break;

		case 3://set value of a pixel

			setPixelValues(N, M, image);

		break;

		case 4://get a pixel value

			getPixelValues(N, M, image);

		break;

		case 5://extract a sub-image

			extractImage(N, M, image);

		break;

		case 6://comput average gray-level of an image

			computeAvgGrayLevel();

		break;

		case 7:

			enlargeImage(image);
		
		break;

		case 8://shrink image
	
			shrinkImage(image);

		break;

		case 9://reflect image about the X (vertically )or Y axis (horizontally)

			reflectImage(image);

		break;

		case 10:
	
			translateImage(image);

		break;

		case 11://rotate an image

			rotateImage(N, M, image);

		break;

		case 12://add two images

			useOverloadPlus(image);

		break;

		case 13://subtract one image from another

			useOverloadMinus(image);

		break;

		case 14://get the negative of an image

			negateImage(image);

		break;

		case 15://count and label regions
	
			countLabelRegions(N, M, Q, type, image);

		break;

		case 16:

		//this is to return to main and exit

		break;

		default:

			cout << "Invalid input. Try again!" << endl;

		}
}
//------------------------------------------------------------------------------
void setPixelValues(int N, int M, ImageType& image)
{
	int row, column, PixelValue, tempPixVal;

	cout << "\nEnter Row coordinate (between 0 and " << N -1 << "): ";
	cin >> row;

	while(row < 0 || row > N - 1)//validate user input
		{
			cout << "Invalid row number. Enter again: ";
			cin >> row;
		}

	cout << "\nEnter Column coordinate (between 0 and " << M -1 << "): ";
	cin >> column;

	while(column < 0 || column > M -1)//validate user input
		{
			cout << "Invalid column number. Enter again: ";
			cin >> column;
		}

	image.getPixelVal(row, column, tempPixVal);//get current pixel value, display

	cout << "\nCurrent pixel value at row " << row << ", column ";
	cout << column << " is " << tempPixVal << ".\n";

	cout << "\nEnter new pixel value (between 0 and 255) for row ";
	cout << row << ", column " << column << " : ";
	cin >> PixelValue;

	while(PixelValue < 0 || PixelValue > 255)//validate user input
		{
			cout << "Invalid Pixel Value. Enter again: ";
			cin >> PixelValue;
		}

	image.setPixelVal(row, column, PixelValue);//set new pixel value
	image.getPixelVal(row, column, PixelValue);//get new pixel value

	cout << "\nPixel value at row " << row << ", column " << column;
	cout << " is now " << PixelValue << ".\n";
}
//------------------------------------------------------------------------------
void getPixelValues(int N, int M, ImageType& image)
{
	int row, column, PixelValue, tempPixVal;

	cout << "\nEnter Row coordinate (between 0 and " << N -1 << "): ";
	cin >> row;

	while(row < 0 || row > N - 1)// for valid row number
		{
			cout << "Invalid row number. Enter again: ";
			cin >> row;
		}

	cout << "\nEnter Column coordinate (between 0 and " << M -1 << "): ";
	cin >> column;

	while(column < 0 || column > M -1)// for valid column number
		{
			cout << "Invalid column number. Enter again: ";
			cin >> column;
		}

		image.getPixelVal(row, column, PixelValue);//get the pixel value

	cout << "\nPixel value at row " << row << ", column " << column;
	cout << " is " << PixelValue << ".\n";
}
//------------------------------------------------------------------------------
void extractImage(int N, int M, ImageType& image)
{
		int ULR, ULC, LRR, LRC;//extraction corner coordinates.
		char outputName[25];

		cout << "Enter the Upper Left corner extraction coordinates: \n";
		cout << "Upper-Left Row Coordinate: ";
		cin >> ULR;

		// for valid upper-left corner row coordinate
		while(ULR < 0 || ULR > N -1)
			{
				cout << "Invalid row coordinate. Enter again: ";
				cin >> ULR;
			}

		cout << "Upper-Left Column Coordinate: ";
		cin >> ULC;
		// for valid upper-left corner column coordinate
		while(ULC < 0 || ULC > M -1)
			{
				cout << "Invalid column coordinate. Enter again: ";
				cin >> ULC;
			}

		cout << "Now enter the Lower Right corner extraction coordinates: \n";
		cout << "Lower-Right Row Coordinate: ";
		cin >> LRR;
		// for valid lower-right corner row coordinate
		while(LRR < ULR || LRR > N -1)
			{
				cout << "Invalid row coordinate. Enter again: ";
				cin >> LRR;
			}
		// for valid lower-right corner row coordinate			
		cout << "Lower-Right Column Coordinate: ";
		cin >> LRC;
		while(LRC < ULC || LRC > M -1)
			{
				cout << "Invalid column coordinate. Enter again: ";
				cin >> LRC;
			}

			image.getSubImage(ULR, ULC, LRR, LRC, image);

			cout << "Enter the name of your extracted output file: " << endl;
			cin >> outputName;
			writeImage(outputName, image);
}
//------------------------------------------------------------------------------
void computeAvgGrayLevel()
{
	int M, N, Q, avg;
	char inputName[25],outputName[25];
	bool type;

	cout << "\nEnter the name of the file to calculate average gray-level: ";
	cout << endl;
 	cin >> inputName;

	readImageHeader(inputName, N, M, Q, type);
	ImageType avgimage(N, M, Q);
	readImage(inputName, avgimage);

	avg = avgimage.computeAvgGrayLevel(avgimage);

	cout << "\nThe average gray-level is: " << avg << "." << endl;
}
//------------------------------------------------------------------------------
void enlargeImage(ImageType& image)
{
	char outputName[25];
	int enlargeFactor;	
	ImageType temp;

	cout << "Enter the Enlarge Factor Number: ";
	cin  >> enlargeFactor;

	while(enlargeFactor <= 0)
		{
			cout << "Enlarge factor must be greater than " << enlargeFactor;
			cout << ". Enter again: ";
			cin >> enlargeFactor;
		}

	cout << "Image being Enlarged..." << endl;

	temp = image.enlargeImage(enlargeFactor,image);
	
	cout << "Enter the name of your enlarged output file: " << endl;
	cin >> outputName;
	writeImage(outputName, temp);
}
//------------------------------------------------------------------------------
void shrinkImage(ImageType& image)
{
	char outputName[25];
	int shrinkFactor;	
	ImageType temp;

	cout << "Enter the Shrink Factor Number: ";
	cin  >> shrinkFactor;

	while(shrinkFactor <= 0)
		{
			cout << "Shrink factor must be greater than " << shrinkFactor;
			cout << ". Enter again: ";
			cin >> shrinkFactor;
		}
	cout << "Image being shrunk..." << endl;

	temp = image.shrinkImage(shrinkFactor,image);
	
	cout << "Enter the name of your shrunk output file: " << endl;
	cin >> outputName;
	writeImage(outputName, temp);
}
//------------------------------------------------------------------------------
void reflectImage(ImageType& image)
{
	char outputName[25];

	cout << "Image being reflected..." << endl;

	image.reflectImage(image);
	
	cout << "Enter the name of your reflected output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image);
}
//------------------------------------------------------------------------------
void translateImage(ImageType& image)
{
	char outputName[25];
	int translateFactor;

	ImageType temp;
	
	cout << "Enter the translation Factor Number: ";
	cin  >> translateFactor;
	cout << endl << endl;	

	temp = image.translateImage(translateFactor,image);
	
	cout << "Enter the name of your translated image output file: " << endl;
	cin >> outputName;
	writeImage(outputName, temp);
}
//------------------------------------------------------------------------------
void rotateImage(int N, int M, ImageType& image)
{
	float angle, theta;
	char outputName[25];

	cout << "Image will be rotated about its center coordinates (" << N/2;
	cout << ", " << M/2 << ").\n";
	cout << "\nEnter angle in degrees between -360 and 360 to rotate ";
	cout << "image: ";
	cin >> angle;

	while(angle < -360 || angle > 360)// for valid angle
		{
			cout << "Invalid angle. Enter again: ";
			cin >> angle;
		}

	cout << "Image being rotated...\n";

	theta = angle * PI/180;	//convert angle in degrees to radians

	image.rotateImage(theta, image);

	cout << "Enter the name of your rotated output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image);
}
//------------------------------------------------------------------------------
void negateImage(ImageType& image)
{
	char outputName[25];

	cout << "Image being negated..." << endl;

	image.negateImage(image);
	
	cout << "Enter the name of your negated output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image);
}
//------------------------------------------------------------------------------
void useOverloadPlus(ImageType& image)
{
	int M, N, Q;
	char inputName[25],outputName[25];
	bool type;

	cout << "\nEnter the name of the file to be added to your original image: ";
	cout << endl;
 	cin >> inputName;

	readImageHeader(inputName, N, M, Q, type);
	ImageType image4(N, M, Q);
	readImage(inputName, image4);

	ImageType image5(N, M, Q);
	
	image5 = image + image4;

	cout << "Enter the name of your added output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image5);
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
	int vall, vali, valo, trash=0;
	int popi, popj;
	int ni,nj;
	int N,M,Q; //get image info
	int marker = -1;
	char outputName[25];
	
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
					trash = 1;
					while(!queue.isEmpty())
					{
						queue.dequeue(popi,popj);//check neighbors
						for(int k = popi-1; k<popi+2; k++)
						{
							for(int l = popj-1; l<popj+2; l++)
							{
								image.getPixelVal(k,l,vali);
								if(vali == 255)
								{
									trash++;
									queue.enqueue(k,l);
									image.setPixelVal(k,l,0);
								}
							}
						}
							outputImage.setPixelVal(popi,popj,label);				
					}
							if(trash > 10 )
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
//------------------------------------------------------------------------------
void findComponentDFS(ImageType& image, ImageType& outputImage)
{
	int vall, vali, valo, trash=0;
	int popi, popj;
	int ni,nj;
	int N,M,Q; //get image info
	int marker = -1;
	char outputName[25];
	
	int coinComp = 0, label = 200;
	
	stacktype stack;//declare a stack
	
	stack.makeEmpty();
	
	outputImage.getImageInfo(N,M,Q);
	
		for(int i = 1; i < N-1; i++)//start checking the entire image
		{
			for(int j = 1; j < M-1; j++)
			{
				image.getPixelVal(i,j,vali);
				if(vali == 255)//if the pixel value is white...
				{
					image.setPixelVal(i,j,0);//make it black so it isn't counted agn
					stack.push(i,j);
					trash = 1;//initialize
					while(!stack.isEmpty())
					{
						stack.pop(popi,popj);
						for(int k = popi-1; k<popi+2; k++)//check the neighbors
						{
							for(int l = popj-1; l<popj+2; l++)
							{
								image.getPixelVal(k,l,vali);
								if(vali == 255)
								{
									trash++;
									stack.push(k,l);
									image.setPixelVal(k,l,0);//mark the neighbor
								}
							}
						}	//set the corresponding value to the output image
							outputImage.setPixelVal(popi,popj,label);
					}		
							if(trash > 10)
							{
							++coinComp;
							label = label - 30;
							cout << "coin counts " << coinComp<<
																	 "   label "<< label << endl;	
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

	cout << "\nEnter the file name of your finished image: " << endl;
	cin >> outputName;
	writeImage(outputName, outputImage);
	
}
