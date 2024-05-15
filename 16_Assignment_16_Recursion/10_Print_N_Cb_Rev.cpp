//10. Write a recursive function to print cubes of first N natural numbers in reverse order.

#include<iostream>
using namespace std;
void print_N(int);
int main(){
    int n;
    cout<<"Enter value for n: ";
    cin>>n;
    print_N(n);
    return 0;
}
void print_N(int n)
{
    if(n>=1)
    {
        cout<<n*n*n<<" ";
        print_N(n-1);
    }
}