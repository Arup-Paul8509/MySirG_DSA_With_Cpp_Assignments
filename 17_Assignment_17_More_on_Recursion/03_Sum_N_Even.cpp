//3. Write a recursive function to calculate sum of first N even natural numbers.

#include<iostream>
using namespace std;
int sum_N_Even(int);
int main()
{
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    cout<<"Sum = "<<sum_N_Even(n);
    return 0;
}
int sum_N_Even(int n)
{
    if(n==0)
        return 0;
    return (2*n)+sum_N_Even(n-1);
}