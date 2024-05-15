#include<iostream>
#include "BST.cpp"
using namespace std;
int main()
{
    BST obj;
    obj.preorder(obj.getroot());
    obj.insert(obj.getroot(),2);
    obj.insert(obj.getroot(),4);
    obj.inorder(obj.getroot());
    return 0;
}