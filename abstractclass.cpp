#include<iostream>
using namespace std;


//An abstract class in cpp is a class which has atleast one pure virtual function
//Abstract classes are designed to be used as base classes or interfaces, and they serve as templates for deriving concrete (non-abstract) classes.
/*
A pure virtual function is a special type of virtual function in C++ that is declared in an abstract base class but has no implementation in that base class.
Pure virtual functions are also known as abstract methods. These functions serve as a declaration or contract that any derived (sub) class must provide an implementation for.

Any class that derives from AbstractBase must provide an implementation for this function, or it will also be considered an abstract class, and you won't be able to create instances of it.
If a class inherits from an abstract class with pure virtual functions and doesn't provide implementations for those functions, 
it becomes an abstract class itself, and you cannot create instances of it either. Pure virtual functions are used to define 
a common interface in the base class while ensuring that derived classes implement the required functionality. 
This is a fundamental concept in achieving polymorphism and creating hierarchies of related classes in C++.
*/
class Base{

private:

public:

//abstract method 
//pure virtual function add '= 0'
virtual void fun() = 0;

//concrete method with implementation
void printInfo()
{
    cout << "This is sample info"  << endl;
}

};

class Derived : public Base
{
private:
    /* data */
public:
    void fun(){
        cout<< "in fun derived"<< endl;
    };
};



int main()
{
    Base *b = new Derived();
    //Base b1; 
    //We cannot create an object of an abstract class because a pure abstract class has no 
    //implementation of the functions and hence it has no meaning creating an object

    return 0;
}