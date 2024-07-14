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

    //insert node at the end of Linkedlist
    void insertNode(int data)
    {
        //create new node
        Node *newNode = new Node(data);

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
        
    } 


    void deleteNode(int offset)
    {
        //check if list is empty
        if(this->head == nullptr)
        {
            cout << "List Empty" << endl;
            return;
        }

        //find if the entered offset is valid
        int length=0;
        Node* temp1=head;
        while (temp1 != nullptr)
        {
            temp1 = temp1->next ;
            length++;
        }
        
        //if entered offset is greater than length
        if(offset > length ||  offset < 1)
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

        Node *prev = nullptr;

        for (int i = 1; i < offset; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = temp->next;
        delete temp;
    }


    void insertPos(int pos, int val)
    {
        Node *newnode = new Node(val);

        if(pos == 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        // Traverse to the position before where the new node will be inserted
        int length=0;
        Node* temp1 = head;
        while (temp1 != nullptr)
        {
            temp1 = temp1->next ;
            length++;
        }

        if (pos > length || pos < 1)
        {
            cout << "Position out of range" << endl;
            return;
        }
            
        Node* temp = head; 

        for(int i=1; i< pos-1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;

    }

    // Function to print the list (for testing purposes)
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList(){
        Node* temp = head;
        while (temp != nullptr)
        {
            temp = head;
            head = head->next;
            delete head;
        }
        
    };
};




int main()
{
    LinkedList list;
    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.insertNode(40);
    list.printList();
    list.insertPos(1,9);
    list.printList();
    list.insertPos(3,11);
    list.printList();
    list.deleteNode(3);
    list.printList();
    return 0;
}