#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "image.h"
using namespace std;

ImageType::ImageType()
{
 N = 0;
 M = 0;
 Q = 0;

 pixelValue = NULL;
}

ImageType::ImageType(int tmpN, int tmpM, int tmpQ)
{
 int i, j;

 N = tmpN;
 M = tmpM;
 Q = tmpQ;

 pixelValue = new int* [N];
 for(i=0; i<N; i++) {
   pixelValue[i] = new int[M];
   for(j=0; j<M; j++)
     pixelValue[i][j] = 255; 

 }
}
bool ImageType::inBounds(int r, int c)
{
	return(r<N-1&&c<M-1&&r>=1&&c>=1);
}

ImageType::ImageType(const ImageType& rhs)//copy constructor
{

  N = rhs.N;
  M = rhs.M;
  Q = rhs.Q;

 pixelValue =new int* [N];
 for(int i=0; i<N; i++) {
   pixelValue[i] = new int[M];
   for(int j=0; j<M; j++)
   {
     pixelValue[i][j] = rhs.pixelValue[i][j];
   }
 }



}
 
void ImageType::getImageInfo(int& rows, int& cols, int& levels)
{
 rows = N;
 cols = M;
 levels = Q;
} 

void ImageType::setImageInfo(int rows, int cols, int levels)
{
 N= rows;
 M= cols;
 Q= levels;
} 

void ImageType::setPixelVal(int i, int j, int val)
{
 pixelValue[i][j] = val;
}

void ImageType::getPixelVal(int i, int j, int& val)
{
 val = pixelValue[i][j];
}

void ImageType::reflectImage(char var, ImageType& image)
{
 int a,b,c;
 image.getImageInfo(a,b,c);
 ImageType tmpImage(a,b,c);
 int k=0,l=0;

 tmpImage.pixelValue = new int* [N];
 for(int i=0; i<N; i++) {
   tmpImage.pixelValue[i] = new int[M];
   for(int j=0; j<M; j++){
     tmpImage.pixelValue[i][j] = image.pixelValue[i][j];
   }
 }

if(var == 'v')
{
//flip vertical 
 for(int i=0;i<N;i++)
 {
  l=(N-1)-i;

  tmpImage.pixelValue[i]=image.pixelValue[l];
 }
 image=tmpImage;
}

else if(var =='h')
{
//flip horizontal
 for(int i=0; i<N; i++) {
   for(int j=0; j<M; j++){
     k=(M-1)-j;

     tmpImage.pixelValue[i][j] = image.pixelValue[i][k]; 
    }
  }
image= tmpImage;
}


 
}


void ImageType::translateImage(int t, ImageType& image)
{
 int a,b,e;
 image.getImageInfo(a,b,e);
 ImageType tmpImage(a,b,e);
 int k=0,l=0;

 tmpImage.pixelValue = new int* [N+t];
 for(int i=0; i<N; i++) {
   tmpImage.pixelValue[i] = new int[M +t];
   for(int j=0; j<M; j++){
     tmpImage.pixelValue[i][j] = image.pixelValue[i][j];
   }
 } 
 int r=0,c=0;
  
 for(int i=0; i<N; i++) {
   for(int j=0; j<M; j++){
     c=t+j;
     tmpImage.pixelValue[i][j] = image.pixelValue[i][c]; 
    }
  }
image= tmpImage;
}

void ImageType::rotateImage(double theta, ImageType& image)
{
 const double pi=3.14;
 
 theta = (theta*pi)/180.0;//convert degrees to radians
 int r=0,c=0;
 int a,b,e;
 image.getImageInfo(a,b,e);
 ImageType tmpImage(a,b,e);
 int k=0,l=0;

 tmpImage.pixelValue = new int* [N];
 for(int i=0; i<N; i++) {
   tmpImage.pixelValue[i] = new int[M];
   for(int j=0; j<M; j++){
     tmpImage.pixelValue[i][j] = image.pixelValue[i][j];
   }
 } 

 for(int i=0; i<N; i++) {
   for(int j=0; j<M; j++){
     c= i*sin(theta)-j*cos(theta);
     c=ceil(c);//rounds up the double

     tmpImage.pixelValue[i][j] = image.pixelValue[i][c]; 
    }
  }
 image= tmpImage;

}

void ImageType::threshold(ImageType& image,int threshold)
{
 int i,j;

 for(i=0; i<N; i++) {
   for(j=0; j<M; j++){
     if(image.pixelValue[i][j]>=threshold)
       image.pixelValue[i][j]=255;
 	else
	  image.pixelValue[i][j]=0;  
   }
 }
}

void ImageType::displayHistogram(ImageType image,ImageType& histogram)
{
 double c,c1;
 int i,j,k,value;
 int counter[255];//counter array 
 char f;

histogram.N= 509;
histogram.M=509;
histogram.Q=255;

 
//initalizes histo gram picture to 0 
 histogram.pixelValue = new int* [histogram.N];
 for(i=0; i<histogram.N; i++) {
   histogram.pixelValue[i] = new int[histogram.M];
   for(j=0; j<histogram.M; j++){
     histogram.pixelValue[i][j] = 0;
   }
 }

 for (i=0;i<255;i++)
   counter[i] =0;//initialize the counter array

//for loops to get frequency of pixel values 
 for(i=0; i<N; i++) {
   for(j=0; j<M; j++){ 
      value = image.pixelValue[i][j];
      counter[value] = 1+counter[value];
   }
 }

//finds max pixel freq
int max_c=0;
for(i=0;i<255;i++)
{
 if(max_c<counter[i])
   max_c=counter[i];
}  

for(i=0;i<255;i++)
{
   c1=counter[i];
   c= (c1/max_c)*500;
   c=ceil(c);//rounds up the normalized pixel freq
   counter[i]=c;
}  
k=0;
 //creates the histogram image
 for(j=0;j<255;j++){
   for(i=0; i<counter[k]; i++){
	histogram.pixelValue[i][j]=255;
        
    } 
     k++;//step through the counter array
 }
}

void  ImageType::dilate(ImageType& image)
{
  int i,j,val,finVal;


  for(i=0;i<230;i++){
    for(j=0;j<320;j++){
 
//checks all the positive surrounding values, seg falts with negative
     if(image.pixelValue[i][j]==255     || 
        image.pixelValue[i+1][j+1]==255 ||
        image.pixelValue[i+1][j]==255 ||
        image.pixelValue[i][j+1]==255)
        finVal = 255;
     else 
	finVal=0;
    
      image.pixelValue[i][j]=finVal;

    }
  }
}

void ImageType::erode(ImageType& image)
{
  int i,j,val,finVal;


  for(i=0;i<230;i++){
    for(j=0;j<320;j++){
 
//checks all the positive surrounding values, seg falts with negative
     if(image.pixelValue[i][j]==0     || 
        image.pixelValue[i+1][j+1]==0 ||
        image.pixelValue[i+1][j]==0 ||
        image.pixelValue[i][j+1]==0)
        finVal = 0;
     else 
	finVal=255;
 
      image.pixelValue[i][j]=finVal;

   }
  }
}
