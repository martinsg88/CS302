#ifndef PIXELTYPE_H
#define PIXELTYPE_H

#include <cstdlib>

#include "NodeType.h"

class PixelType
public:
  int i;
  int j;

  PixelType& operator= (PixelType&);
#endif