#include<iostream>
#include "Stack.cpp"
using namespace std;
int main()
{
    Stack obj(5);
    Stack minStack(obj.getCapacity());
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.show();
    cout<<endl;
    revStack(obj);
    obj.show();
    // obj.push(40,minStack);
    // obj.push(30,minStack);
    // obj.push(50,minStack);
    // obj.push(10,minStack);
    // obj.pop(minStack);
    // obj.push(5,minStack);
    // obj.pop(minStack);
    // obj.pop(minStack);
    // obj.pop(minStack);
    // obj.pop(minStack);
    // cout<<endl;
    // obj.show();
    // cout<<endl;
    // cout<<minStack.peek();
    
    return 0;
}