#include "Stack.cpp"
int checkPrecedence(char op)
{
    if(op=='^')
        return 3;
    else if(op=='/' || op=='*')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string Q)
{
    string P;
    Stack s(10);
    s.push('(');
    Q=Q+')';
    // cout<<"Q = "<<Q<<endl;
    // cout<<"Stack"<<endl;
    // s.show();
    // cout<<endl;
    // cout<<"P = "<<P<<endl;
    for(int i=0;i<Q.length();i++)
    {
        if((Q[i]>='a' && Q[i]<='z')||(Q[i]>='A' && Q[i]<='Z'))
            P=P+Q[i];
        else if(Q[i]=='(')
            s.push(Q[i]);
        else if(Q[i]==')')
        {
            while(!s.isUnderflow() && s.peek()!='(')
            {
                P=P+(char)s.peek();
                s.pop();
            }
            if(!s.isUnderflow())
                s.pop();
        }
        else
        {
            if(s.isUnderflow())
                s.push(Q[i]);
            else
            {
                while(!s.isUnderflow() && checkPrecedence(s.peek())>=checkPrecedence(Q[i]))
                {
                    P=P+(char)s.peek();
                    s.pop();
                }
                s.push(Q[i]);                
            }
        }
        // cout<<"Q = "<<Q<<endl;
        // cout<<"Stack"<<endl;
        // s.show();
        // cout<<endl;
        // cout<<"P = "<<P<<endl; 
    }

    return P;
}
int main()
{
    string P,Q;
    Q="A*B-C/(D+E)";
    cout<<"Infix : "<<Q<<endl;
    P=infixToPostfix(Q);
    cout<<"Postfix : "<<P;
    return 0;
}