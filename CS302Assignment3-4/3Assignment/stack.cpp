#include <iostream>

using namespace std;


class stacktype
{
	friend class nodetype;
	
	public:
		
		stacktype();
		~stacktype();
		void push(int&,int&);
		void pop(int&, int&);
		void makeEmpty();
		bool isEmpty();
		bool isFull();
		
	private:
		nodetype* top;
	
};

class nodetype
{
	friend class stacktype;
	friend class queuetype;
	
	public:
//		nodetype();
//		~nodetype();
//		nodetype(int,int,nodetype*);
		int i;
		int j;
		nodetype *next;
};
/*nodetype::notetype()
{
	
	
}
nodetype::~nodetype()
{

}
nodetype::nodetype(int a, int b, nodetype* anode)
{

}*/
stacktype::stacktype()
{
	top = NULL;
}
stacktype::~stacktype()
{
	top = NULL;
	delete []top;
}
void stacktype::push(int& pushi, int& pushj)
{
	nodetype* newnode;
	newnode = new nodetype;
	
	newnode->i = pushi;
	newnode->j = pushj;
	
	newnode->next = top;

	top = newnode;
}
void stacktype::pop(int& popi, int& popj)
{
	nodetype* newnode;
	
	popi = top->i;
	popj = top->j;
	
	newnode = top;
	top = top->next;
	
	delete newnode;
}
bool stacktype::isEmpty()
{
	return(top == NULL);
}
bool stacktype::isFull()
{
	nodetype *location;
	
	location = new nodetype;
	
	if(location == NULL)
		return true;
	else
		delete location;
		return false;
}
int main()
{
	return 0+1-1;
}
	
	
	
	