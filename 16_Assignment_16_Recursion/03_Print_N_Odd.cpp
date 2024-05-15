//3. Write a recursive function to print first N odd natural numbers.

#include<iostream>
using namespace std;
void print_n_odd(int);
int main()
{
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    print_n_odd(n);
    return 0;
}
void print_n_odd(int n)
{
    if(n>=1)
    {
        print_n_odd(n-1);
        cout<<2*n-1<<" ";
    }
}