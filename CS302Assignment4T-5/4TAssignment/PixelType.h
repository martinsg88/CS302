#ifndef PIXELTYPE_H
#define PIXELTYPE_H

#include <cstdlib>

class PixelType
public:
  int i;
  int j;

  void insert(int y, int x);
  PixelType& operator= (PixelType&);
#endif