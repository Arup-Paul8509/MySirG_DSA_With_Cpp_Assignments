//7. Write a recursive function to print binary of a given decimal number.

#include<iostream>
using namespace std;
void print_Binary(int);
int main()
{
    int d;
    cout<<"Enter a decimal number: ";
    cin>>d;
    print_Binary(d);
    return 0;
}
void print_Binary(int n)
{
    if(n>0)
    {
        print_Binary(n/2);
        cout<<n%2;
    }
}