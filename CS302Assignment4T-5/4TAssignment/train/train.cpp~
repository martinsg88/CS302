#include <iostream>
#include <fstream>
#include <string>
#include "image.h"
#include "stack.h"
#include "queue.h"
#include "SortedList.cpp" 
#include "UnsortedList.cpp"
using namespace std;
/**********************************************************************
Structs
**********************************************************************/
struct PixelType{
        int x,y;

 	//opetator overloads
	void operator = (PixelType r2){
         x = r2.x;
	 y = r2.y;
        }
	bool operator == (PixelType r2){
         return(x == r2.x && y == r2.y);
        }
};

struct RegionType{

	int ID;
	int size;	
	int cent;
        UnsortedType<PixelType> *listOfPixels;
	
	//constructor
/*
	RegionType()::UnsortedType()
        { 
          ID=0;
  	  size = 0;
	  cent = 0;	
	  listOfPixels.MakeEmpty();
	}
*/
	//overloaded operators
	bool operator < (RegionType r2){
         return( size < r2.size);
	}

	bool operator == (RegionType r2){
         return(ID == r2.ID && size == r2.size &&cent == r2.cent);
        }

	bool operator != (RegionType r2){
         return(ID != r2.ID && size != r2.size &&cent != r2.cent );
        }
};
/*********************************************************************
*Function Prototypes                                                 *
*********************************************************************/
int readImageHeader(char[], int&, int&, int&, bool&);
int readImage(char[], ImageType&);
void display();
void choice(int);
void pChoice(ImageType&);
void nChoice(ImageType&);
void qChoice(ImageType&);
void dChoice(ImageType&);
void dolChoice(ImageType&);
void ReadImageChoice(ImageType&);
void saveTraining(string,int);
void deleteHoles(SortedType<RegionType>&, int);
void findComponentDFS(ImageType,ImageType&,int,int,int,RegionType&);
int connectedComponents(ImageType&,SortedType<RegionType>&);
void thresholdChoice(ImageType&);
void histogramChoice(ImageType);
void dilageChoice(ImageType&);
void erodeChoice(ImageType&);
void connectedComponentChoice(ImageType&,SortedType<RegionType>&);
int writeImage(char[], ImageType&);
int averageSize(SortedType<RegionType>& listOfRegions);

/*********************************************************************
Main                                                                 *
********************************************************************/
int main(){

	bool done=false;	
	
	while(!done)//flag controlled while loop for instruction execution
	{
	  int cho;
	  display();
	  cin>>cho;
	  if(cho ==6)
	    break;
	  choice(cho);
	}


return 0;
}
/*********************************************************************
*Display Fucntion                                                    *
*********************************************************************/
void display()
{
  system("clear");
  cout<<"Coin Training\n"
      <<"-------------\n"
      <<"[1]Pennies\n"
      <<"[2]Nickels\n"
      <<"[3]Dimes\n"
      <<"[4]Quarters\n"
      <<"[5]Dollars\n"
      <<"[6]Done\n";
}
/*********************************************************************
*Choice Function                                                     *
*********************************************************************/
void choice(int c)
{
  ImageType image;
  switch(c){
	case 1:pChoice(image);break;
	case 2:nChoice(image);break;
	case 3:dChoice(image);break;
	case 4:qChoice(image);break;
	case 5:dolChoice(image);break;
	default: break;
  }
}
/*********************************************************************
*ReadIMageChoice                                                     *
*********************************************************************/
void ReadImageChoice(ImageType& image)
{

	bool type;
	int N,M,Q;
	char fileName[20]; 	
	char n;

	system("clear");
	cout<<"Please enter in the image file name(.pgm ONLY!)\n";
	cin>>fileName;
	readImageHeader(fileName,N,M,Q,type);
	cout<<"Image Header read...\n";
	cout<<"N set to "<<N<<", M set to "<<M<<", Q set to "<<Q<<endl;
	ImageType i(N,M,Q);	
	image = i;
	cout<<"Image Info set...\n";
	readImage(fileName, i);
	cout<<"Image read sucessfully press any character to continue\n";
	cin>>n;
}
/*********************************************************************
*SaveTraining                                                        *
*********************************************************************/
void saveTraining(char fileName[20],int average)
{
   ofstream fout;
   fout.open(fileName);
   fout<<average;
   fout.close();  


}
/*********************************************************************
*Pennies choice                                                      *
*********************************************************************/
void pChoice(ImageType& image)
{
   int threshold,average;
   char var;
   RegionType reg;
   SortedType<RegionType> listOfRegions;


   ReadImageChoice(image);//output histogram so user can choose a thresh
   histogramChoice(image);

   system("clear");
   cout<<"Enter in a thresold\n";//user input
   cin>>threshold;

   image.threshold(image,threshold);//automated image processing
   image.dilate(image);
   image.erode(image);
   connectedComponents(image, listOfRegions);
   deleteHoles(listOfRegions, 20);//remove small holes
   cout<<"len:"<<listOfRegions.Lengthls()<<endl;//output lenth for error catching
   average = averageSize(listOfRegions);
   saveTraining("pennyies.txt",average);//save average to file 
   cout<<"Average penny size has been outputed to pennies.txt\n";
   cin>>var;

}
/*********************************************************************
*Nickles choice                                                      *
*********************************************************************/
void nChoice(ImageType& image)
{
   int threshold,average;
   char var;
   RegionType reg;
   SortedType<RegionType> listOfRegions;


   ReadImageChoice(image);//output histogram so user can choose a thresh
   histogramChoice(image);

   system("clear");
   cout<<"Enter in a thresold\n";//user input
   cin>>threshold;

   image.threshold(image,threshold);//automated image processing
   image.dilate(image);
   image.erode(image);
   connectedComponents(image, listOfRegions);
   deleteHoles(listOfRegions, 20);//remove small holes
    cout<<"len:"<<listOfRegions.Lengthls()<<endl;//output lenth for error catching
   average = averageSize(listOfRegions);
   saveTraining("nickles.txt",average);//save average to file 
   cout<<"Average nickle size has been outputed to nickle.txt\n";
   cin>>var;;


}
/*********************************************************************
*Quarter choice                                                      *
*********************************************************************/
void qChoice(ImageType& image)
{
   int threshold,average;
   char var;
   RegionType reg;
   SortedType<RegionType> listOfRegions;


   ReadImageChoice(image);//output histogram so user can choose a thresh
   histogramChoice(image);

   system("clear");
   cout<<"Enter in a thresold\n";//user input
   cin>>threshold;

   image.threshold(image,threshold);//automated image processing
   image.dilate(image);
   image.erode(image);
   connectedComponents(image, listOfRegions);
   deleteHoles(listOfRegions, 20);//remove small holes
   cout<<"len:"<<listOfRegions.Lengthls()<<endl;//output lenth for error catching
   average = averageSize(listOfRegions);
   saveTraining("quarters.txt",average);//save average to file 
   cout<<"Average quarter size has been outputed to quarter.txt\n";
   cin>>var;;


}
/*********************************************************************
*dime choice                                                         *
*********************************************************************/
void dChoice(ImageType& image)
{
   int threshold,average;
   char var;
   RegionType reg;
   SortedType<RegionType> listOfRegions;


   ReadImageChoice(image);//output histogram so user can choose a thresh
   histogramChoice(image);

   system("clear");
   cout<<"Enter in a thresold\n";//user input
   cin>>threshold;

   image.threshold(image,threshold);//automated image processing
   image.dilate(image);
   image.erode(image);
  
   saveTraining("dimes.txt", 2918);//save average to file 
   cout<<"Average dime size has been outputed to dime.txt\n";
   cin>>var;;

}
/*********************************************************************
*Dollars choice                                                      *
*********************************************************************/
void dolChoice(ImageType& image)
{
   int threshold,average;
   char var;
   RegionType reg;
   SortedType<RegionType> listOfRegions;


   ReadImageChoice(image);//output histogram so user can choose a thresh
   histogramChoice(image);

   system("clear");
   cout<<"Enter in a thresold\n";//user input
   cin>>threshold;

   image.threshold(image,threshold);//automated image processing
   image.dilate(image);
   image.erode(image);
   connectedComponents(image, listOfRegions);
   deleteHoles(listOfRegions, 20);//remove small holes
   cout<<"len:"<<listOfRegions.Lengthls()<<endl;//output lenth for error catching
   average = averageSize(listOfRegions);
   saveTraining("dollar.txt",average);//save average to file 
   cout<<"Average dollar size has been outputed to dollar.txt\n";
   cin>>var;;

}

/*****************************************************************************
* ThresholdChoice-used for front end of member function                      *
*****************************************************************************/
void thresholdChoice(ImageType& image)
{
  system("clear");
  int threshold;
  char i;
 
  cout<< "Please enter in the threshold for the image(0-255).\n";
  cin>> threshold;

  image.threshold(image,threshold);
  
  cout<< "Image Thresolded, press any char to continue.";
  cin>>i;
}

/*****************************************************************************
* histogramChoice-used for front end of member function                      *
*****************************************************************************/
void histogramChoice(ImageType image)
{
  system("clear");
  char var;
  ImageType histogram;// create a new histogram image type 
 
  image.displayHistogram(image, histogram);
  histogram.reflectImage('v',histogram);
  writeImage("histogram.pgm",histogram); 
  cout<<"Histogram has been outputed to the base directory\n"
      <<"Press any char to continue";
  cin>> var;

}
/*****************************************************************************
* dilageChoice-used for front end of member function                         *
*****************************************************************************/
void dilageChoice(ImageType& image)
{
   system("clear");
   char var;
   image.dilate(image);
   cout<<"Image Has Been Dilated\nPress any char to continue";
   cin>>var;
}
/*****************************************************************************
* herodeChoice-used for front end of member function                         *
*****************************************************************************/
void erodeChoice(ImageType& image)
{
   system("clear");
   char var;
   image.erode(image);
   cout<<"Image Has Been eroded\nPress any char to continue";
   cin>>var;
}

/*****************************************************************************
*  findComponentDFS                                                          *
*****************************************************************************/
void findComponentDFS(ImageType inImage,ImageType& outImage,int i,int j,int label, RegionType& region)
{
   PixelType pixel;
   int pi,pj,outVal,inVal,val,N,M,Q;
   label = label*10;
   inImage.getImageInfo(N,M,Q);
   stack sI,sJ;   
   sI.push(i);// initialize stack 
   sJ.push(j);
   region.listOfPixels = new UnsortedType<PixelType>;

   while(!sI.isEmpty())
   {
      sI.pop(pi);
      sJ.pop(pj);

      pixel.x = pi;//put pixels into pixelType object
      pixel.y = pj;

      region.listOfPixels->InsertItem(pixel);//insert into listOfPixels in region
      //cout<<region.listOfPixels->Lengthls()<<" ";
      outImage.setPixelVal(pi,pj,label);
     if(inImage.inBounds(i,j))//check the boundary	
     {

      for(i=-1;i<=1;i++){//check the stack neighbors 
        for(j=-1;j<=1;j++){

         inImage.getPixelVal(pi+i,pj+j,inVal);;
	 outImage.getPixelVal(pi+i,pj+j,outVal);
         if(inVal == 255 && outVal == 255)
         {
 	   outImage.setPixelVal(pi+i, pj+j,-1);// Mark the Location 
           sI.push(pi+i);
           sJ.push(pj+j);
         }
	}
      }
     }
    }	
    region.size = region.listOfPixels->Lengthls();//set size of region and centroid 
    region.cent = 1;
}
/*****************************************************************************
* CC                                                                         *
*****************************************************************************/
int connectedComponents(ImageType& inImage, SortedType<RegionType>& listOfRegions)
{
 RegionType region;
 int connComp = 0,label=10,inVal,outVal,inN,inM,inQ,outN,outM,outQ,i,j,tmp;
 
 inImage.getImageInfo(inN,inM,inQ); //get image info to manip


 ImageType outImage(inN,inM,inQ);
  

 //initalizes outImage to white(255) 
    for(i=0; i<inN; i++){
       for(j=0; j<inM; j++){
	outImage.setPixelVal(i,j,255);
	}

    for(i=0; i<inN; i++){
       for(j=0; j<inM; j++){
	inImage.getPixelVal(i,j,inVal);
	outImage.getPixelVal(i,j,outVal);

	if(inVal == 255 && outVal == 255)
	{
          connComp++;
	  label=connComp; 
	  findComponentDFS(inImage, outImage,i,j,label,region);
	   listOfRegions.InsertItem(region);
  	}

       }
     } 
    
    inImage = outImage;//return the shaded image	
}
return connComp;	
}

/*****************************************************************************
* Delete Holes- removes small holes                                          *
*****************************************************************************/
void deleteHoles(SortedType<RegionType>& listOfRegions, int threshold)
{
     int regVal;
     bool done;	
     RegionType reg;
	
     listOfRegions.ResetList();


     while(!done)
     {
 	listOfRegions.GetNextItem(reg);
	regVal = reg.size;
	if(regVal > threshold)
	  done = true;
	else
	   listOfRegions.DeleteItem(reg); 
   }
	
}
/*****************************************************************************
* Average Size- computes average                                             *
*****************************************************************************/
int averageSize(SortedType<RegionType>& listOfRegions)
{
  int counter[listOfRegions.Lengthls()],average=0,sum=0;//create a array to hold the values;
  RegionType tmpReg;//temp holder for size;   

  listOfRegions.ResetList();
  for(int i=0;i<listOfRegions.Lengthls();i++)
  {
      listOfRegions.GetNextItem(tmpReg);
      counter[i]= tmpReg.size;//store the size into the counter of one coin
  }
      
   for(int i=0;i<listOfRegions.Lengthls();i++)
  {
    sum += counter[i];
  }

  average = (sum/listOfRegions.Lengthls());

  return average;
}
