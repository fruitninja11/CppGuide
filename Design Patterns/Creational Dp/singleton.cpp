/*
Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

1. Ensure that a class has just a single instance. Why would anyone want to control how many instances a class has? 
The most common reason for this is to control access to some shared resource—for example, a database or a file.

2. Provide a global access point to that instance. Remember those global variables that you (all right, me) used to store some essential objects?
While they’re very handy, they’re also very unsafe since any code can potentially overwrite the contents of those variables and crash the app.
Just like a global variable, the Singleton pattern lets you access some object from anywhere in the program. However, it also protects that instance from being overwritten by other code.

All implementations of the Singleton have these two steps in common:

1. Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
2. Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.
If your code has access to the Singleton class, then it’s able to call the Singleton’s static method. So whenever that method is called, the same object is always returned.

*/



/*
Private Constructor:

The constructor of the Singleton class is private, preventing direct instantiation from outside the class. This ensures that the class can only be instantiated from within its own member functions.
Static Member Instance:

static Singleton* instance;: This is a static pointer to hold the single instance of the Singleton class.
getInstance Method:

static Singleton* getInstance(): This static member function is used to access the single instance of the Singleton class.
It checks if instance is nullptr (i.e., if the instance has not been created yet), and if so, it creates a new instance.
If instance already exists, it simply returns the existing instance.
Usage in Main Function:

In main(), Singleton::getInstance() is called multiple times (obj1 and obj2), demonstrating that both obj1 and obj2 point to the same instance of Singleton.
This ensures that there is only one instance of Singleton throughout the program.


*/


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

Preventing Multiple Instances:
Attempting to create a new instance of Singleton using new Singleton() outside the getInstance() method results in a compile-time error due to the private constructor.

Use Cases:
Configuration Managers: Providing a single point of access to configuration settings across an application.
Logging Services: Ensuring that all log messages go through a single instance of a logging service.
Resource Managers: Managing limited resources (like database connections) where only one instance is necessary.
Benefits:
Global Access: Provides a single global point of access to the instance of the class.
Lazy Initialization: The instance is created only when getInstance() is called for the first time, promoting efficient memory usage.
Thread Safety: Can be enhanced to support thread-safe initialization in multithreaded environments.

*/ 



#include <iostream>
using namespace std;

class Singleton {
private:
    // Private constructor to prevent instantiation from outside the class
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static member to hold the single instance
    static Singleton* instance;

public:
    // Static method to provide access to the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void displayMessage() {
        cout << "Hello from Singleton!" << endl;
    }

    void singletonmethod()
    {
        cout << "Singleton method called" << endl;
    }
};

// Initialize static member
/*
Why Not Initialize Inside the Class?
C++ requires that the static member be defined outside the class because the class definition is only a blueprint for objects. 
Static members, being shared among all instances, must have a single definition in a separate compilation unit to ensure that there is one and only one instance of the static member.
*/
Singleton* Singleton::instance = nullptr;

int main() {
    // Accessing the Singleton instance
    Singleton* s1 = Singleton::getInstance();
    s1->displayMessage();

    Singleton* s2 = Singleton::getInstance();
    s2->displayMessage();

    // Verify that both instances are the same
    if (s1 == s2) {
        cout << "Both instances are the same." << endl;
    }

    return 0;
}

