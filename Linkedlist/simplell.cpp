#include<iostream>
using namespace std;

class Node
{

public:

    int data;
    Node* next;

    //default const
    Node():data(0),next(nullptr){}

    //param const
    Node(int val):data(val),next(nullptr){}

    ~Node(){};
};

class LinkedList
{
private:
    Node* head;

public:
    //Default Constructor
    LinkedList():head(nullptr){};

    /* //insert node at the end of Linkedlist
    void insertNode(int data)
    {
        //create new node
        Node *newNode = new Node;

        //assign head
        if( head == nullptr)
        {
            head = newNode;
            return;
        }

        //traverse at the end of list
        Node* temp = head;
        while (temp->next != nullptr)
        {
            //update temp
            temp = temp->next;
        }

        //we found the last node 
        //now enter the new node to its next
        temp->next = newNode;
        
    } */

    ~LinkedList();
};







int main()
{
    return 0;
}