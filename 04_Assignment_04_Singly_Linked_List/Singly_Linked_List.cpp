#include<iostream>
using namespace std;
class node
{
    public:
        int item;
        node *next;
};
class SLL
{
    private:
        node *start;
    public:
        SLL();
        void insertBeginning(int);
        void insertLast(int);
        void showList();
        node* search(int);
        void insertAfter(int,node*); 
        void delFirst();
        void delLast();
        void del(node*);
        ~SLL();
};
SLL::SLL()
{
    start=NULL;
}
void SLL::insertBeginning(int item)
{
    node *tmp=new node();
    tmp->item=item;
    tmp->next=start;
    start=tmp;
}
void SLL::insertLast(int item)
{
    node *tmp=new node();
    tmp->item=item; 
    tmp->next=NULL;
    if(start)
    {   
        node *t=start;
        while(t->next)
            t=t->next;
        t->next=tmp;
    }
    else
        start=tmp;
}
void SLL::showList()
{
    if(start==NULL)
        cout<<"Empty !"<<endl;
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
node* SLL::search(int item)
{
    if(start==NULL)
        return NULL;
    else 
    {
        node *ptr=start;
        while(ptr)
        {
            if(ptr->item==item)
                return ptr;
            ptr=ptr->next;
        }
        return NULL;
    }
}
void SLL::insertAfter(int item,node* pos)
{
    if(pos==NULL)
        cout<<endl<<"Invalid postion";
    else 
    {
        node *tmp=new node;
        tmp->item=item;
        tmp->next=pos->next;
        pos->next=tmp;
    }    
}
void SLL::delFirst()
{
    if(start==NULL)
        cout<<endl<<"No element to delete ... ! ";
    else
    {
        node *tmp=start;
        start=start->next;
        delete tmp;
    }
}
void SLL::delLast()
{
    if(start==NULL)
        cout<<endl<<"No element to delete ... !";
    else if(!start->next)
        delFirst();
    else
    {
        node *p1=start;
        node *p2=NULL;
        while(p1->next)
        {
            p2=p1;
            p1=p1->next;
        }
        p2->next=NULL;
        delete p1;
    }
}
void SLL::del(node *pos)
{
    if(pos==NULL)
        cout<<endl<<"Invalid Position !";
    else if(pos==start)
        delFirst();
    else if(pos->next==NULL)
        delLast();
    else
    {
        node *p1,*p2;
        p1=start;
        p2=pos->next;
        while(p1->next!=pos)
            p1=p1->next;
        p1->next=p2;
        delete pos;
    }
}
SLL::~SLL()
{
    while(start)
        delFirst();
}
int main()
{
    SLL obj;
    obj.showList();
    obj.insertBeginning(10);
    obj.insertLast(20);
    obj.insertBeginning(15);
    obj.showList();
    obj.insertAfter(50,obj.search(30));
    obj.insertBeginning(101);
    obj.insertAfter(44,obj.search(101));
    cout<<endl;
    obj.showList();
    //cout<<endl<<obj.search(15);
    /*
    obj.delFirst();
    cout<<endl;
    obj.showList();
    
    obj.delFirst();
    cout<<endl;
    obj.showList();
    obj.delFirst();
    cout<<endl;
    obj.showList();
    obj.delFirst();
    cout<<endl;
    obj.showList();
    
    obj.delLast();
    cout<<endl;
    obj.showList();
    obj.delLast();
    cout<<endl;
    obj.showList();
    obj.delLast();
    cout<<endl;
    obj.showList();
    obj.delLast();
    cout<<endl;
    obj.showList();
    */
    obj.del(obj.search(1010));
    cout<<endl;
    obj.showList();
    return 0;
}