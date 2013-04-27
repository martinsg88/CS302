#include "PixelType.h"
#include <cstdlib>

//Default Constructor-----------------------------------------------------------
//{
//		In-line
//}
//Overlaoded = Operator for int-------------------------------------------------
void PixelType::insert(int y, int x)
{
	j = x;
	i = y;
}
//------------------------------------------------------------------------------
PixelType& PixelType::operator= (PixelType& object)
{
	i = object.i;
	j = object.j;

//	return(*this);	
}
//Default Destructor------------------------------------------------------------
//{
//		In-line
//}
