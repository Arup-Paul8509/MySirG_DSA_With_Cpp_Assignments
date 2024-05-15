#include<iostream>
using namespace std;
class Queue
{
    private:
        int front;
        int rear;
        int capacity;
        int *ptr;
    public:
        Queue(int);
        void insert(int);
        void del();
        int getFront();
        int getRear();
        bool isOverflow();
        bool isUnderflow();
        int count();
        void show();
        ~Queue();
};
Queue::Queue(int cap)
{
    front=-1;
    rear=-1;
    capacity=cap;
    ptr=new int[cap];
}
void Queue::insert(int item)
{
    if(front==-1) //If queue is empty
    {
        ptr[++rear]=item;
        front++;
    }
    else if((front==0 && rear==capacity-1)||(front-rear==1)) // If queue is Full
        cout<<"Can't insert: Queue is Full!";
    else if(rear==capacity-1 && front>0) // If rear is last index but front is not the first
    {
        rear=0;
        ptr[rear]=item;
    }
    else //Regular case
        ptr[++rear]=item;
}
int Queue::getFront()
{
    if(front==-1)
    {
        cout<<"Queue is empty!";
        return 0;
    }
    return ptr[front];
}
int Queue::getRear()
{
    if(front==-1)
    {
        cout<<"Queue is empty!";
        return 0;
    }
    return ptr[rear];
}
void Queue::del()
{
    if(front==-1)
        cout<<"Can't Delete: Queue is Empty!";
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
bool Queue::isOverflow()
{
    if((front==0 && rear==capacity-1)||(front-rear==1))
        return true;
    else
        return false;
}
bool Queue::isUnderflow()
{
    if(front==-1)
        return true;
    else
        return false;
}
int Queue::count()
{
    int i,c=0;
    if(isUnderflow())
        return 0;
    else if(isOverflow())
        return capacity;
    else if(front==rear)
        return 1;
    else if(rear<=front)
    {
        for(i=0;i<=rear;i++)
            c++;
        for(i=front;i<capacity;i++)
            c++;
        return c;
    }
    else
    {
        for(i=front;i<=rear;i++)    
            c++;
        return c;
    }
}
void Queue::show()
{
    int i;
    if(front==-1)
        cout<<"Empty!";
    else if(rear<front)
    {
        for(i=rear;i>=0;i--)
            cout<<ptr[i]<<" ";
        for(i=capacity-1;i>=front;i--)
            cout<<ptr[i]<<" ";
    }
    else if(front==rear)
        cout<<ptr[front];
    else
    {
        for(i=rear;i>=front;i--)
            cout<<ptr[i]<<" ";
    }
}
Queue::~Queue()
{
    delete []ptr;
}