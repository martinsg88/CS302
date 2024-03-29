#include <iostream>

using namespace std;

template <class ItemType>
class NodeType;

template <class ItemType>
class PixelList
{

public:
	PixelList();
	~PixelList();
	void MakeEmpty();
	void RetrieveItem(ItemType&, bool&);
	void InsertItem(ItemType);
	void ResetList();
	int  LengthIs();
	bool IsLastItem();
	void GetNextItem(ItemType&);
	void DeleteItem(ItemType);
private:
	NodeType<ItemType>* listData;
	NodeType<ItemType>* currentPos;
	int length;
};

template <class ItemType>
class RegionList
{

public:
	RegionList();
	~RegionList();
	void MakeEmpty();
	int LengthIs();
	void RetrieveItem(ItemType&, bool&);
	void InsertItem(ItemType);
	void DeleteItem(ItemType);
	void ByeTrash();
	void ResetList();
	bool IsLastItem();
	void GetNextItem(ItemType&);
	
private:
	NodeType<ItemType>* listData;
	NodeType<ItemType>* currentPos;
	int length;
};

template <class ItemType>
class NodeType
{

public:
	NodeType();//default constructor
	NodeType<ItemType>*  next;
	ItemType info;
};



//***** NODE CLASS ******//


//****** PIXEL LIST ******//
template <class ItemType>
PixelList<ItemType>::PixelList()
{
	listData = NULL;
	length = 0;
}

template <class ItemType>
PixelList<ItemType>::~PixelList()
{
	MakeEmpty();
}

template <class ItemType>
void PixelList<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* temp;
 
	while(listData != NULL) 
	{
		temp = listData;
		listData = listData->next;
		delete temp;
	}
 length=0;
}

template <class ItemType>
void PixelList<ItemType>::InsertItem(ItemType newitem)
{
	NodeType<ItemType>* location;
	
	location = new NodeType<ItemType>;
	location->info = newitem;
	location->next = listData;
	length++;

}

template <class ItemType>
void PixelList<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	NodeType<ItemType>* location;

	location = listData;
	found = false;
 
	while( (location != NULL) && !found)
	{

		if(item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
			location = location->next;
	}
}

template <class ItemType>
void PixelList<ItemType>::ResetList()
{
	currentPos = listData;
}

template <class ItemType>
int PixelList<ItemType>::LengthIs()
{
	return length;
}

template <class ItemType>
bool PixelList<ItemType>::IsLastItem()
{
	return (currentPos == NULL);
}

template <class ItemType>
void PixelList<ItemType>::GetNextItem(ItemType& item)
{
	item = currentPos->info;
	currentPos = currentPos->next;
}

template <class ItemType>
void PixelList<ItemType>::DeleteItem(ItemType item)
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* temp;
	
	if(item == listData->info)
	{
		temp = listData;
		listData = listData->next;
	}
	
	else
	{
		while(!(item == (location->next)->info))
			location = location->next;
		
		temp = location->next;
		location->next = temp->next;
	}
	
	delete temp;
	length--;
}
//****** PIXEL LIST ******//

//****** Region LIST *****//
template <class ItemType>
RegionList<ItemType>::RegionList()
{
	listData = NULL;
	length = 0;
}

template <class ItemType>
RegionList<ItemType>::~RegionList()
{
	MakeEmpty();
}

template <class ItemType>
void RegionList<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* temp;
 
	while(listData != NULL) 
	{
		temp = listData;
		listData = listData->next;
		delete temp;
	}
 length=0;
}

template <class ItemType>
void RegionList<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	NodeType<ItemType>* location;

	location = listData;
	found = false;

	while((location !=NULL) && !found)
	{
		if(location->info < item)
		{
			location = location->next;
		}		
		else if(location->info == item)
		{
				found = true;
				item = location->info;
		}
	else
		location = NULL;
	}
}

template <class ItemType>
void RegionList<ItemType>::InsertItem(ItemType newItem)
{
	NodeType<ItemType>* newNode;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* location;
	bool stop;

	stop = false;
	location = listData;
	predLoc = NULL;

	while (location !=NULL && !stop)
	{
		if (location->info < newItem)
		{
			predLoc = location;
			location = location->next;
		}
	
	else
		stop = true;
	}
	
	newNode = new NodeType<ItemType>;
	newNode->info = newItem;

	if(predLoc == NULL)
	{
		newNode->next = listData;
		listData = newNode;
	}

	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
}

template <class ItemType>
void RegionList<ItemType>::DeleteItem(ItemType item)
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* temp;
	
	if(item == listData->info)
	{
		temp = listData;
		listData = listData->next;
	}
	
	else
	{
		while(!(item == (location->next)->info))
			location = location->next;
		
		temp = location->next;
		location->next = temp->next;
	}
	
	delete temp;
	length--;
}
	
template <class ItemType>
void RegionList<ItemType>::ByeTrash() // gets rid of trash
{
	int trash = 30;
	NodeType<ItemType>* location = listData;

	while(location->size < trash)
	{
		listData = listData->next;
		delete location;
		location = listData;
		length--;
	}
}

template <class ItemType>
void RegionList<ItemType>::ResetList()
{
	currentPos = listData;
}

template <class ItemType>
int RegionList<ItemType>::LengthIs()
{
	return length;
}

template <class ItemType>
bool RegionList<ItemType>::IsLastItem()
{
	return (currentPos == NULL);
}

template <class ItemType>
void RegionList<ItemType>::GetNextItem(ItemType& item)
{
	item = currentPos->info;
	currentPos = currentPos->next;
}


//*** Garbage ***//
int main()
{
	return (1-1+2-2+4-4);
}
