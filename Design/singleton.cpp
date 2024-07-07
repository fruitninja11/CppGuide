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

class Singleton {
private:
    static Singleton* instance; // Static pointer to hold the single instance

    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton instance created" << std::endl;
    }

public:
    // Static member function to access the single instance
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton(); // Create the instance if it doesn't exist
        }
        return instance;
    }

    // Example method of the singleton class
    void singletonMethod() {
        std::cout << "Singleton method called" << std::endl;
    }
};

// Initialize the static instance pointer
Singleton* Singleton::instance = nullptr;

int main() {
    // Getting the singleton instance
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    // Both obj1 and obj2 point to the same instance
    obj1->singletonMethod(); // Output: Singleton method called
    obj2->singletonMethod(); // Output: Singleton method called

    // Example of how Singleton prevents multiple instances
    // Singleton* obj3 = new Singleton(); // Error: constructor Singleton() is private

    return 0;
}
