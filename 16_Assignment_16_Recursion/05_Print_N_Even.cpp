//5. Write a recursive function to print first N even natural numbers.
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
        print_N(n-1);
        cout<<2*n<<" ";
    }
}