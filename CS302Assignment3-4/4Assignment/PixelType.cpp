#include "PixelType.h"
#include <cstdlib>

//Default Constructor-----------------------------------------------------------
//{
//		In-line
//}
//Overlaoded = Operator for int-------------------------------------------------
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
