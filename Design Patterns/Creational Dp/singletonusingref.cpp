/*
Static Local Variable Initialization:

In C++, a static local variable inside a function is initialized only once, the first time control passes through its declaration. 
The variable retains its value between function calls.The initialization of a static local variable is thread-safe in C++11 and later, 
meaning that if multiple threads try to initialize it at the same time, the compiler ensures that only one thread will perform the initialization.


First Call to getInstance:

When getInstance is called for the first time, the static local variable instance is created and initialized.
The constructor of the Singleton class is called, and the message "Singleton instance created" is printed.
The function then returns a reference to this newly created instance.
Subsequent Calls to getInstance:

On subsequent calls to getInstance, the static local variable instance is already initialized.
The function simply returns a reference to the existing instance without creating a new one.
*/

#include<iostream>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton Instance created" << endl;
    }

public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton &) = delete;

    Singleton& operator=(const Singleton &) = delete;
    
    void anyMethod()
    {
        cout << "Mehtod Called" << endl;
    }
};

 int main()
 {
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();
    Singleton &s3 = s1;
    //Singleton s4 = s1;
    //s2=s1;
    cout << &s1<< endl;
    cout << &s2<< endl;
    return 0;
 }


