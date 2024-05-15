#include "ArrayDataStructure.cpp"
int main()
{
    Array arr(10);
    arr.showArray();
    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);
    arr.showArray();
    arr.insert(50,2);
    arr.showArray();
    arr.edit(1,25);
    arr.showArray();
    arr.del(2);
    arr.showArray();
    cout<<endl<<arr.getElement(2);
    cout<<endl<<arr.getIndex(40);
    return 0;
}