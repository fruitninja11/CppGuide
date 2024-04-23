/*
The Singleton design pattern ensures that a class has only one instance and provides a global point of access to that instance. 
This pattern is commonly used in scenarios where you need to control access to a shared resource or manage a single, unique object throughout the application.

Private Constructor: The constructor of the class is made private to prevent instantiation of the class from outside. 
This means that the class cannot be directly instantiated using the new keyword.


Static Member Function: The class provides a static member function getInstance() that returns a reference to the single instance of the class. 
This function is used to access the singleton object.


Static Local Variable: Inside the getInstance() function, a static local variable of type Singleton is declared. 
This variable is initialized the first time the function is called, and subsequent calls to the function return the same instance.


Singleton Object: The singleton object is created on the first call to getInstance() and remains alive until the program terminates. 
This ensures that there is only one instance of the class throughout the program's lifetime.

Private Destructor: The destructor of the class is made private to prevent deletion of the singleton object from outside the class. 
This ensures that the singleton object cannot be destroyed inadvertently.


Deleted Copy Constructor and Assignment Operator: The copy constructor and assignment operator are deleted to prevent copying of the singleton object. 
This ensures that there is only one instance of the class and it cannot be copied or assigned to another object.

    +-----------------------------------+
    |           Singleton              |
    +-----------------------------------+
    |  + getInstance(): Singleton&     |
    +-----------------------------------+
    |  - Singleton()                   |
    |  - ~Singleton()                  |
    |  - Singleton(const Singleton&)   |
    |  - operator=(const Singleton&)   |
    +-----------------------------------+
    |  - static instance: Singleton    |
    +-----------------------------------+

*/



#include <iostream>

class Singleton {
public:
    // Static method to access the singleton instance
    static Singleton& getInstance() {
        // Create the singleton instance if it doesn't exist
        static Singleton instance;
        return instance;
    }

    // Other member functions and variables can be added as needed

private:
    // Private constructor to prevent instantiation from outside
    Singleton() {
        // Constructor code here
    }

    // Private destructor to prevent deletion from outside
    ~Singleton() {
        // Destructor code here
    }

    // Disable copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    // Access the singleton instance
    Singleton& singletonInstance = Singleton::getInstance();

    // Use the singleton instance
    // ...

    return 0;
}
