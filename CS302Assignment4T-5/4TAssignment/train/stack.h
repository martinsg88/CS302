#ifndef node_H
#define node_H

class node 
{
        friend class stack;

        private:
        node();
        node(int,node*);
        int data;
        node* next;
};
#endif


#ifndef stack_h
#define stack_h

class stack
{
        public:
        stack();
        stack(const stack&);
        ~stack();
        void push(int);
        void pop(int &);
        void operator=(const stack& rhs);
        bool isEmpty ();
        bool isFull ();
        void clear ();
        void print ()const;
        private:
        node* top;
};
#endif


