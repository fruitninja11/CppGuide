/*
Polymorphism

Compile time polymorphism (static binding / early binding)
1. function overloading
2. operator overloading

Runtime polymorphism (dynamic binding / lazy binding)
function overriding (using virtual functions)

What happens at run time polymorphism?
1.Whenever any function is declared virtual in a class 
then a static array called virtual table or Vtable is created.

2. This vtable has funtion pointers pointing to the virtual functions

3. Now we should have something to point to the vtable from the class.

4. So, asecret hidden data member is added to the class 
called virtual pointer vptr that points to the vtable

5. The class which has virtual function or the class that is
being derived from a class that has virtual function will have its own vtable.


*/

#include <iostream>
using namespace std;

class Base {
public:
    // Overloaded function in the base class
    void display() const {
        cout << "Display from Base with no parameters" << endl;
    }

    void display(int n) const {
        cout << "Display from Base with integer: " << n << endl;
    }

    // Virtual function in the base class
    virtual void show() const {
        cout << "Show from Base" << endl;
    }

    // Overloaded addition operator in the base class
    Base operator+(const Base& other) const {
        Base result;
        result.value = this->value + other.value;
        return result;
    }

    Base operator-(const Base &temp) const{
        Base result;
        result.value = this->value - temp.value;
        return result;
    }

    // Setter for value
    void setValue(int val) {
        value = val;
    }

    // Getter for value
    int getValue() const {
        return value;
    }

protected:
    int value = 0;
};

class Derived : public Base {
public:


    // if we dont use the using statement the compiler will see only derived display and use that.
    // and even if we pass the int parameters , because the integer 5 can be implicitly converted to a double it will work

    /*
        In C++, when you define a function in a derived class with the same name as one in the base class, 
        all functions with that name in the base class become hidden.
        using Base::display; in the Derived class brings the display methods from the Base class into the scope of the Derived class. 
        This allows the Derived class to inherit and use the overloaded display methods from the Base class.
    */
    // Bring the Base class display methods into the Derived class scope
    using Base::display;

    // Overriding the virtual function in the derived class
    void show() const override {
        cout << "Show from Derived" << endl;
    }

    // Overloading an additional function in the derived class
    void display(double d) const {
        cout << "Display from Derived with double: " << d << endl;
    }

    // Overloaded addition operator in the derived class
    Derived operator+(const Derived& other) const {
        Derived result;
        result.value = this->value + other.value;
        return result;
    }
};

int main() {
    Base b1, b2;
    b1.setValue(10);
    b2.setValue(20);

    Derived d1, d2;
    d1.setValue(30);
    d2.setValue(40);

    Base b3 = b1 + b2; // Calls Base::operator+
    Derived d3 = d1 + d2; // Calls Derived::operator+

    cout << "b1 + b2 = " << b3.getValue() << endl; // Output: 30
    cout << "d1 + d2 = " << d3.getValue() << endl; // Output: 70

    // Calling overloaded functions in the base class
    b1.display();        // Calls Base::display()
    b1.display(5);       // Calls Base::display(int)

    // Calling the overridden function
    Base* b = &d1;
    b->show();           // Calls Derived::show()
    
    // Directly calling functions from the Derived class object
    d1.display();         // Calls Base::display()
    d1.display(5);        // Calls Base::display(int)
    d1.display(5.5);      // Calls Derived::display(double)

    return 0;
}
