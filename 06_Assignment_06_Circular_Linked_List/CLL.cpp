#include<iostream>
using namespace std;
class node
{
    public:
        int item;
        node* next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL();
        void showList();
        void insertBeg(int);
        void insertEnd(int);
        node* search(int);
        void insertAfter(int,node*);
        void delFirst();
        void delLast();
        void del(node*);
        node* getFirstNode();
        ~CLL();
};
//Constructor
CLL::CLL(){ last=nullptr; }
//Show elements of list
void CLL::showList()
{
    if(!last)
        cout<<"Empty !";
    else
    {
        node *p=last->next;
        do
        {
            cout<<p->item<<" ";
            p=p->next;
        }while(p!=last->next);
    }
}
//Insert at the beginning
void CLL::insertBeg(int item)
{
    node *tmp=new node;
    tmp->item=item;
    if(last)
        tmp->next=last->next;
    else
        last=tmp;
    last->next=tmp;
}
//Insert at end
void CLL::insertEnd(int item)
{
    node *tmp=new node;
    tmp->item=item;
    if(last)
    {
        tmp->next=last->next;
        last->next=tmp;
    }
    else
        tmp->next=tmp;
    last=tmp;
}
//Search a node
node* CLL::search(int item)
{
    if(last)
    {
        node *p=last->next;
        do
        {
            if(p->item==item)
                return p;
            p=p->next;
        }while(p!=last->next);
    }
    return nullptr;
}
//Insert after specified position
void CLL::insertAfter(int item,node* pos)
{
    if(pos)
    {
        if(pos==last)
            insertEnd(item);
        else
        {
            node *tmp=new node;
            tmp->item=item;
            node *p=last->next;
            while(p!=pos)
                p=p->next;
            tmp->next=p->next;
            p->next=tmp;
        }
    }
}
//Delete first node
void CLL::delFirst()
{
    if(last)
    {
        node *p=last->next;
        if(last->next==last)
            last=nullptr;
        else
            last->next=p->next;
        delete p;
    }
}
//Delete last node
void CLL::delLast()
{
    if(last)
    {
        node *tmp=last; //tmp points the last node
        if(last->next==last) //for single node
            last=nullptr;
        else //for more than one node
        {
            node *p=last->next;
            while(p->next!=last)
                p=p->next;
            p->next=last->next;
            last=p;
        }
        //tmp->next=nullptr;
        delete tmp;
    }
}
//Delete specific node
void CLL::del(node *pos)
{
    if(pos)
    {
        if(pos==last)
            delLast();
        else if(pos==last->next)
            delFirst();
        else
        {
            node *p=last->next;
            while(p->next!=pos)
                p=p->next;
            p->next=pos->next;
            pos->next=nullptr;
            delete pos;
        }
    }
}
//Get first node address
node* CLL::getFirstNode()
{
	return last->next;
}
//Destructor
CLL::~CLL()
{
    while(last)
        delFirst();
}
int isCycle(CLL &obj)
{
    node *t1,*t2;
    t1=t2=obj.getFirstNode();
    do 
    {
        if(!t1)
            return 0;
        if(!t1->next)
            return 0;
        t1=t1->next->next;
        t2=t2->next;
    }while(t1!=t2);
    return 1;
}
int cycleLength(CLL &obj)
{
    int count=0;
    if(isCycle(obj))
    {
        node *t1,*t2;
        t1=t2=obj.getFirstNode();
        do
        {
            t1=t1->next;
            t2=t2->next->next;
        } while(t1!=t2);
        do
        {
            count++;
            t2=t2->next;
        } while (t1!=t2);
        
    }
    return count;
}
int main()
{
	CLL obj;
	obj.insertEnd(10);
	obj.insertEnd(20);
	obj.insertEnd(30);
    obj.insertEnd(40);
	cout<<isCycle(obj)<<endl;
    cout<<cycleLength(obj);
	return 0;
}
