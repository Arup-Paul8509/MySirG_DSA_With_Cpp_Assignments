#include<iostream>
#include "DLL.cpp"
using namespace std;
class Deque: private DLL
{
    public:
        Deque(); //Constructor
        void insertFront(int);
        void insertRear(int);
        void delFront();
        void delRear();
        int getFront();
        int getRear();
        ~Deque();
        bool isEmpty();       
};
Deque::Deque():DLL(){}
void Deque::insertFront(int item)
{
    insertBeginning(item);
}
void Deque::insertRear(int item)
{
    insertAtEnd(item);
}
void Deque::delFront()
{
    delFirst();
}
void Deque::delRear()
{
    delLast();
}
int Deque::getFront()
{
    if(getStart())
    {
        return getStart()->item;
    }
    cout<<"Empty Queue!";
    return 0;
}
int Deque::getRear()
{
    if(getStart())
    {
        node *t=getStart();
        while(t->next)
            t=t->next;
        return t->item;
    }
    cout<<"Empty Queue!";
    return 0;
}
Deque::~Deque(){}
bool Deque::isEmpty()
{
    return !getStart();
}