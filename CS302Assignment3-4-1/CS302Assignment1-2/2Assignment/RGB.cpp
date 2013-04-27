//RGB.cpp

#include <cstdlib>
#include <iostream>
#include <math.h>
#include "RGB.h"

using namespace std;

//Default Constructor-----------------------------------------------------------
RGB::RGB()
{
	R = 0;
	G = 0;
	B = 0;
}
//Copy Constructor--------------------------------------------------------------
RGB::RGB(RGB& object)
{
	R = object.R;
	G = object.G;
	B = object.B;
}
//Parameter Constructor---------------------------------------------------------
RGB::RGB(int tmpR, int tmpG, int tmpB)
{
	R = tmpR;
	G = tmpG;
	B = tmpB;
}
//Overlaoded = Operator for int-------------------------------------------------
void RGB::operator=(int i)
{
	R = i;
	G = i;	
	B = i;
	
//	return(*this);
}
//Overlaoded = Operator for RGB Type--------------------------------------------
RGB& RGB::operator=(RGB& object)
{
	R = object.R;
	G = object.G;	
	B = object.B;
	
	return(*this);
}

//Overlaoded + Operator for RGB Type--------------------------------------------
RGB& RGB::operator+(RGB object)
{
	R = R + object.R;
	G = G + object.G;	
	B = B + object.B;

	return (*this);
}
//Overlaoded + Operator for int-------------------------------------------------
RGB& RGB::operator+ (int p)
{
	R = R + p;
	G = G + p;	
	B = B + p;
	
	return (*this);
}
//Overlaoded - Operator for int-------------------------------------------------
RGB& RGB::operator-(int s)
{

	R = R - s;
	G = G - s;
	B = B - s;

	return (*this);
}
//Overlaoded - Operator for RGB Type--------------------------------------------
RGB& RGB::operator-(RGB object)
{
	R = R - object.R;
	G = G - object.G;	
	B = B - object.B;
	
	return (*this);
}
//Overlaoded * Operator for RGB Type--------------------------------------------
RGB& RGB::operator*(RGB object)
{
	R = R*object.R;
	G = G*object.G;	
	B = B*object.B;
	
	return (*this);
}
//Overlaoded * Operator for int-------------------------------------------------
RGB& RGB::operator*(int m)
{
	R = R*m;
	G = G*m;	
	B = B*m;
	
	return (*this);
}
//Overlaoded * Operator for float-----------------------------------------------
RGB& RGB::operator*(float f)
{
		R = int(R*f);
		G = int(G*f);	
		B = int(B*f);
	
	return (*this);
}
//Overlaoded / Operator for int-------------------------------------------------
RGB& RGB::operator/(int d)
{
	R = R/d;
	G = G/d;	
	B = B/d;
	
	return (*this);
}
//I/O stream overloads----------------------------------------------------------
//Ostream overlaod--------------------------------------------------------------
ostream & operator<< (ostream &ostrm, const RGB& object)
{
	ostrm << "\nRed pixel value is: " << object.R << endl;
	ostrm << "Green pixel value is: " << object.G << endl; 
	ostrm << "Blue pixel value is: " << object.B;

	return (ostrm);
}
//Istream overload--------------------------------------------------------------
istream & operator>> (istream &istrm, RGB& object)
{
	cout << "\nEnter Red pixel value: ";
	istrm >> object.R;
	
	
	cout << "Enter Green pixel value: ";
	istrm >> object.G; 
	
	
	cout << "Enter Blue pixel value: ";
	istrm >> object.B;
	

	return (istrm);
}
//------------------------------------------------------------------------------
bool RGB:: operator < (int zero)
{
	if(R < 0)
	{
		R = R*(-1);
	}
	if(G < 0)
	{
		G = G*(-1);
	}
	if(B < 0)
	{
		B = B*(-1);
	}

	return(false);
}
//------------------------------------------------------------------------------
bool RGB:: operator < (float llimit)
{
	if(R < llimit)
	{
		return (true);
	}
	else if(G < llimit)
	{
		return (true);
	}
	else if(B < llimit)
	{
		return (true);
	}
	else
	{
		return(false);
	}
}
//------------------------------------------------------------------------------
bool RGB:: operator > (float ulimit)
{
	if(R > ulimit)
	{
		return (true);
	}
	else if(G > ulimit)
	{
		return (true);
	}
	else if(B > ulimit)
	{
		return (true);
	}
	else
	{
		return(false);
	}
}
//Destructor--------------------------------------------------------------------
RGB::~RGB()
{
	R = 0;
	G = 0;
	B = 0;	
}
