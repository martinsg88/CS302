#ifndef IMAGE_H
#define IMAGE_H

// a simple example - you would need to add more funtions

class ImageType {
 public:
   ImageType();
   ImageType(int, int, int);
   ImageType(const ImageType& rhs);//copy constructor
   void getImageInfo(int&, int&, int&);
   void setImageInfo(int, int, int);
   void setPixelVal(int, int, int);
   void getPixelVal(int, int, int&);
   void reflectImage(char, ImageType&); 
   void translateImage(int t, ImageType&);
   void rotateImage(double theta, ImageType&);
   void threshold(ImageType&,int);
   void displayHistogram(ImageType,ImageType&);
   void dilate(ImageType&);
   void erode(ImageType&);
   bool inBounds(int, int);

   


 private:
   int N, M, Q;
   int **pixelValue;
};

#endif

