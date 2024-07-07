#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

void createStackObject() {
    MyClass stackObj; // Created on the stack
}

void createHeapObject() {
    MyClass* heapObj = new MyClass(); // Created on the heap
    delete heapObj; // Must be explicitly deleted
}

int main() {
    createStackObject();
    createHeapObject();
    return 0;
}

// Output:
// Constructor called
// Destructor called
// Constructor called
// Destructor called
