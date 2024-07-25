/*
JOIN NOTES
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
1. Double join will result into program termination.
2. If needed we should check thread is joinable before joining. ( using joinable() function)

DETACH NOTES
0. This is used to detach newly created thread from the parent thread.
1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
   double detach() will result into program termination.
2. If we have detached thread and main function is returning then the detached thread execution is suspended.

NOTES:
Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will 
terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.
*/


//g++ -std=c++11 -pthread threadcreation.cpp -o threadcreation

#include<iostream>
#include<thread>
#include <chrono>
using namespace std;

//function pointer
void fun()
{
    cout << "Function called" << endl;
    //thread sleeps for 4 seconds
    std::this_thread::sleep_for(chrono::seconds(4));
}


int main()
{
    std::thread t1(fun);

    //wait for thread to complete
    t1.join();


    //check if thread is joinable or not
    if (t1.joinable()) 
    {
        t1.join();
    }
    
    std::thread t2(fun);
    t2.detach();

    return 0;
}