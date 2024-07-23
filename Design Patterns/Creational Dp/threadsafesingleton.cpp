/*
The given code below is not thread safe. Here we take two threads and try to create objects.
 Since both the threads create objects,which differs from out principle of singleton;

 We have to handle this:
 We use mutex:
 Mutex locks the critical section of the code and unlocks only after going exiting the section.
 It means only one thread can execute crititcal section at a time.

 --01 Double check locking
 Do we need mutex lock all the time here, no we just need it only to create first instance.
 But when the instance is created we dont need lock at all. This ensures lock is put only once.

 Why? Because locks are expensive operations.

*/


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance; 
    static mutex mtx;
    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton instance created" << std::endl;
    }

    Singleton(const Singleton &obj){};
    Singleton& operator=(const Singleton &obj){};

public:

    static Singleton* getInstance() 
    {
        if(instance == nullptr) //--01
        {
            //This ensures that only one thread can execute this block at a time.
            mtx.lock();
            if (instance == nullptr) 
            {
                instance = new Singleton(); // Create the instance if it doesn't exist
            }
            mtx.unlock();
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
mutex Singleton::mtx;

void user1getInstance()
{
    Singleton* obj1 = Singleton::getInstance();
}

void user2getInstance()
{
    Singleton* obj2 = Singleton::getInstance();
}


int main() {

    thread t1(user1getInstance);
    thread t2(user2getInstance);
    
    t1.join();
    t2.join();

    // Example of how Singleton prevents multiple instances
    // Singleton* obj3 = new Singleton(); // Error: constructor Singleton() is private
    Singleton* obj3 = Singleton::getInstance();
    Singleton* obj4 = Singleton::getInstance();
    //*obj4 = obj3;
    return 0;
}