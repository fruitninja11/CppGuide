/*
Here we have created two simple classes
one has a basic definition of tree
BST is how we need a binary search tree to be
We can create different binary trees using Tree node definition;

*/


#include<iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    
    
    TreeNode(int val):value(val),left(nullptr),right(nullptr){};
    ~TreeNode(){
        delete left;
        delete right;
        left = right = nullptr;
    };
};


class BST 
{
private:
    TreeNode *node;

    TreeNode* insertNode(TreeNode *node, int value)
    {
        if(node == nullptr)
        {
            return new TreeNode(value);    //this is possible since there is a param const in the TreeNode class
        }

        if (value < node->value)
        {
            node->left = insertNode(node->left,value);
        }
        
        if (value > node->value)
        {
            node->right = insertNode(node->right,value);
        }
        return node;
    }

    void inorder(TreeNode *node)
    {
        if(node != nullptr)
        {
            inorder(node->left);
            cout << node->value << endl;
            inorder(node->right);
        }
    }

    void preorder(TreeNode *node)
    {
        if(node != nullptr)
        {
            cout << node->value << endl;
            preorder(node->left);
            preorder(node->right);
        }
    }


    void postorder(TreeNode *node)
    {
        if(node != nullptr)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << endl;
        }
    }

public:

    BST():node(nullptr){}

    ~BST()
    {
        delete node;
        node = nullptr;
    }

    void insert(int value)
    {
        node=insertNode(node, value);
    }

    void inorder()
    {
        inorder(node);
    }

};


int main()
{
    BST tree;

    tree.insert(22);
    tree.insert(12);
    tree.insert(8);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(40);

    
    tree.inorder();

    return 0;
}
