#include<iostream>
using namespace std;
class node
{
    public:
        int coeff;
        int degree;
        node* next;
};
class Polynomial
{
    private:
        node* start;
    public:
        Polynomial();
        void insert(int,int);
        void showPolynomial();
        node* getFirstNode();
};
Polynomial::Polynomial()
{
    start=NULL;
}
void Polynomial::insert(int coeff,int deg)
{
    node *n=new node;
    n->coeff=coeff;
    n->degree=deg;
    if(!start)
    {
        n->next=NULL;
        start=n;
    }
    else
    {
        node *t1,*t2;
        t1=start;
        t2=NULL;
        while(t1)
        {
            if(t1->degree > deg)
            {
                t2=t1;
                t1=t1->next;
            }
            else
                break;
        }
        if(t1==start)
        {   
            n->next=start;
            start=n;
        }
        else if(t1==NULL)
        {
            n->next=NULL;
            t2->next=n;
        }
        else
        {
            n->next=t1;
            t2->next=n;
        }
    }
}
void Polynomial::showPolynomial()
{
    node *t=start;
    if(t)
        cout<<"f(x)=";
    while(t)
    {
        if(t->next==NULL)
            cout<<t->coeff<<"X^"<<t->degree;
        else
            cout<<t->coeff<<"X^"<<t->degree<<"+";
        t=t->next;
    }
}
node* Polynomial::getFirstNode()
{
    return start;
}
//Non-member function
void addPolynomial(Polynomial &obj1,Polynomial &obj2)
{
    Polynomial obj;
    node *t1,*t2;
    t1=obj1.getFirstNode();
    t2=obj2.getFirstNode();
    while(t1 && t2)
    {
        if(t1->degree == t2->degree)
        {
            obj.insert((t1->coeff)+(t2->coeff),t1->degree);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->degree > t2->degree)
        {
            obj.insert(t1->coeff,t1->degree);
            t1=t1->next;
        }
        else if(t1->degree < t2->degree)
        {
            obj.insert(t2->coeff,t2->degree);
            t2=t2->next;
        }
    }
    if(!t1)
    {
        while(t2)
        {
            obj.insert(t2->coeff,t2->degree);
            t2=t2->next;
        }
    }
    else
    {
        while(t1)
        {
            obj.insert(t1->coeff,t1->degree);
            t1=t1->next;
        }
    }
    cout<<endl;
    obj.showPolynomial();
}
int main()
{
    Polynomial p1,p2;
    p1.insert(3,2);
    p1.insert(2,1);
    p1.insert(1,0);
    p1.showPolynomial();
    cout<<endl;
    p2.insert(1,3);
    p2.insert(3,1);
    p2.showPolynomial();
    cout<<endl;
    addPolynomial(p1,p2);
    return 0;
}