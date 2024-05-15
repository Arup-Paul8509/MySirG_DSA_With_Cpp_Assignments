#include<iostream>
using namespace std;
class DynArray
{
    private:
        int cap,lastindex;
        int *ptr;
    public:
        DynArray(int);
        void doubleArray();
        void halfArray();
        int getCapacity();
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void showArray();
        void del(int);
        int getElement(int);
        int getIndex(int);
        int count();
        ~DynArray();
};
int DynArray::getCapacity()
{
    return cap;
}
DynArray::DynArray(int n)
{
    cap=n;
    lastindex=-1;
    ptr=new int[cap];
}
void DynArray::doubleArray()
{
    cap*=2;
    int *tmp=new int[cap];
    for(int i=0;i<=lastindex;i++)
        tmp[i]=ptr[i];
    delete ptr;//delete []ptr;
    ptr=tmp;
}
void DynArray::halfArray()
{
    cap/=2;
    int *tmp=new int[cap];
    for(int i=0;i<=lastindex;i++)
        tmp[i]=ptr[i];
    delete []ptr;
    ptr=tmp;
}
bool DynArray::isEmpty()
{
    return lastindex==-1;
}
bool DynArray::isFull()
{
    return lastindex+1==cap;
}
void DynArray::append(int item)
{
    if(isFull())
        doubleArray();
    ptr[++lastindex]=item;
}
void DynArray::insert(int index,int item)
{
    if(index>=0 && index<=lastindex+1)
    {
        if(isFull())
            doubleArray();    
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=item;
        lastindex++;
    }
    else
        cout<<endl<<"Invalid operation : Invalid index...";
}
void DynArray::showArray()
{
    for(int i=0;i<=lastindex;i++)
        cout<<ptr[i]<<" ";
}
void DynArray::edit(int index,int newitem)
{
    if(index>=0 && index<=lastindex)
        ptr[index]=newitem;
    else
        cout<<endl<<"Invalid operation : Invalid Index ...";
}
void DynArray::del(int index)
{
    if(isEmpty())
        cout<<endl<<"Invalid operation : Array is empty ...";
    else
    {
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
        if(lastindex+1==cap/2)
            halfArray();
    }
}
int DynArray::getElement(int index)
{
    if(index>=0 && index<=lastindex)
        return ptr[index];
    cout<<endl<<"Invalid operation : Invalid index...";
    return -1;
}
int DynArray::getIndex(int item)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==item)
            return i;
    }
    return -1;
}
int DynArray::count()
{
    return lastindex+1;
}
DynArray::~DynArray()
{
    delete ptr;
}
int main()
{
    DynArray obj(5);
    cout<<endl<<obj.getCapacity();
    cout<<endl;
    obj.append(10);
    obj.append(20);
    obj.append(30);
    obj.showArray();
    cout<<endl<<obj.count();
    cout<<endl;
    obj.insert(3,40);
    cout<<endl<<obj.count()<<endl;
    obj.showArray();
    //cout<<endl<<obj.getCapacity();
    obj.del(2);
    cout<<endl<<obj.count()<<endl;
    obj.showArray();
    return 0;
}
