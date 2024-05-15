#include "DLL.cpp"
DLL add(DLL &obj1,DLL obj2)
{
    int carry=0,sum;
    DLL obj;
    node *t1,*t2;
    t1=obj1.getFirstNode();
    t2=obj2.getFirstNode();
    while(t1->next)
        t1=t1->next;
    while(t2->next)
        t2=t2->next;
    while(t1 && t2)
    {
        sum=t1->item+t2->item+carry;
        carry=sum/10;
        sum=sum%10;
        obj.insertBeginning(sum);
        t1=t1->prev;
        t2=t2->prev;
    }
    if(!t1)
    {
        while(t2)
        {
            sum=t2->item+carry;
            carry=sum/10;
            sum=sum%10;
            obj.insertBeginning(sum);
            t2=t2->prev;
        }
    }
    else
    {
        while(t1)
        {
            sum=t1->item+carry;
            carry=sum/10;
            sum=sum%10;
            obj.insertBeginning(sum);
            t1=t1->prev;
        } 
    }
    //obj.showList();
    return obj;
}
int main()
{
    DLL obj1,obj2;
    obj1.insertAtEnd(1);
    obj1.insertAtEnd(2);
    obj1.insertAtEnd(3);
    obj1.insertAtEnd(4);
    obj1.showList();
    cout<<endl;
    obj2.insertAtEnd(4);
    obj2.insertAtEnd(5);
    obj2.insertAtEnd(6);
    obj2.insertAtEnd(7);
    obj2.showList();
    cout<<endl;
    DLL obj=add(obj1,obj2);
    obj.showList();
    return 0;
}