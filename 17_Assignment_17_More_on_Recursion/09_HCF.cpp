//9. Write a recursive function to calculate HCF of two numbers.

#include<iostream>
using namespace std;
int hcf(int,int);
int main()
{
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"HCF = "<<hcf(a,b);
    return 0;
}
int hcf(int x,int y)
{
    if(x%y==0)
        return y;
    return hcf(y,x%y);
}