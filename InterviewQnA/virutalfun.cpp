/*
In C++, the access specifier (private, protected, or public) of the overridden function in the derived class 
does not affect the ability to call it through a base class pointer when the function is marked as virtual.

Since display() is a virtual function in the Base class, and you are calling it via a Base pointer (b), 
the program will look for the most derived version of this function. 
However, the derived class display() is private, so it cannot be called directly from outside the class (like in main()).

But since you're calling it through the base class pointer (b), the program will use the Base class version of display() 
because the Derived class's display() function is inaccessible from the context of the base class pointer.

What the Compiler Does:
Virtual Function and Vtable:
When you declare a virtual function in C++, the compiler creates a vtable (virtual table) for the class. 
This table holds pointers to the virtual functions accessible by objects of that class.
When the Derived class overrides the Base class's display() method, the vtable for Derived is updated to point to Derived::display() instead of Base::display().

Access Control:
The access specifier (private, protected, public) determines where the method can be called from but does not affect how the vtable resolves the function call.
The display() method in Derived is marked as private, which means it cannot be accessed directly from outside the Derived class. However, since the function call is made through a pointer to the Base class and display() is virtual, the vtable mechanism is used.

Function Call Resolution:
When b->display() is called, the program looks up the vtable for the actual object type that b points to. Since b is pointing to a Derived object, the vtable entry for display() will point to Derived::display(), despite the function being private.
The private access specifier does not prevent the vtable from correctly resolving the function call to Derived::display() at runtime. The vtable mechanism operates independently of the access control, meaning the correct overridden function (Derived::display()) is called.

Runtime Behavior:
The call to b->display() results in Derived::display() being executed, and "Derived Display" is printed.

Summary:
Private Access Specifier: While it prevents direct access from outside the class, it does not prevent the virtual function mechanism from working. The derived class's display() method is called through the vtable, even though it is private.
Output: The correct output of the program is "Derived Display" because the Derived class's implementation of display() is invoked.

*/


#include<iostream>
using namespace std;

class Base{
    public:
    virtual void display(){
        cout << "Base Display" << endl;
    }
    
};

class Derived : public Base
{
    private:
    void display(){
        cout << "Derived Display" << endl;
    }
};

int main()
{
    Base *b = new Derived();
    b->display();
    return 0;
}