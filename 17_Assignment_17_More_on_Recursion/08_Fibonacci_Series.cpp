//8. Write a recursive function to find nth term of the Fibonacci series.

#include<iostream>
using namespace std;
int fib(int);
int main()
{
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    cout<<n<<"th Fibonacci Number: "<<fib(n);
    return 0;
}
int fib(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fib(n-1)+fib(n-2);       
}