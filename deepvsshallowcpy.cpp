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
    int *ptr;
    int age;

public:
    Student():ptr(new int(0)),age(0){};

    Student(int ptr1, int age1)
    {
        ptr = new int(ptr1);
        age = age1;
    }

    void setPtr(int ptr1){
        *ptr = ptr1;
    }

    void setage(int age1){
        age = age1;
    }
    void display()
    {
        cout << *ptr << " -> " << age << endl;
    }

    //copy constructor
    Student(const Student &obj)
    {   
        ptr = new int;
        *ptr = *obj.ptr;
        age = obj.age;
    }
    ~Student(){
        cout << "dest" << endl;
    };
};


int main()
{
    Student s1(10,20);
    Student s2 = s1;
    s1.display();
    s2.display();
    s2.setPtr(20);
    s1.display();
    s2.display();

    return 0;
}