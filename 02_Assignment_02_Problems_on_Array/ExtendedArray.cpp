#include<iostream>
#include "F:\DSA Using CPP Assignment\01_Assignment_01_Array_Data_Structure\ArrayDataStructure.cpp"
using namespace std;
class ExtendedArray:public Array
{
    private:
    public:
        ExtendedArray(int);
        void sort();
        int max();
        int min();
        int search(int);
        int sum();
        float avg();
        void rotate();
        void removeDuplicate();
        int secondLargest();
        void swap(int,int);
};
ExtendedArray::ExtendedArray(int n):Array(n)
{}
void ExtendedArray::sort()
{
    int *p=getPtr();
    for(int i=0;i<=count()-1;i++)
    {
        for(int j=0;j<count()-1;j++)
        {
            if(p[j]>p[j+1])
            {
                int tmp=p[j];
                p[j]=p[j+1];
                p[j+1]=tmp;
            }
        }
    }
    setPtr(p);
}
int ExtendedArray::max()
{
    int *p=getPtr();
    int max=0;
    for(int i=1;i<=count()-1;i++)
    {
        if(p[i]>p[max])
            max=i;
    }
    return p[max];
}
int ExtendedArray::min()
{
    int min=getElement(0);
    for(int i=1;i<count();i++)
    {
        if(getElement(i)<min)
            min=getElement(i);
    }
    return min;
}
int ExtendedArray::search(int item)
{
    for(int i=0;i<count();i++)
        if(getElement(i)==item)
            return i;
    return -1;
}
int ExtendedArray::sum()
{
    int s=0;
    for(int i=0;i<count();i++)
        s=s+getElement(i);
    return s;
}
float ExtendedArray::avg()
{
    float s=0;
    for(int i=0;i<count();i++)
        s=s+getElement(i);
    return s/count();
}
void ExtendedArray::rotate()
{
    int *p=getPtr();
    int tmp=getElement(count()-1);
    for(int i=count()-1;i>=1;i--)
        p[i]=p[i-1];
    p[0]=tmp;
}
void ExtendedArray::removeDuplicate()
{
    int *p=getPtr();
    for(int i=0;i<count();i++)
    {
        for(int j=i+1;j<count();j++)
        {
            if(p[j]==p[i])
                del(j);
        }
    }
}
int ExtendedArray::secondLargest()
{
    int l=getElement(0),sl=getElement(0);
    for(int i=1;i<count();i++)
    {
        if(getElement(i)>l)
        {
            sl=l;
            l=getElement(i);
        }
    }
    return sl;

}
void ExtendedArray::swap(int x,int y)
{
    if(x>=0 && x<count() && y>=0 && y<count() && x!=y)
    {
        int *p=getPtr();
        int tmp=p[x];
        p[x]=p[y];
        p[y]=tmp;
    }
}