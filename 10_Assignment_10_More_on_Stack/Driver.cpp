#include "Stack.cpp"
int main()
{
    Stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.pop();
    obj.push(40);
    obj.pop();
    obj.push(50);
    obj.push(100);
    obj.push(11);
    obj.show();
    cout<<endl;
    //cout<<obj.peek();
    cout<<endl;
    //isUnderflow();
    reverseStack(obj);
    obj.show();
    cout<<endl;
    cout<<isPlaindrome(121);
    return 0;
}