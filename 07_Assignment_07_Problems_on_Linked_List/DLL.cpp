#include<iostream>
using namespace std;
class node
{
    public:
        node *prev;
        int item;
        node *next;
};
class DLL
{
    private:
        node *start;
    public:
        DLL();
        void insertBeginning(int);
        void insertAtEnd(int);
        node* search(int);
        void insertAfter(node*,int);
        void delFirst();
        void delLast();
        void del(node*);
        void showList();
        node* getFirstNode();
        ~DLL();
};
DLL::DLL(){ start=nullptr;}
node* DLL::getFirstNode()
{
    return start;
}
void DLL::insertBeginning(int item)
{
    node *tmp=new node;
    tmp->prev=nullptr;
    tmp->item=item;
    tmp->next=start;
    if(start)
        start->prev=tmp;
    start=tmp;    
}
void DLL::insertAtEnd(int item)
{
    node *tmp=new node;
    tmp->item=item;
    tmp->next=nullptr;
    if(!start)
    {
        tmp->prev=nullptr;
        start=tmp;
    }
    else
    {
        node *t=start;
        while(t->next)
            t=t->next;
        tmp->prev=t;
        t->next=tmp;
    }
}
node* DLL::search(int item)
{
    node *t=start;
    while(t)
    {
        if(t->item==item)
            return t;
        t=t->next;
    }
    return nullptr;
}
void DLL::insertAfter(node *p,int item)
{
    if(p)
    {
        node *tmp=new node;
        tmp->item=item;
        tmp->prev=p;
        tmp->next=p->next;
        if(p->next)
            p->next->prev=tmp;
        p->next=tmp;
    }
}
void DLL::delFirst()
{
    if(start)
    {
        node *t=start;
        if(t->next)
            t->next->prev=nullptr;
        start=t->next;
        delete t;
    }
}
void DLL::delLast()
{
    if(start)
    {
        node *t=start;
        while(t->next)
            t=t->next;
        if(!t->prev)
            start=nullptr;
        else
        {
            t->prev->next=nullptr;
            t->prev=nullptr;
        }
        delete t;
    }
}
void DLL::del(node *p)
{
    if(p)
    {
        if(!p->prev)
            delFirst();
        else if(!p->next)
            delLast();
        else
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
        }
    }
}
void DLL::showList()
{
    if(start==nullptr)
        cout<<"Empty ! "<<endl;
    else
    {
        node *t=start;
        while(t)
        {
            cout<<t->item<<" ";
            t=t->next;
        }
    }
}
DLL::~DLL()
{
    while(start)
        delLast();
}