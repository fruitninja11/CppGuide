/*
Mutex: Mutual Exclusion

RACE CONDITION:
0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition.


When working with multithreading in programming, one of the crucial moments is knowing how to secure certain parts 
of the code from being accessed by multiple threads simultaneously, which can lead to serious problems. 
For that purpose, we use Mutex. 

*/

//g++ -std=c++11 -pthread threadcreation.cpp -o threadcreation

#include<iostream>
#include<thread>
#include <chrono>
#include<mutex>
using namespace std;

int amount=0;
std::mutex m;


//function pointer
void fun()
{
    cout << "Function called" << endl;
    m.lock();
    amount++;
    m.unlock();
}

void fun1()
{
    //cannot be unlocked manually
    std::lock_guard<mutex> funlock(m);
    cout << "Function called" << endl;
    amount++;
   
}


int main()
{
    std::thread t1(fun);
    std::thread t2(fun);
    std::thread t3(fun);
    std::thread t4(fun);

    //wait for thread to complete
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << amount;
    return 0;
}