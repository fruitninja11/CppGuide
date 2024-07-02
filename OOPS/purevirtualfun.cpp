/*
0. If some class can have only signature of function but not the body then we use pure virtual functions.
1. Sometimes in Base class we know the function name but not the definition of the function, so we want Derived classes to provide the definition of the function.
2. We can actually give body of pure virtual function.
3. If you have pure virtual function in your class, it means that class is an Abstract class and you can't create an object of that class. (But pointers and Reference can be created)

USE CASE:
1. Used to create abstract classes, which helps in creating interfaces (APIs)

*/
#include<iostream>
using namespace std;

//Abstract class
class Base
{
private:
    /* data */
public:
    /* pure virtual fun*/
    virtual void fun()=0;
};

//point 3 
void Base :: fun()
{
    cout << "example of how you can give body to pure virtual function" << endl;
}


class Derived : public Base
{
private:
    /* data */
public:
    void fun()
    {
        cout << "Derived Function called";
    }
};


int main()
{
    Derived d;
    //Base b; //not possible;
    Base *ptr;
    Base &ref = d;

    return 0;
}


