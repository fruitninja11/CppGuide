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


    void deleteNode(int offset)
    {
        //find if the entered offset is valid
        int length=0;
        while (head != nullptr)
        {
            head = head->next ;
            length++;
        }
        
        //if entered offset is greater than length
        if(offset > length)
        {
            cout << "Index out of range" << endl;
            return;
        }

        Node *temp = head;
        //if offset is first element
        if(offset == 1)
        {
            head = head->next;
            delete temp;
            return;
        }

        Node *prev = head;
        //we have to traverse list so that we can got to that index
        int i =0;

        //until we reach that offset store previous address in prev
        while (i != offset)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }

        //after this loop we have reached the node we want to delete
        // now store the address of next in prev of next;
        prev->next = temp->next;

        //delete the current holding node of a

        delete temp;
        
    }


    void insertPos(int pos)
    {
        Node *newnode = new Node;

        if(pos == 1)
        {
            newnode->next = head;
            head = newnode;
        }
    }

    ~LinkedList(){};
};







int main()
{
    return 0;
}