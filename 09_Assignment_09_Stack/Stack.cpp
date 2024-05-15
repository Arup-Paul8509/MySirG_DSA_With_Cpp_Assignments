#include "ArrayDataStructure.cpp"
class Stack:private Array
{
    public:
        Stack(int);
        Stack(Stack &);
        void push(int);
        void push(int,Stack &);
        int peek();
        void pop();
        void pop(Stack &);
        bool isOverflow();
        bool isUnderflow();
        int getCapacity();
        void show();
        void operator=(Stack &);
        ~Stack();
};
Stack::Stack(int cap):Array(cap){}
Stack::Stack(Stack &ob):Array(ob){}
void Stack::operator=(Stack &s)
{
    Array::operator=(s);
}
void Stack::push(int data)
{
    if(isFull())
        cout<<"Stack Overflow!";
    else
    {
        append(data);
    }
}
void Stack::push(int data,Stack &minStack)
{
    if(minStack.isUnderflow())
        minStack.push(data);
    else
    {
        if(minStack.peek()>data)
            minStack.push(data);
    }
    push(data);
}
int Stack::peek()
{
    if(!isEmpty())
        return getElement(count()-1);
    else
    {
        cout<<"Stack is Empty!";
        return 0;
    }
}
void Stack::pop()
{
    if(isEmpty())
        cout<<"Stack Underflow!";
    else
    {
        del(count()-1);
    }
}
void Stack::pop(Stack &minStack)
{
    if(peek()==minStack.peek())
        minStack.pop();
    pop();
}
bool Stack::isOverflow()
{
    return isFull();
}
bool Stack::isUnderflow()
{
    return isEmpty();
}
void Stack::show()
{
    if(!isEmpty())
        for(int i=count()-1;i>=0;i--)
            cout<<getElement(i)<<endl;
}
int Stack::getCapacity()
{
    return Array::getCapacity();
}
Stack::~Stack()
{}
void revStack(Stack &s)
{
    Stack tmp(s.getCapacity());
    while(!s.isUnderflow())
    {
        tmp.push(s.peek());
        s.pop();
    }
    s=tmp;
}