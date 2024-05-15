//1. Write a recursive function to calculate sum of first N natural numbers.

#include<iostream>
using namespace std;
int sum_N(int);
int main()
{
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    cout<<"Sum = "<<sum_N(n);
    return 0;
}
int sum_N(int n)
{
    if(n==0)
        return 0;
    return n+sum_N(n-1);
}
