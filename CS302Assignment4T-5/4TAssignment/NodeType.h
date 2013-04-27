#ifndef NODETYPE_H
#define NODETYPE_H

#include "RegionType.h"
#include "PixelType.h"

template <class ItemType>
class NodeType
{
	public:
	ItemType info;
	NodeType<ItemType> *next;
};
#endif
