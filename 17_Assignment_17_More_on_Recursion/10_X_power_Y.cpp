//10. Write a recursive function to calculate x power y.

#include<iostream>
using namespace std;
int power(int,int);
int main()
{
    int x,y;
    cout<<"Enter number: ";
    cin>>x;
    cout<<"Enter power: ";
    cin>>y;
    cout<<x<<" power "<<y<<" = "<<power(x,y);
    return 0;
}
int power(int x,int y)
{
    if(y==0)
        return 1;
    return x*power(x,y-1);
}