#ifndef REGIONTYPE_H
#define REGIONTYPE_H

#include <cstdlib>

#include "PixelType.h"

class RegionType
public:
  int regionID;	
  int regionSize;
  float Xcentroid;
  float Ycentroid;
  PixelType pixelType;

  RegionType& operator= (RegionType&);	// Overload =