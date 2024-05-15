#include<iostream>
using namespace std;
class Array
{
    private:
        int cap;
        int lastindex;
        int *ptr;
    public:
        Array(int);
        Array(Array &);
        bool isEmpty();
        bool isFull();
        void showArray();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int getElement(int);
        int count();
        int getIndex(int);
        int getCapacity();
        ~Array();
        //Operator Overloading
        void operator=(Array &);
        //Additional functions
        int* getPtr(){return ptr;}
        void setPtr(int *ptr){ this->ptr=ptr;}
};
Array::Array(int n)
{
    cap=n;
    lastindex=-1;
    ptr=new int[cap];
}
Array::Array(Array &ob)
{
    cap=ob.cap;
    lastindex=ob.lastindex;
    ptr=new int[cap];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=ob.ptr[i];
}
void Array::operator=(Array &ob)
{
    cap=ob.cap;
    lastindex=ob.lastindex;
    if(ptr)
        delete []ptr;
    ptr=new int[cap];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=ob.ptr[i];
}
int Array::getCapacity()
{
    return cap;
}
bool Array::isEmpty()
{
    return lastindex==-1;
}
bool Array::isFull()
{
    return lastindex+1==cap;
}
void Array::append(int item)
{
    if(isFull())
        cout<<endl<<"Invalid operation : Array is full...";
    else
    {
        ptr[++lastindex]=item;
    }
}
void Array::insert(int item,int index)
{
    if(isFull())
        cout<<endl<<"Invalid operation : Array is full...";
    else if(index<0 || index>lastindex+1)
        cout<<endl<<"Invalid operation : Invalid index...";
    else if(index==lastindex+1)
    {
        append(item);
    }
    else
    {
        for(int i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=item;
        lastindex++;
    }
}
void Array::showArray()
{
    if(isEmpty())
        cout<<endl<<"Array is empty";
    else
    {
        cout<<endl;
        for(int i=0;i<=lastindex;i++)
            cout<<ptr[i]<<" ";
    }
}
void Array::edit(int index,int newitem)
{
    if(index>=0 && index<=lastindex)
        ptr[index]=newitem;
    else
        cout<<endl<<"Invalid operation : Invalid index...";
}
void Array::del(int index)
{
    if(isEmpty())
        cout<<endl<<"Invalid operation : Can't delete, the array is empty ...";
    else
    {
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
    }
}
int Array::getElement(int index)
{
    if(index>=0 && index<=lastindex)
        return ptr[index];
    else
    {
        cout<<endl<<"Invalid operation : Invalid index ... ";
        return -1;
    }
}
int Array::count()
{
    return lastindex+1;
}
int Array::getIndex(int item)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==item)
            return i;
    }
    return -1;
}
Array::~Array()
{
    delete []ptr;
}
