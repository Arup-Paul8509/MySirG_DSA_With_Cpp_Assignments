//2. Write a recursive function to calculate sum of first N odd natural numbers.

#include<iostream>
using namespace std;
int sum_N_Odd(int);
int main()
{
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    cout<<"Sum = "<<sum_N_Odd(n);
    return 0;
}
int sum_N_Odd(int n)
{
    if(n==0)
        return 0;
    return (2*n-1)+sum_N_Odd(n-1);
}