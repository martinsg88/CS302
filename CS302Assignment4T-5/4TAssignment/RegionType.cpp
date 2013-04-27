#include "RegionType.h"
#include <cstdlib>

//Constructor-------------------------------------------------------------------
RegionType::RegionType()
{
	regionID = 0;
	regionSize = 0;
	Xcentroid = 0;	
	Ycentroid = 0;
}
//------------------------------------------------------------------------------
RegionType& RegionType::operator=(RegionType& regionObject)
{
	regionID = regionObject.regionID;
	regionSize = regionObject.regionSize;
	Xcentroid = regionObject.Xcentroid;
	Ycentroid = regionObject.Ycentroid;
}
//------------------------------------------------------------------------------
RegionType::~RegionType()
{
 	regionID = 0;
	regionSize = 0;
	Xcentroid = 0;
	Ycentroid = 0;
}
//------------------------------------------------------------------------------
