#include "Stack.cpp"
#include<math.h>
int eval(int x,int y,char op)
{
    switch(op)
    {
        case '+':
            return y+x;
        break;
        case '-':
            return y-x;
        break;
        case '*':
            return y*x;
        break;
        case '/':
            return y/x;
        break;
        case '^':
            return pow(y,x);
    }
}
int evalPostfix(string P)
{
    Stack s(20);
    P+=')';
    int i=0;
    while(P[i]!=')')
    {
        if(P[i]>='0' && P[i]<='9')
            s.push(P[i]-48); // ASCII of '0' is 48 so it store 48-48=0 into stack
        else
        {
            int x=s.peek();
            s.pop();
            int y=s.peek();
            s.pop();
            s.push(eval(x,y,P[i]));
        }
        i++;
    }
    return s.peek();
}
int main()
{
    string P="23+52-3/*";
    cout<<evalPostfix(P);
    return 0;
}