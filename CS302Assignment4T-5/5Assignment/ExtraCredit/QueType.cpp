#include "QueType.h"
#include <cstddef>                 // For NULL
#include <new>                     // For bad_alloc

// Class constructor------------------------------------------------------------
QueType::QueType()
{
  front = NULL;
  rear = NULL;
}
//------------------------------------------------------------------------------
void QueType::MakeEmpty()
{
  QNode* tempPtr;

    while (front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  rear = NULL;
}
//------------------------------------------------------------------------------
bool QueType::IsFull() const
{
  QNode* location;
  try
  {
    location = new QNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc)
  {
    return true;
  }
}
//------------------------------------------------------------------------------
bool QueType::IsEmpty() const
{
  return (front == NULL);
}
//------------------------------------------------------------------------------
void QueType::Enqueue(ItemType newItem)
{
  if (IsFull())
    throw FullQueue();
  else
  {
    QNode* newNode;

    newNode = new QNode;
    newNode->info = newItem;
    newNode->next = NULL;
    if (rear == NULL)
      front = newNode;
    else
      rear->next = newNode;
    rear = newNode;
  }
}
//------------------------------------------------------------------------------
void QueType::Dequeue(ItemType& item)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    QNode* tempPtr;

    tempPtr = front;
    item = front->info;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete tempPtr;
  }
}
//------------------------------------------------------------------------------
QueType::QueType (const QueType& anotherQue)
{
  QNode* ptr1;
  QNode* ptr2;
  
  if (anotherQue.front == NULL)
    front = NULL;
  else
  {
    front = new QNode;
    front->info = anotherQue.front->info;
    ptr1 = anotherQue.front->next;
    ptr2 = front;
    while (ptr1 != NULL)
    {
      ptr2->next = new QNode;
      ptr2 = ptr2->next;
      ptr2->info = ptr1->info;
      ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
    rear = ptr2;
  }    
}
// Class destructor-------------------------------------------------------------
QueType::~QueType()
{
  MakeEmpty();
}
