#include<iostream>
using namespace std;
class node
{
    public:
        node *prev;
        int item;
        node *next;
};
class CDLL
{
    private:
        node *start;
    public:
        CDLL();
        void insertBeg(int);
        void insertEnd(int);
        node* search(int);
        void insertAfter(node*,int);
        void delFirst();
        void delLast();
        void del(node*);
        void showList();
        ~CDLL();
};
//Constructor
CDLL::CDLL() { start=nullptr; }
//Insert into beginning
void CDLL::insertBeg(int item)
{
    node *n=new node;
    n->item=item;
    if(start)
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
    else
    {
        n->prev=n;
        n->next=n;
    }
    start=n;
}
//Insert at the end
void CDLL::insertEnd(int item)
{
    node *n=new node;
    n->item=item;
    if(start)
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;    
    }
    else
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
}
//Search a node
node* CDLL::search(int item)
{
    node *tmp=start;
    if(start)
    {
        do 
        {
            if(tmp->item==item)
                return tmp;
            tmp=tmp->next;
        }while(tmp!=start);
    }
    return nullptr;
}
//Insert after specific node
void CDLL::insertAfter(node *pos,int item)
{
    if(pos)
    {
        node *n=new node;
        n->item=item;
        n->prev=pos;
        n->next=pos->next;
        pos->next->prev=n;
        pos->next=n;
    }
}
//Delete first element
void CDLL::delFirst()
{
    //if(start)
    //{
        node *t=start;
        if(start->next==start)
            start=nullptr;
        else
        {
            start=start->next;
            start->prev=t->prev;
            t->prev->next=start;
        }
        delete t;
    //}
    
}
//Delete last element
void CDLL::delLast()
{
    node *t=start->prev;
    if(start==start->next)
        start=nullptr;
    else
    {
        t->prev->next=start;
        start->prev=t->prev;
    }
    delete t;
}
//Delete specific node
void CDLL::del(node *pos)
{
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    if(pos==start)
        start=start->next;
    delete pos;
}
//Display all elements of list
void CDLL::showList()
{
    //if(start)
    //{
        node *t=start;
        do
        {
            cout<<t->item<<" ";
            t=t->next;
        }while(t!=start);
    //}
}
//Destructor
CDLL::~CDLL()
{
    while(start)
        delFirst();
}