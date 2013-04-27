#ifndef PIXELTYPE_H
#define PIXELTYPE_H

#include <cstdlib>

class PixelType{
public:
  int i;
  int j;
  PixelType() {i = 0; j = 0; };  // In-line Constructor
  void insert(int y, int x);
  PixelType& operator= (PixelType&);  ~PixelType() {i = 0; j = 0; }; // In-line Destructor};
#endif
