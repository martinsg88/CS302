#ifndef node_H
#define node_H

class node
{
        friend class queue;

        private:
        node();
        node(int,node*);
        int data;
        node* next;
};
#endif

#ifndef queue_h
#define queue_h

class queue
{
 public:
    queue();
    ~queue();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(int);
    void Dequeue(int&);
 private: 
    node* qFront;
    node* qRear;
}; 
#endif

