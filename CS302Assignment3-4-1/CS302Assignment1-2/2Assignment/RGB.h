//RGB.h

#ifndef RGB_H
#define RGB_H

//#include <iostream>
//#include <cstdlib>

using namespace std;
class RGB;
ostream &operator<< (ostream &, const RGB&);
istream &operator>> (istream &, RGB&);

class RGB
{

public:

   int R;
   int G;
   int B;

   //constructors	
   RGB();				//Default Constructor
   RGB(int, int, int);	//Parameter Constructor
   RGB(RGB&);			//Copy Constructor
 
	//Overloaded operators
	void operator=(int);
	RGB& operator=(RGB&);
	RGB& operator+(RGB);
	RGB& operator+(int);
	RGB& operator-(int);
	RGB& operator-(RGB);
	RGB& operator*(int);
	RGB& operator*(float);
	RGB& operator*(RGB);
	RGB& operator/(int);
	bool operator<(int);
	bool operator<(float);
	bool operator>(float);

	friend ostream &operator<< (ostream &, const RGB&);
	friend istream &operator>> (istream &, RGB&);

	//destructor
	~RGB();

};
#endif
