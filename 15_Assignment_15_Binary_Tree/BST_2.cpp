#include<iostream>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};

class BST
{
    private:
        node *root;
    protected:
        void preorderrec(node *);
        void inorderrec(node *);
        void postorderrec(node *);
        node* deleteNode(node *,int);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preorder();
        void inorder();
        void postorder();
        void del(int);
        node* search(int);
        ~BST();
};

BST::BST(){root=nullptr;}

bool BST::isEmpty(){ return root==nullptr;}

void BST::insert(int data)
{
    node *ptr;
    node *n=new node;
    n->item=data;
    n->left=n->right=nullptr;
    if(root==nullptr) root=n;
    else
    {
        ptr=root;
        while(n->item!=ptr->item)
        {
            if(n->item<ptr->item)
            {
                if(ptr->left)
                    ptr=ptr->left;
                else
                {
                    ptr->left=n;
                    break;
                }
            }
            else
            {
                if(ptr->right)
                    ptr=ptr->right;
                else
                {
                    ptr->right=n;
                    break;
                }
            }
        }
        if(ptr->item==n->item)  delete n;
    }
}

void BST::preorderrec(node *ptr)
{
    if(ptr==nullptr)    return;
    cout<<ptr->item<<" ";
    preorderrec(ptr->left);
    preorderrec(ptr->right);
}

void BST::preorder()
{
    preorderrec(root);
}

void BST::inorderrec(node *ptr)
{
    if(ptr==nullptr)    return;
    inorderrec(ptr->left);
    cout<<ptr->item<<" ";
    inorderrec(ptr->right);
}

void BST::inorder()
{
    inorderrec(root);
}

void BST::postorderrec(node *ptr)
{
    if(ptr==nullptr)    return;
    postorderrec(ptr->left);
    postorderrec(ptr->right);
    cout<<ptr->item<<" ";
}

void BST::postorder()
{
    postorderrec(root);
}

node* BST::deleteNode(node *ptr, int data)
{
    if(ptr==nullptr)    return nullptr;
    if(ptr->item < data)
        ptr->left=deleteNode(ptr->left,data);
    else if(ptr->item > data)
        ptr->right=deleteNode(ptr->right,data);
    else
    {
        //no child
        if(ptr->left==nullptr && ptr->right==nullptr)
        {
            delete ptr;
            return nullptr;
        }
        //single child
        if(ptr->left==nullptr || ptr->right==nullptr)
        {
            node *child=ptr->left?ptr->left:ptr->right;
            delete ptr;
            return child;
        }
        //two child
        node *pred, *parpred;
        parpred=ptr;
        pred=ptr->left;
        while(pred->right)
            pred=pred->right;
        ptr->item=pred->item;
        parpred->right=deleteNode(pred,pred->item);
    }
    return ptr;
}

void BST::del(int data)
{
    root=deleteNode(root, data);
}

node* BST::search(int data)
{
    node *ptr=root;
    while(ptr)
    {
        if(ptr->item==data)
            return ptr;
        if(ptr->item > data)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return ptr;
}

BST::~BST()
{
    while(root)
        del(root->item);
}