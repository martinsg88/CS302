//Program:	processImageMain.cpp
//Author:

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "image.h"
#include "RGB.h"

const float PI = 3.141592653;

using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);

//overloaded readImage() prototypes

void readImage(char fname[], ImageType<int>& image);
void readImage(char fname[], ImageType<RGB>& image);

//overloaded writeImage() prototypes

void writeImage(char fname[], ImageType<int>& image);
void writeImage(char fname[], ImageType<RGB>& image);

//prototype to execute case statements
template<class pixelType>
void executeCases(int, int, int, int, ImageType<pixelType>& image);

template<class pixelType>
void setPixelValues(int, int, ImageType<pixelType>& image);

template<class pixelType>
void getPixelValues(int, int, ImageType<pixelType>& image);

template<class pixelType>
void extractImage(int, int, ImageType<pixelType>& image);

template<class pixelType>
void computeAvgGrayLevel(ImageType<pixelType>& image);

template<class pixelType>
void enlargeImage(ImageType<pixelType>&);

template<class pixelType>
void shrinkImage(ImageType<pixelType>&);

template<class pixelType>
void reflectImage(ImageType<pixelType>&);

template<class pixelType>
void translateImage(ImageType<pixelType>&);

template<class pixelType>
void rotateImage(ImageType<pixelType>& image);

template<class pixelType>
void negateImage(ImageType<pixelType>&);

template<class pixelType>
void useOverloadPlus(ImageType<pixelType>&);

template<class pixelType>
void useOverloadMinus(ImageType<pixelType>&);

//==============================================================================
int main(int argc, char *argv[])
{//open main

	int M, N, Q;
	bool Color;
	int choice;
	char inputName[25];

	cout << "\nEnter the name of the image file you would like to process:  ";
	cin >> inputName;

	readImageHeader(inputName, N, M, Q, Color);// read image header
	
	ImageType<int> grayLevelImage(N, M, Q);//instantiate grayscale image
	ImageType<RGB>	colorImage(N, M, Q);		//instantiate color image

	if(!Color)
	{
		//read gray image
		readImage(inputName, grayLevelImage);	
	}
	else 

		readImage(inputName, colorImage);   // read color image

	while(choice != 15)
		{
			cout << "\nPlease choose from the following menu options:\n";

			cout << "\n (1) Save an image to a file";
			cout << "\n (2) Get Image Information.";
			cout << "\n (3) Set Pixel Value.";
			cout << "\n (4) Get Pixel Value.";
			cout << "\n (5) Extract a subimage from an image.";
			cout << "\n (6) Compute Average Gray-level.";
			cout << "\n (7) Enlarge Image.";
			cout << "\n (8) Shrink Image.";
			cout << "\n (9) Reflect Image Vertically or Horizontally.";
			cout << "\n(10) Translate Image.";
			cout << "\n(11) Rotate Image.";
			cout << "\n(12) Add two images.";
			cout << "\n(13) Subtract two images.";
			cout << "\n(14) Compute the negative of an image.";
			cout << "\n(15) Quit.\n";
			cout << "\nSelection: ";
			cin >> choice;
			if(choice == 15)
			{
				cout << "\nThanks for using the system." << endl;
			}

			if(!Color)
			{
				executeCases(choice, N, M, Q, grayLevelImage);
			}
			else
			{
				executeCases(choice, N, M, Q,colorImage);
			}
		}

 return (1);

}//close main
//==============================================================================
template<class pixelType>
void executeCases(int choice, int N, int M, int Q, 
					            								 ImageType<pixelType>& image)
{
	char outputName[25];

	switch (choice)
	{
		case 1://save an image to a file
			cout << "Enter the name of your output file: " << endl;
 			cin >> outputName;
		
			//write image
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
	
			computeAvgGrayLevel(image);

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

			rotateImage(image);

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

		case 15:

		//this is to return to main and exit

		break;

		default:

			cout << "Invalid input. Try again!" << endl;

		}
}
//------------------------------------------------------------------------------
template<class pixelType>
void setPixelValues(int N, int M, ImageType<pixelType>& image)
{
	int row, column;
	pixelType PixelValue, tempPixVal;
	float llimit = 0; // lower limit user input for RGB and Int
	float ulimit = 255; //upper limit user input for RGB and Int

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
	cout << row << ", column " << column << ": ";
	cin >> PixelValue;

	while(PixelValue < llimit || PixelValue > ulimit)//validate user input
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
template<class pixelType>
void getPixelValues(int N, int M, ImageType<pixelType>& image)
{
	int row, column;
	pixelType PixelValue, tempPixVal;

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

	cout << "\nPixel value at row " << row << ", column " << column ;
	cout << " is " << PixelValue << ".\n";
}
//------------------------------------------------------------------------------
template<class pixelType>
void extractImage(int N, int M, ImageType<pixelType>& image)
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
template<class pixelType>
void computeAvgGrayLevel(ImageType<pixelType>& image)
{
	int M, N, Q; 
	pixelType avg;
	char inputName[25],outputName[25];

	image.computeAvgGrayLevel(image);
}

//------------------------------------------------------------------------------
template<class pixelType>
void enlargeImage(ImageType<pixelType>& image)
{
	int N,M,Q;
	N = M = Q = 0;	

	char outputName[25];
	int enlargeFactor;	
	ImageType<pixelType> temp(N,M,Q);

	cout << "Enter the Enlarge Factor Number: ";
	cin  >> enlargeFactor;

	while(enlargeFactor <= 0)
		{
			cout << "Enlarge factor must be greater than " << enlargeFactor;
			cout << ". Enter again: ";
			cin >> enlargeFactor;
		}

	cout << "Image being Enlarged..." << endl;

	temp = image.enlargeImage(enlargeFactor, image);
	
	cout << "Enter the name of your enlarged output file: " << endl;
	cin >> outputName;
	writeImage(outputName, temp);
}
//------------------------------------------------------------------------------
template<class pixelType>
void shrinkImage(ImageType<pixelType>& image)
{
	char outputName[25];
	int shrinkFactor;	
	ImageType<pixelType> temp;

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
template<class pixelType>
void reflectImage(ImageType<pixelType>& image)
{
	char outputName[25];

	cout << "Image being reflected..." << endl;

	image.reflectImage(image);
	
	cout << "Enter the name of your reflected output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image);
}
//------------------------------------------------------------------------------
template<class pixelType>
void translateImage(ImageType<pixelType>& image)
{
	char outputName[25];
	int translateFactor;

	ImageType<pixelType> temp;
	
	cout << "Enter the translation Factor Number: ";
	cin  >> translateFactor;
	cout << endl << endl;	

	temp = image.translateImage(translateFactor, image);
	
	cout << "Enter the name of your translated image output file: " << endl;
	cin >> outputName;
	writeImage(outputName, temp);
}
//------------------------------------------------------------------------------
template<class pixelType>
void rotateImage(ImageType<pixelType>& image)
{
	int N, M, Q;
	float angle, theta;
	char outputName[25];

	image.getImageInfo(N, M, Q);

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
template<class pixelType>
void negateImage(ImageType<pixelType>& image)
{
	char outputName[25];

	cout << "Image being negated..." << endl;

	image.negateImage(image);
	
	cout << "Enter the name of your negated output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image);
}
//------------------------------------------------------------------------------
template<class pixelType>
void useOverloadPlus(ImageType<pixelType>& image)
{
	int M, N, Q;
	char inputName[25],outputName[25];
	bool type;

	cout << "\nEnter the name of the file to be added to your original image: ";
	cout << endl;
 	cin >> inputName;

	readImageHeader(inputName, N, M, Q, type);
	ImageType<pixelType> image4(N, M, Q);
	readImage(inputName, image4);

	ImageType<pixelType> image5(N, M, Q);
	 
	image5 = image + image4;

	cout << "Enter the name of your added output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image5);
}
//------------------------------------------------------------------------------
template<class pixelType>
void useOverloadMinus(ImageType<pixelType>& image)
{
	int M, N, Q;
	char inputName[25],outputName[25];
	bool type;

	cout << "\nEnter the name of the file to be subtracted from your original ";
	cout << "image."  << endl;
	cin >> inputName;

	readImageHeader(inputName, N, M, Q, type);
	ImageType<pixelType> image6(N, M, Q);
	readImage(inputName, image6);

	ImageType<pixelType> image7(N, M, Q);
	
	image7 = image - image6;

	cout << "Enter the name of your subtracted output file: " << endl;
	cin >> outputName;
	writeImage(outputName, image7);
}

//------------------------------------------------------------------------------
