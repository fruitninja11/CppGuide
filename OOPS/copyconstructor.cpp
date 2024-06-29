#include <bits/stdc++.h>
using namespace std;


class Base{
    private:
    char name[10];
    int age;

    public:
    
    Base()
    {
        cout << "Default constructor" << endl;
    }

    Base(const char* name, int age)
    {
        // Ensure name doesn't exceed the size of the array
        // Copy the provided name into the class member 'name'
        strncpy(this->name, name, sizeof(name)-1);
        this->name[sizeof(name)-1]='\0';
        
        //this is a pointer variable that points to current object
        this -> age = age;
    }

    //copy constructor
    /*
        when i send Base obj in copy constructor what it means is
        i am sending pass by value to the copy constructor
        now since pass by value creates a copy, when it will try to 
        create copy it will again call copy constrctor. 
        now infinite loop will be created

        but when i send an object by reference it sends the actual object (obj1)
        so same memory is referenced by obj1 and temp

    */
    Base (Base& tempobj)
    {
        strncpy(this->name, tempobj.name, sizeof(tempobj.name)-1);
        this->name[sizeof(tempobj.name)-1]='\0';

        this->age = tempobj.age;
    }

    // Method to display member values
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    ~Base()
    {
        cout << "Default Destructor" << endl;
    }

};

int main() {
    // Creating an object of Base class using parameterized constructor
    Base obj1("John", 25);

    //default copy constructor is called but we have written our own
    Base obj2(obj1);
    
    obj1.display(); // Displaying member values
    obj2.display();
    
    return 0;
}