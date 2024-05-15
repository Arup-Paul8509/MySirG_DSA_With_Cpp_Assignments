#include "CDLL.cpp"
class Stack:private CDLL
{
    public:
        Stack();
        void push(int);
        int peek();
        void pop();
        void show();
        bool isUnderflow();
        void operator=(Stack &);
        ~Stack();
};
Stack::Stack():CDLL(){}
void Stack::operator=(Stack &s)
{
    CDLL::operator=(s);
}
void Stack::push(int data)
{
    insertEnd(data);
}
int Stack::peek()
{
    if(getLast())
        return getLast()->item;
    else
    {
        cout<<"Stack is Empty!";
        return 0;
    }
}
void Stack::pop()
{
    if(getLast())
        delLast();
    else
        cout<<"Stack Underflow!";
}
void Stack::show()
{
    if(getLast())
    {
        node *t=getLast();
        do{
            cout<<t->item<<endl;
            t=t->prev;
        }while(t!=getLast());
    }
}
bool Stack::isUnderflow()
{
    return !getLast();
}
Stack::~Stack(){}
void reverseStack(Stack &ob)
{
    Stack tmp;
    while(!ob.isUnderflow())
    {
        tmp.push(ob.peek());
        ob.pop();
    }
    ob=tmp;
    //tmp.show();
}
bool isPlaindrome(int n)
{
    Stack s,tmp;
    int d;
    while(n>0)
    {
        d=n%10;
        s.push(d);
        n=n/10;
    }
    tmp=s;
    reverseStack(tmp);
    while(!s.isUnderflow())
    {
        if(s.peek()!=tmp.peek())
            return 0;
        s.pop();
        tmp.pop();       
    }
    return 1;
}