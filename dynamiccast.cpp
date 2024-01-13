// duynamic_cast< new_type> (expression)


#include<iostream>
#include<exception>
using namespace std;

class Base
{
    virtual void print() // by adding virtual we make the function polymorphic //runti,e check possible
    {
        cout << "Base" << endl;
    }
};

class DerivedA : public Base
{
    void print()
    {
        cout << "DerivedA" << endl;
    }
};

class DerivedB : public Base
{
    void print()
    {
        cout << "DerivedB" << endl;
    }
};


int main()
{
    DerivedA d1;

    Base *bp = dynamic_cast<Base*>(&d1); //typecast of derivedA object into base pointer //basepointer is holding derivedA object

    //DerivedB *d2 = dynamic_cast<DerivedB*>(bp); //problem

    DerivedA *d2 = dynamic_cast<DerivedA*>(bp); //no problem because type casting to original derived class

    if (d2 == nullptr)
    {
        cout << "NULL" << endl;
    }
    else
        cout << "NOT NULL" << endl;
    
    try
    {
        //DerivedB &ref = dynamic_cast<DerivedB&>(d1);
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        //cout << e.what() << endl;
    }
    
    return 0;
}

// work only on polymorphic base class (atleast one virtual function)
// it has a run-time overhead since it checkds at run time
// mainly used for checking correct downcast


