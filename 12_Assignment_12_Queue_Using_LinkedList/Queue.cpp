#include "Singly_Linked_List.cpp"
class Queue:private SLL
{
    public:
        Queue();
        void insert(int);
        void del();
        int getFront();
        int getRear();
        int count();

};
Queue::Queue():SLL(){}
void Queue::insert(int item)
{
    insertBeginning(item);
}
void Queue::del()
{
    delLast();
}
int Queue::getFront()
{
    node *t=getStart();
    while(t->next)
        t=t->next;
    return t->item;
}
int Queue::getRear()
{
    return getStart()->item;
}
int Queue::count()
{
    int c=0;
    node *t=getStart();
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}
void sort(Queue &q)
{
    
}