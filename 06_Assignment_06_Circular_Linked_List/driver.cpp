#include "CLL.cpp"
int main()
{
    CLL obj;
    obj.insertEnd(10);
    obj.insertEnd(20);
    obj.insertEnd(30);
    obj.insertEnd(40);
    obj.insertEnd(50);
    obj.showList();
    cout<<endl;
    obj.del(obj.search(40));
    obj.showList();
    return 0;
}