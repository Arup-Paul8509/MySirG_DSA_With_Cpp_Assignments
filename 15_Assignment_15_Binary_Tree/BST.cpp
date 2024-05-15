#include<iostream>
using namespace std;
class node
{
    public:
        node *left;
        int data;
        node *right;
};
class BST
{
    private:
        node *root;
    public:
        BST();
        bool isEmpty();
        node* getroot();
        void insert(node*,int);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);

        node* search(node*,int);
};
BST::BST(){ root=NULL; }
node* BST::getroot(){ return root; }
bool BST::isEmpty(){    return root==NULL;  }
void BST::insert(node *root,int item)
{
    if(root==NULL)
    {
        node *n=new node();
        n->data=item;
        n->left=n->right=NULL;
        root=n;
        return;
    }
    else if(item < root->data)
        insert(root->left,item);
    else if(item > root->data)
        insert(root->right,item); 
}
void BST::preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void BST::inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void BST::postorder(node *root)
{   
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
node* BST::search(node *root,int item)
{
    if(root->data==item)
        return root;
    search(root->left,item);
    search(root->right,item);
    return NULL;
}