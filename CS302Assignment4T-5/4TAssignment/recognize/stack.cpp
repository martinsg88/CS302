#include "stack.h"
#include <iostream>
using namespace std;


/***********************************************************************
Constructor
***********************************************************************/
stack::stack()       
{
        top='\0';//set top to null
}

/***********************************************************************
Copy Constructor
***********************************************************************/
stack::stack(const stack& rhs)      
{
        node* temp=rhs.top;
        node* ntemp;

        top=new node(temp->data,temp->next);
        ntemp=top;
        ntemp=ntemp->next;

        while(temp->next!='\0')
        {
                ntemp=new node(temp->data,temp->next);
                ntemp=ntemp->next;
                temp=temp->next;
        }
}
/***********************************************************************
Destructor
***********************************************************************/
stack::~stack()       
{
        clear();
}
/***********************************************************************
Push- puts new element onto the stack
***********************************************************************/
void stack::push(int temp)     
{
        top=new node(temp,top);
}
/***********************************************************************
Pop-takes the top element off the top of the stack
***********************************************************************/
void stack::pop(int& item)      
{
     if(!isEmpty())
     {
        node* temp=top;
        item=top->data;
        top=top->next;
        delete temp;
     }
}
/***********************************************************************
Overloaded assignment operator 
***********************************************************************/
void stack::operator=(const stack& rhs)    
{
        node* temp=rhs.top;
        node* ntemp;

        top=new node(temp->data,temp->next);
        temp=temp->next;
        ntemp=top->next;

        while(temp->next!='\0')
        {
            ntemp=new node(temp->data,temp->next);
            ntemp=ntemp->next;
            temp=temp->next;
        }

}

/***********************************************************************
Is Empty Function- Returns empty if top is equil to NULL 
***********************************************************************/
bool stack::isEmpty()          
{
        if(top=='\0')
	 return true;
        else 
	 return false;
}

/***********************************************************************
Is Full- Always returns false
***********************************************************************/
bool stack::isFull()   
{
        return false;
}

/***********************************************************************
Clear- Clears the stack by deleting the elements in it 
***********************************************************************/
void stack::clear()    
{
        node* tempNext;
        while(top!='\0')
        {
            tempNext=top->next;
            delete top;
            top=tempNext;
        }
        
}


/***********************************************************************
Node Constructor- with two parameters 
***********************************************************************/
node::node(int tmp,node* t)  
{
        data=tmp;
        next=t;
        t='\0';
}

/***********************************************************************
Node Default Constructor
***********************************************************************/
node::node()
{
         data='\0';
         next='\0';                      
}
