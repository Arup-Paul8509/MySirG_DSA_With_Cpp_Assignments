//6. Write a recursive function to calculate sum of the digits of a given number.

#include<iostream>
using namespace std;
int sum_of_digits(int);
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Sum = "<<sum_of_digits(n);
    return 0;
}
int sum_of_digits(int n)
{
    if(n==0)
        return 0;
    return (n%10)+sum_of_digits(n/10);
}