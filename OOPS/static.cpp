/*
Static variables and fucntions that are global only have file scope.

Use Cases of Static in C++:
Singleton Pattern: Using a static member function to access a single instance of a class.

Counters and Flags: Maintaining state across function calls, such as counting function invocations.

Utility Functions: Declaring utility functions that do not require an object context.

Memory Management: Allocating memory once for a class rather than per instance.

Internal Linkage: Restricting visibility of global variables and functions to their translation units.

*/

#include<iostream>
using namespace std;

static int globalVar = 10; // Static global variable

void counter() {
    static int count = 0; // Static variable initialization
    count++;
    cout << "Count: " << count << endl;
}

class MyClass {
public:
    static int staticVar; // Static member variable declaration
    static void staticFunction() { // Static member function definition
        cout << "Static Function" << endl;
    }
};

int MyClass::staticVar = 0; // Static member variable initialization


int main() {
    counter(); // Output: Count: 1
    counter(); // Output: Count: 2
    counter(); // Output: Count: 3
    MyClass obj1, obj2;
    obj1.staticVar = 10;
    obj2.staticVar = 20;
    cout << "obj1.staticVar: " << obj1.staticVar << endl; // Output: 20
    cout << "obj2.staticVar: " << obj2.staticVar << endl; // Output: 20

    MyClass::staticFunction(); // Output: Static Function

    return 0;
}