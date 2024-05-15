#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    int pNo;
    node *next;
};
class priorityQueue
{
    private:
        node *start;
    public:
        priorityQueue();
        void insert(int,int);
        void showQueue();
        void delHighestPriority();
        int getHighestPriorityElem();
        int getHighestPriorityNo();
        bool isEmpty();
        ~priorityQueue();

};
priorityQueue::priorityQueue(){ start=NULL; }
void priorityQueue::insert(int data,int p)
{
    node *n=new node;
    n->data=data;
    n->pNo=p;
    if(start==NULL)
    {
        n->next=NULL;
        start=n;
    }
    else
    {
        if(n->pNo > start->pNo)
        {
            n->next=start;
            start=n;
        }
        else
        {
            node *t=start;
            while(t->next)
            {
                if(t->next->pNo >= n->pNo)
                    t=t->next;
                else
                    break;
            }
            n->next=t->next;
            t->next=n;
        }
    }
    //    node *p1=start,*p2=NULL;
    //    while(p1 && p1->pNo >= n->pNo)
    //    {
    //         p2=p1;
    //         p1=p1->next;
    //    }
    //    if(p1==NULL)
    //    {
    //         n->next=NULL;
    //         p2->next=n;
    //    }
    //    else if(p2==NULL)
    //    {
    //         n->next=p1;
    //         start=n;
    //    }
    //    else
    //    {
    //         p2->next=n;
    //         n->next=p1;
    //    }
    // }
}
void priorityQueue::showQueue()
{
    if(start==NULL)
        cout<<"Empty"<<endl;
    else
    {
        node *t=start;
        while(t)
        {
            cout<<t->data<<"("<<t->pNo<<")"<<" ";
            t=t->next;
        }
    }
}
void priorityQueue::delHighestPriority()
{
    if(start)
    {
        node *t=start;
        start=start->next;
        delete t;
    }
}
int priorityQueue::getHighestPriorityElem()
{
    if(start)
        return start->data;
    else
    {
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
}
int priorityQueue::getHighestPriorityNo()
{
    if(start)
        return start->pNo;
    else
    {
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
}
bool priorityQueue::isEmpty()
{
    return start==NULL;
}
priorityQueue::~priorityQueue()
{
    while(start)
        delHighestPriority();
}