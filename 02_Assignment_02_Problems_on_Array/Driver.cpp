#include<iostream>
#include "ExtendedArray.cpp"
using namespace std;
int main()
{
    ExtendedArray obj(10);
    /*
    obj.append(50);
    obj.append(40);
    obj.append(30);
    obj.append(20);
    obj.append(10);
    obj.append(65);
    cout<<endl<<obj.count()<<endl;
    obj.showArray();
    obj.sort();
    obj.showArray();
    cout<<endl<<obj.max()<<endl;
    cout<<endl<<obj.min()<<endl;
    cout<<endl<<obj.search(30)<<endl;
    cout<<endl<<obj.search(100)<<endl;
    cout<<endl<<obj.sum()<<endl;
    cout<<endl<<obj.avg()<<endl;
    obj.rotate();
    obj.showArray();
    obj.rotate();
    obj.showArray();
    */
    obj.append(10);
    obj.append(20);
    obj.append(10);
    obj.append(15);
    obj.append(20);
    obj.append(40);
    obj.append(50);
    obj.showArray();
    obj.removeDuplicate();
    obj.showArray();
    obj.swap(0,2);
    obj.showArray();
    cout<<endl<<obj.secondLargest();
    return 0;
}