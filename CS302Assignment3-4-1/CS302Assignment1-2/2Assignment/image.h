#ifndef IMAGE_H
#define IMAGE_H
#include <cstdlib>
#include <iostream>
#include <math.h>

#include "RGB.h"

using namespace std;

template <class pixelType>
class ImageType
{

 private:
   int N, M, Q;				//N = rows, M = columns, Q = level
   pixelType **pixelValue;	//double pointer for dynamically created 2D array

 public:
	//constructors	
  	ImageType();							//Default Constructor
	ImageType(int, int, int);				//Parameter Constructor
	ImageType(const ImageType<pixelType>&);	//Copy Constructor

	//getters
 	void getImageInfo(int&, int&, int&);
	void getPixelVal(int, int, pixelType&);
	void getSubImage(int, int, int, int, ImageType&);

	//setters
	void setImageInfo(int, int, int);
	void setPixelVal(int, int, pixelType);

	//modifiers
	void computeAvgGrayLevel(const ImageType<pixelType>&);
	ImageType<pixelType> enlargeImage(int, ImageType<pixelType>&);
	ImageType<pixelType> shrinkImage(int, ImageType<pixelType>&);
	void negateImage(ImageType<pixelType>&);
	void reflectImage(ImageType<pixelType>&);
	ImageType<pixelType> translateImage(int, ImageType<pixelType>&);
	void rotateImage(float, ImageType<pixelType>&);

	//observers
	bool inBounds(int, int);
	void abs(RGB&);

	//Overloaded operators
	void operator = (const ImageType<pixelType>&);
	ImageType<pixelType> operator + (ImageType<pixelType>&);
	ImageType<pixelType> operator - (ImageType<pixelType>&);
	void operator < (int);

	//destructor
	~ImageType();
};
//Default Constructor-----------------------------------------------------------
template<class pixelType>
ImageType<pixelType>::ImageType()
{
 cout << "\nEntering Default Constructor..." << endl;
 N = 0;
 M = 0;
 Q = 0;

 pixelValue = NULL;

 cout << " Departing Default Constructor...\n" << endl;
}
//Parameter Constructor---------------------------------------------------------
template<class pixelType>
ImageType<pixelType>::ImageType(int tmpN, int tmpM, int tmpQ)
{
 cout << "\nEntering Parameter Constructor..." << endl;
 N = tmpN;
 M = tmpM;
 Q = tmpQ;
 cout << "Getting ready to create pointers and array...\n";
 pixelValue = new pixelType* [N];//create a "single column" of pointers

//	RGB tmpRGB;
	
	for(int i = 0; i < N; i++)
	{	//create row elements for the "col" of pointers
		pixelValue[i] = new pixelType[M];
		{

			for(int j = 0; j < M; j++)
			{			
				pixelValue[i][j] = 0; 
			}
		}
	}

 cout << " Departing Parameter Constructor...\n" << endl;
}
//Copy Constructor--------------------------------------------------------------
template<class pixelType>
ImageType<pixelType>::ImageType(const ImageType<pixelType> &object)
{
 cout << "\nEntering Copy Constructor..." << endl;
	N = object.N;
	M = object.M;
	Q = object.Q;

	pixelValue = new pixelType* [N];//allocate a "single column" of pointers

	for(int i = 0; i < N; i++)//for each of the pointers in the new column...
		{
			pixelValue[i] = new pixelType[M];//allocate "a row" of elements
			for(int j = 0; j < M; j++)
				pixelValue[i][j] = object.pixelValue[i][j];
		}
 cout << " Departing Copy Constructor...\n" << endl;
}
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::getImageInfo(int& rows, int& cols, int& levels)
{
 rows = N;
 cols = M;
 levels = Q;
}
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::getPixelVal(int i, int j, pixelType& val)
{
 val = pixelValue[i][j];
} 
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::setImageInfo(int rows, int cols, int levels)
{
 N = rows;
 M = cols;
 Q = levels;
} 
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::setPixelVal(int i, int j, pixelType val)
{
 pixelValue[i][j] = val;
}
//------------------------------------------------------------------------------
template <class pixelType>
void ImageType<pixelType>::computeAvgGrayLevel(const
						   ImageType<pixelType> &object)
{
	pixelType sum;
	sum = 0;

	for(int i = 0; i < object.N; i++)
		for(int j = 0; j < object.M; j++)
			sum = sum + object.pixelValue[i][j];
	sum = sum/(object.N*object.M);

	cout << "The average gray level is: " << sum << endl;
}
//------------------------------------------------------------------------------
template<class pixelType>
ImageType<pixelType> ImageType<pixelType>::enlargeImage(int e,
												ImageType<pixelType> &object)
{
	int i,j,k; 
	//temp to contain all of object just incase
	ImageType<pixelType> temp (N, M, Q); 
	//temp2 needs to be a factor of (e) larger than the older
	ImageType<pixelType> temp2(N*e, M*e, Q);
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			temp.pixelValue[i][j]=object.pixelValue[i][j]; //populate temp
		}
	}

	for(i=0; i< N*e; i++)
	{
		for(j=0; j< M*e; j++)
		{	//going through every element of object
			temp2.pixelValue[i][j]=object.pixelValue[i/e][j/e]; 
									    //putting it into temp 2, "i/e" & N*e" 
									    //are walking through and putting it in 
									    //like Prof. Bebis's example
		}		
	}
return (temp2);
}
//------------------------------------------------------------------------------
template<class pixelType>//s is shrink factor
ImageType<pixelType> ImageType<pixelType>::shrinkImage(int s,
												ImageType<pixelType> &object)
{

//NOTE a lot of this is not needed after, but was put in because object is
//passed by refrence

	int i,j,k;

	ImageType<pixelType> temp(N, M, Q);

	ImageType<pixelType> temp2(N/s, M/s, Q);

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			temp.pixelValue[i][j]=object.pixelValue[i][j]; //populate temp
		}
	}

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			object.pixelValue[i][j]=0; // zero out object
		}
	}

	for(i=0; i<N; i+=s)
	{
		for(j=0; j<M; j+=s)
		{	//go through every other of object and populate it from temp	
			object.pixelValue[i/s][j/s]=temp.pixelValue[i][j]; 
		}		
	}

	for(i=0; i<N; i+=s)
	{
		for(j=0; j<M/s; j+=s)
		{		
			object.pixelValue[i/s][j/s]=temp.pixelValue[i][j]; //getting y values
		}	
	}

	for(i = 0; i < (N/s)-1 ; i++)
	{
		for(j = 0; j < (M/s)-1; j++)
		{	// setting it to temp2 to be returned
			temp2.pixelValue[i][j]=object.pixelValue[i][j];
		}
	}
	return(temp2);
}
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::getSubImage(int ULr,int ULc, int LRr,int LRc,
{
	ImageType<pixelType> temp(N, M, Q);//declare a temp image object
	int i = 0, j = 0;			//counter variables

	//assign existing image to a temp object
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			temp.pixelValue[i][j]=object.pixelValue[i][j];
		}
	}

	//reset all existing pixels to 0
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			object.pixelValue[i][j]=0;
		}
	}

	//copy the original values from the temp object back into the original obj.
	for(i = ULr; i <= LRr ; i++)
	{
		for(j = ULc; j <= LRc; j++)
		{
			object.pixelValue[i][j]=temp.pixelValue[i][j];
		}
	}
}
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::negateImage(ImageType<pixelType> &object)
{
	for(int i = 0; i < object.N; i++)
		for(int j = 0; j < object.M; j++)
		object.pixelValue[i][j] = ((object.pixelValue[i][j])*-1) + 255;
}
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::reflectImage(ImageType<pixelType> &object)
{
	int i = 0, j = 0, H = 0, V = 0;
	ImageType temp(N, M, Q);
	char axis;

	//assign existing image to a temp object
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			temp.pixelValue[i][j]=object.pixelValue[i][j];
		}
	}

	//reset all existing pixels to 0
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			object.pixelValue[i][j]=0;
		}
	}
	cout << "Would you like to reflect your image (V)ertically (about the ";
	cout << "X-axis) or (H)orizontally (about the Y-axis)?";
	cin >> axis;

	switch(axis)
	{

	case 'H':
	case 'h':

	//reflect temp object about Y axis
	for(i = 0; i < N ; i++)
		{
			for(j = M -1 ; j >= 0; j--)
				{
					object.pixelValue[i][H] = temp.pixelValue[i][j];
					H++;
				}
			H = 0;
		}		

	break;

	case 'V':
	case 'v':

	//reflect temp object about X axis
	for(j = 0; j < M-1 ; j++)
		{
			for(i = N-1 ; i >= 0; i--)
				{
					object.pixelValue[V][j] = temp.pixelValue[i][j];
					V++;
				}
			V = 0;
		}		
	break;
	}
}
//------------------------------------------------------------------------------
template<class pixelType>
ImageType<pixelType> ImageType<pixelType>::translateImage(int t,
												ImageType<pixelType> &object)
{
	int i,j,k;
	ImageType<pixelType> temp(N, M, Q);

	pixelType transval; //value to be assigned to temp

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			temp.pixelValue[i][j]=object.pixelValue[i][j];//assign object to temp
		}
	}

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			object.getPixelVal(i,j,transval); //get transval at i and j
		        if((i + t < N) && (j + t < M))  // out of bounds check
			temp.setPixelVal(i + t, j + t, transval); //set at trasnlated value
		}
	}

	return(temp);
}
//------------------------------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::rotateImage(float theta,
												ImageType<pixelType> &object)
{
	int N, M, Q, R, C;	//new row and column containers
	int Xc, Yc;				//new center coordinates

	object.getImageInfo(N, M, Q);

	Xc = (int)(N/2 + 0.5);//X-coordinate integer center of image
	Yc = (int)(M/2 + 0.5);//Y-coordinate integer center of image

	ImageType temp(N, M, Q);//declare an image type object

	//assign existing image to a temp object
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			temp.pixelValue[i][j] = object.pixelValue[i][j];
		}
	}

	//reset all existing pixels to 0
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			object.pixelValue[i][j] = 0;
		}
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			{	//calculate the row coordinate
				R = Xc + int(((i - Xc)*(cos(theta))-(j-Yc)*(sin(theta))) + 0.5);
				//calculate the column coordinate
				C = Yc + int(((i - Xc)*(sin(theta))+(j-Yc)*(cos(theta))) + 0.5);

				if(object.inBounds(R, C))//bounds check; out of bounds is black
						object.pixelValue[R  = N-1][C = M-1] = 0;
				//otherwise, re-populate the original image using new coords
				object.pixelValue[R][C] = temp.pixelValue[i][j];
			}
}
//------------------------------------------------------------------------------
template<class pixelType>
bool ImageType<pixelType>::inBounds(int R, int C)
{
	bool inBounds;	
	//check row and column bounds
	if((R < 0 || R > N - 1) || (C < 0 || C > M - 1))
		{
			return true;
		}
	else
		return false;
}
//Overlaoded = Operator---------------------------------------------------------
template<class pixelType>
void ImageType<pixelType>::operator= (const ImageType<pixelType>&object)
{
	cout << "\nEntering Overloaded = Operator..." << endl;
	
	for(int i = 0; i < N; i++) 	// deallocate the 2D array
		{
			delete [] pixelValue[i];// delete single column array of pointers
		}

	delete [] pixelValue;			// delete double pointer

	N = object.N;
	M = object.M;
	Q = object.Q;

	pixelValue = new pixelType* [N];//allocate a "single column" of pointers

	for(int i = 0; i < N; i++)//for each pointer in the single column...
		{
			pixelValue[i] = new pixelType[M];//allocate "a row" of elements
			for(int j = 0; j < M; j++)
				pixelValue[i][j] = object.pixelValue[i][j];
		}
 cout << " Departing Overloaded = Operator...\n" << endl;
}
//Overlaoded + Operator---------------------------------------------------------
template<class pixelType>
ImageType<pixelType> ImageType<pixelType>::operator +
												  (ImageType<pixelType> &object)
{
 cout << "\nEntering Overloaded + Operator..." << endl;

	ImageType<pixelType> temp(N, M, Q);
	float a = 0;

	cout << "Enter the influence factor (between 0 and 1) your original image ";
	cout << "should have on the second image: " << endl;

	cin >> a;

 for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		temp.pixelValue[i][j] = (((pixelValue[i][j])*a)+
											((object.pixelValue[i][j])*(1-a)));
	}
 cout << " Departing Overloaded + Operator...\n" << endl;

 return (temp);
}
//Overlaoded - Operator---------------------------------------------------------
template<class pixelType>
ImageType<pixelType> ImageType<pixelType>::operator -
												  (ImageType<pixelType> &object)
{
	cout << "\nEntering Overloaded - Operator..." << endl;
	ImageType<pixelType> temp(N, M, Q);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
//		  temp.pixelValue[i][j] = abs(pixelValue[i][j]-object.pixelValue[i][j]);
		  temp.pixelValue[i][j] = pixelValue[i][j] - object.pixelValue[i][j];
						
			if(temp.pixelValue[i][j] < 0)
			{
				temp.pixelValue[i][j] = temp.pixelValue[i][j]*(-1);
			}
		}
	}
	cout << "Departing Overloaded - Operator...\n" << endl;
	return (temp);
}
//Destructor--------------------------------------------------------------------
template<class pixelType>
ImageType<pixelType>::~ImageType()
{
 cout << "\nEntering Destructor..." << endl;

	N = M = Q = 0;						// deinitialize N, M & Q

   for(int i = 0; i < N; i++) 	// deallocation the 2D array
		{
			delete [] pixelValue[i];// delete "single column" of pointers
		}

	delete [] pixelValue;			// delete double pointer

 cout << " Departing Destructor...\n" << endl;
}
#endif
