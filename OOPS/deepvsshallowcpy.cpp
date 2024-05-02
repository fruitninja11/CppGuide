#include<iostream>
#include<string.h>
using namespace std;

//deep copy vs shallow copy 
// when should we use compiler's copy constructor or our own copy constructor?
// compiler's copy assignment operator or our own copy assignment operator

/*
-------------------------|
|   b1.age =20           |
|   b1.ptr = 2000        |
|   b1.*ptr = 10         |
--------------------------

---Shallow Copy-------

-------------------------|
|   b2.age =20           |
|   b2.ptr = 2000        |
|   b2.*ptr = 10         |
--------------------------

*/

class Student
{
private:
    char *name;
    int age;

public:
    Student():name(nullptr),age(0){};

    Student(const char* ptr1, int age1)
    {
        this->name = new char(strlen(ptr1)+1); //+1 for null character
        strcpy(this->name,ptr1); // Copy ptr1 into name

        age = age1;
    }

    //copy constructor
    Student(const Student &obj)
    {   
        this->name = new char(strlen(obj.name)+1); //+1 for null character
        strcpy(this->name,obj.name); // Copy obj.name into name
        age = obj.age;
    }

    // Destructor
    ~Student() {
        if (name != nullptr) // Check if name is not null
            delete[] name; // Free the dynamically allocated memory for name
        cout << "Destructor called" << endl;
    }

     // Display Function
    void display() {
        cout << name << " -> " << age << endl;
    }

    // Setter for name
    void setName(const char* ptr1) {
        if (this->name != nullptr) // Free existing memory if any
            delete[] this->name;
        this->name = new char[strlen(ptr1) + 1]; // Allocate memory for name
        strcpy(name, ptr1); // Copy ptr1 into name
    }

    // Setter for age
    void setAge(int age1) {
        age = age1;
    }

};


int main()
{
    Student s1("Shubham",20);
    Student s2 = s1;
    s1.display();
    s2.display();
    s2.setName("Gaurav");
    s1.display();
    s2.display();

    return 0;
}