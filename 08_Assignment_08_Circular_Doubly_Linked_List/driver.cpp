#include "CDLL.cpp"
int main()
{
    CDLL obj;
    obj.insertBeg(10);
    obj.insertAfter(obj.search(10),20);
    obj.insertEnd(30);
    obj.insertAfter(obj.search(30),50);
    // obj.delFirst();
    // obj.delFirst();
    // obj.delFirst();
    // obj.delFirst();
    // obj.delFirst();
    // obj.delFirst();
    // obj.delLast();
    // obj.delLast();
    // obj.delLast();
    // obj.delLast();
    // obj.delLast();
    // obj.delLast();
    obj.del(obj.search(10));
    obj.del(obj.search(50));
    obj.del(obj.search(100));
    obj.showList();

    return 0;
}