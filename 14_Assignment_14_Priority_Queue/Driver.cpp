#include "Priority_Queue.cpp"
using namespace std;
int main()
{
    priorityQueue obj;
    obj.insert(30,2);
    obj.showQueue();
    cout<<endl;
    obj.insert(40,5);
    obj.showQueue();
    cout<<endl;
    obj.insert(50,4);
    obj.showQueue();
    cout<<endl;
    obj.insert(60,3);
    obj.showQueue();
    cout<<endl;
    obj.insert(70,1);
    obj.showQueue();
    cout<<endl;
    obj.insert(80,0);
    obj.showQueue();
    cout<<endl;
    obj.insert(90,1);
    obj.showQueue();
    cout<<endl;
    obj.insert(100,6);
    obj.showQueue();
    return 0;
}