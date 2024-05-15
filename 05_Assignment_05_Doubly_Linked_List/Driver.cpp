#include "DLL.cpp"
int main()
{
    DLL obj;
    obj.showList();
    obj.insertBeginning(10);
    obj.insertAtEnd(20);
    obj.insertBeginning(30);
    obj.insertBeginning(40);
    obj.insertAtEnd(100);
    cout<<endl;
    obj.showList();
    cout<<endl;
    obj.insertAfter(obj.search(10),50);
    obj.showList();
    obj.delFirst();
    cout<<endl;
    obj.showList();
    cout<<endl;
    obj.del(obj.search(50));
    obj.showList();
    return 0;
}