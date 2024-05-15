//2. Write a recursive function to print first N natural numbers in reverse order.

#include<iostream>
using namespace std;
void print_N_rev(int);
int main()
{
    int n;
    printf("Enter value for n: ");
    scanf("%d",&n);
    print_N_rev(n);
    return 0;
}
void print_N_rev(int n)
{
    if(n>=1)
    {
        cout<<n<<" ";
        print_N_rev(n-1);
    }
}