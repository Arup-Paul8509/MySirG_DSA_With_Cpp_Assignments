//4. Write a recursive function to calculate sum of squares of first N natural numbers.

#include<iostream>
using namespace std;
int sum_N_Square(int);
int main()
{
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    cout<<"Sum = "<<sum_N_Square(n);
    return 0;
}
int sum_N_Square(int n)
{
    if(n==0)
        return 0;
    return (n*n)+sum_N_Square(n-1);
}