#ifndef REGIONTYPE_H
#define REGIONTYPE_H

#include <cstdlib>

//#include "PixelType.h"
#include "PixelList.h"

class RegionType
public:
  int regionID;	
  int regionSize;
  float Xcentroid;
  float Ycentroid;
//  PixelList<PixelType> pixelList;

  RegionType& operator= (RegionType&);	// Overload =