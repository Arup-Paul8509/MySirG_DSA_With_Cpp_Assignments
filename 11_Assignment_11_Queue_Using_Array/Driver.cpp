#include "Queue.cpp"
int main()
{
    Queue q(5);
    // cout<<q.isUnderflow();
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.insert(50);
    q.del();
    q.del();
    q.del();
    q.insert(60);
    q.del();
    q.del();
    q.del();
    cout<<q.getFront();
    q.show();
    cout<<endl<<q.count();
    return 0;
}