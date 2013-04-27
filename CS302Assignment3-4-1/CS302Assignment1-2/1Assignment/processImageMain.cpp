//Program:	processImageMain.cpp

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "image.h"

const float PI = 3.1415927;

using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);
int readImage(char[], ImageType&);
int writeImage(char[], ImageType&);

//prototype to execute case statements
void executeCases(int choice, int N, int M, int Q, ImageType& image);
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
//void useCopyConstructor(char[], const ImageType&);
//void useOverloadEqual(char[], const ImageType&);
void useOverloadPlus(ImageType&);
void useOverloadMinus(ImageType&);

//==============================================================================
int main(int argc, char *argv[])
{//open main

	int M, N, Q;	//rows, cols, gray-level values
	bool type;
	int choice;
	char inputName[25];

	cout << "\nEnter the name of the image file you would like to process:  ";
	cin >> inputName;

	// read image header
	readImageHeader(inputName, N, M, Q, type);

	// allocate memory for the image array
	cout << "\nGetting ready to create an object...\n";
	ImageType image(N, M, Q);
	cout << " Object created...\n";

	// read image
	readImage(inputName, image);

	while(choice != 15)
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
			cout << "\n(15) Quit.\n";
			cout << "\nSelection: ";
			cin >> choice;
			if(choice == 15)
			{
				cout << "\nThanks for using this system." << endl;
			}

			executeCases(choice, N, M, Q, image);
		}

 return (1);

}//close main
//==============================================================================
void executeCases(int choice, int N, int M, int Q, ImageType& image)
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

		case 15:

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

	cout << "\nEnter Row coordinate (between 0 and " << N - 1 << "): ";
	cin >> row;

	while(row < 0 || row > N - 1)//validate user input
		{
			cout << "Invalid row number. Enter again: ";
			cin >> row;
		}

	cout << "\nEnter Column coordinate (between 0 and " << M - 1 << "): ";
	cin >> column;

	while(column < 0 || column > M -1)//validate user input
		{
			cout << "Invalid column number. Enter again: ";
			cin >> column;
		}

	image.getPixelVal(row, column, tempPixVal);//get current pixel val, display

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
	int enlargFactor;	
	ImageType temp;

	cout << "Enter the Enlarge Factor Number: ";
	cin  >> enlargFactor;
	cout << endl << endl;	

	cout << "Image being Enlarged..." << endl;

	temp = image.enlargeImage(enlargFactor,image);
	
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
	cout << endl << endl;	

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

	image.rotateImage(N, M, theta, image);

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
/*void useCopyConstructor(char outputName[], const ImageType& image)
{
	ImageType image2(image);
	//writeImage(outputName, image2);
}*/
//------------------------------------------------------------------------------
void useOverloadEqual(char outputName[], const ImageType& image)
{
	ImageType image3;
	image3 = image;
	//writeImage(outputName, image3);
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