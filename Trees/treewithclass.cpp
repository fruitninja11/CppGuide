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

    void printleftview(TreeNode *node)
    {
        if(node != nullptr)
        {
            cout << node->value << endl;
            printleftview(node->left);
        }
    }

    void printrightview(TreeNode *node)
    {
        if(node != nullptr)
        {
            cout << node->value << endl;
            printrightview(node->right);
        }
    }

    bool searchNode(TreeNode *node , int key)
    {
        if(node == nullptr)
            return false;
        
        if(key < node->value)
        {
            return searchNode(node->left,key);
        }
        else if(key > node->value)
        {
            return searchNode(node->right,key);
        }
        else
        {
            return true;
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

    void printleftside()
    {
        printleftview(node);
    }

    void printrightside()
    {
        printrightview(node);
    }

    void search(int key)
    {
        if (searchNode(node,key))
        {
            cout << " Key Present" << endl;
        }
        else{
            cout << " Key Not Present" << endl;
        }
        
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
    //tree.inorder();
    //tree.printleftside();
    //tree.printrightside();
    tree.search(232);
    return 0;
}
