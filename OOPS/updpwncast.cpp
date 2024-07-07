/*
Upcasting is a process of pointing to derived classes using a base class pointer
In function overriding we do that.

Downcasting is the process of pointing to bbase class using a derived class pointer
This happens using dynamic cast

*/

#include<iostream>
using namespace std;

class Base
{
private:
    /* data */
public:
    virtual void show()
    {
        cout << "Base show";
    }
};

class Derived : public Base
{
private:
    /* data */
public:
    void show() override
    {
        cout << "Derived show" << std::endl;
    }
};


int main()
{
    Base *bptr = new Derived(); //implicit upcasting
    bptr->show();

    // Downcasting
    Derived *dptr = dynamic_cast<Derived*> (bptr);

    if (dptr) {
        //dptr->specificFunction(); // Safe to call specific function
        std::cout << "Downcasting done" << std::endl;
    } else {
        std::cout << "Downcasting failed" << std::endl;
    }

    delete bptr;
    return 0;
}