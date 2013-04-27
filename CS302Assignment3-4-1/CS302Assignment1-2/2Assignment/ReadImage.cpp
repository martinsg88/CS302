#include <iostream>
#include <fstream>
#include <cstdlib>

#include "image.h"
#include "RGB.h"

using namespace std;

//Read Grayscale Image----------------------------------------------------------
void readImage(char fname[], ImageType<int>& image)
{
 cout << "Reading grayscale image...\n";

 int i, j;
 int N, M, Q;
 unsigned char *charImage;
 char header [100], *ptr;
 ifstream ifp;

 ifp.open(fname, ios::in | ios::binary);

 if (!ifp)
 {
   cout << "Can't read image: " << fname << endl;
   exit(1);
 }

// read header, test for 'P5'
 ifp.getline(header,100,'\n');
 if ((header[0]!=80) || (header[1]!=53) )
	{   
		cout << "Image " << fname << " is not PGM" << endl;
		exit(1);
	}

ifp.getline(header,100,'\n');
 while(header[0]=='#')
   ifp.getline(header,100,'\n');

 M=strtol(header,&ptr,0);
 N=atoi(ptr);

 ifp.getline(header,100,'\n');
 Q=strtol(header,&ptr,0);

 charImage = (unsigned char *) new unsigned char [M*N];

 ifp.read( reinterpret_cast<char *>(charImage), (M*N)*sizeof(unsigned char));

 if (ifp.fail())
 {
	cout << "Image " << fname << " has wrong size" << endl;
	exit(1);
 }

 ifp.close();

 // Convert the unsigned characters to integers

 int val;

 for(i=0; i<N; i++)
   for(j=0; j<M; j++)
		{
			val = (int)charImage[i*M+j];
			image.setPixelVal(i, j, val);     
		}

 delete [] charImage;

 cout << "Grayscale image read...\n";
 //return (1);
}

//Read Color Image--------------------------------------------------------------
void readImage(char fname[], ImageType<RGB>& image)
{
 cout << "Reading color image...\n";

 int i, j;
 int N, M, Q;
 unsigned char *charImage;
 char header [100], *ptr;
 ifstream ifp;

 ifp.open(fname, ios::in | ios::binary);
  
 if (!ifp) {
   cout << "Can't read image: " << fname << endl;
   exit(1);
 }

// read header, test for 'P6'

 ifp.getline(header,100,'\n');

 if ( (header[0]!=80) || (header[1]!=54) )
	{
		cout << "Image " << fname << " is not PPM" << endl;
		exit(1);
	}

 ifp.getline(header,100,'\n');
 while(header[0]=='#')
   ifp.getline(header,100,'\n');

 M=strtol(header,&ptr,0);
 N=atoi(ptr);
 
 ifp.getline(header,100,'\n');
 Q=strtol(header,&ptr,0);

 charImage = (unsigned char *) new unsigned char [3*M*N];

 ifp.read( reinterpret_cast<char *>(charImage), (3*M*N)*sizeof(unsigned char));

 if (ifp.fail())
	{
		cout << "Image " << fname << " has wrong size" << endl;
		exit(1);
	}

 ifp.close();
 
 // Convert the unsigned characters to integers

 RGB value;
 
 for(i=0; i < N; i++)
  for(j=0; j < 3*M; j+=3)
	{
		value.R = (int)charImage[i*3*M+j];
		value.G = (int)charImage[i*3*M+j+1];
		value.B = (int)charImage[i*3*M+j+2];
		image.setPixelVal(i, j/3, value);
  }
 cout << "Color image read...\n";
delete [] charImage;

}

