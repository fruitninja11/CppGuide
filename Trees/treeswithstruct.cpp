/*
Implementation of binary search tree where left side of tree is smaller value than root  
and right side is bigger value than root.

Inorder Traversal:
At first traverse left subtree then visit the root and then traverse the right subtree.

Preorder Traversal:
At first visit the root then traverse left subtree and then traverse the right subtree.

Postorder Traversal
At first traverse left subtree then traverse the right subtree and then visit the root.

*/


#include<iostream>
using namespace std;


struct Tree
{
    int value;
    Tree* left;
    Tree* right;

    //Tree(int value) : value(value), left(nullptr), right(nullptr) {}
};


//new node creation
Tree* createNode(int val)
{
    Tree* newnode = new Tree;
    newnode->value = val;
    newnode->left= nullptr;
    newnode->right= nullptr;
    return newnode;
}

Tree* insertNode(Tree *root, int val)
{
    //if new node, then create
    if (root == nullptr)
    {
        return createNode(val);
    }

    if (val < root->value)
    {
        root->left = insertNode(root->left,val);
    }

    if (val > root->value)
    {
        root->right = insertNode(root->right,val);
    }
    
    return root;
}



//traversal in tree : postorder
void postorder(Tree* root)
{
    if(root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << endl;
    }
}


//traversal in tree : preorder
void preorder(Tree* root)
{
    if(root != nullptr)
    {
        cout << root->value << endl;
        preorder(root->left);
        preorder(root->right);
    }
}


//traversal in tree : inorder
void inorder(Tree* root)
{
    if(root != nullptr)
    {
        inorder(root->left);
        cout << root->value << endl;
        inorder(root->right);
    }
}



int main()
{   
    Tree *t = nullptr;
    t = insertNode(t,22);
    t = insertNode(t,12);
    t = insertNode(t,8);
    t = insertNode(t,20);
    t = insertNode(t,30);
    t = insertNode(t,25);
    t = insertNode(t,40);

    inorder(t);

    preorder(t);

    postorder(t);
    
    return 0;
}