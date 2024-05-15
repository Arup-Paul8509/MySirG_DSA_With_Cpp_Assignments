#include "SLL.cpp"
int count(SLL &obj)
{
    node *t;
    int c=0;
    t=obj.getFirstNode();
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}
void reverse(SLL &obj)
{
    node *t1,*t2,*t3;
    t1=obj.getFirstNode();
    t2=t3=nullptr;
    while(t1->next)
    {
        t3=t2;
        t2=t1;
        t1=t1->next;
        t2->next=t3;

    }
    t1->next=t2;
    obj.setFirstNode(t1);
}
node* findMiddle(SLL &obj)
{
    int n=count(obj);
    node *t=obj.getFirstNode();
    if(n%2==0)
    {
        for(int i=1;i<n/2;i++)
            t=t->next;
        return t;
    }
    else
    {
        for(int i=1;i<(n+1)/2;i++)
            t=t->next;
        return t;
    }
    return nullptr;
}
int isCycle(SLL &obj)
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
int cycleLength(SLL &obj)
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
void sort(SLL &obj)
{
    node *t1,*t2;
    int i,j,tmp;
    for(i=1;i<=count(obj);i++)
    {
        t1=obj.getFirstNode();
        t2=t1->next;
        for(j=0;j<=count(obj)-i-1;j++)
        {
            if(t1->item > t2->item)
            {
                tmp=t1->item;
                t1->item=t2->item;
                t2->item=tmp;
            }
            t1=t2;
            t2=t2->next;
        }
    }
}
SLL merge(SLL &obj1,SLL &obj2)
{
    node *t1,*t2;
    t1=obj1.getFirstNode();
    t2=obj2.getFirstNode();
    SLL obj;
    while(t1 && t2)
    {
        if(t1->item<=t2->item)
        {
            obj.insertLast(t1->item);
            t1=t1->next;
        }
        else
        {
            obj.insertLast(t2->item);
            t2=t2->next;
        }
    }
    if(!t1)
    {
        while(t2)
        {
            obj.insertLast(t2->item);
            t2=t2->next;
        }
    }
    else
    {
        while(t1)
        {
            obj.insertLast(t1->item);
            t1=t1->next;
        }
    }
    return obj;
}
int main()
{
    //SLL obj;
    // node *t;
    // obj.insertLast(10);
    // obj.insertBeginning(20);
    // obj.insertBeginning(30);
    // obj.insertBeginning(40);
    // obj.insertLast(50);
    // obj.insertLast(60);
    // obj.showList();
    // //reverse(obj);
    // cout<<endl;
    // obj.showList();
    // cout<<endl;
    // t=findMiddle(obj);
    // if(t)
    //     cout<<t->item;
    // cout<<endl;
    // //cout<<isCycle(obj);
    // //cout<<endl<<count(obj);
    // sort(obj);
    // cout<<endl;
    // obj.showList();
    SLL obj1,obj2;
    obj1.insertLast(10);
    obj1.insertLast(30);
    obj1.insertLast(40);
    obj1.insertLast(60);
    obj1.showList();
    cout<<endl;
    obj2.insertLast(20);
    obj2.insertLast(50);
    obj2.showList();
    cout<<endl;
    SLL obj=merge(obj1,obj2);
    obj.showList();
    return 0;
}