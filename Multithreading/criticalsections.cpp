/*
Few important points to remember for "Thread OR Process Synchronisation" is as follows:
1.0 Thread Or Process synchronize to access critical section.
2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.
3.0 Critical section comes into picture when there is a WRITE operation on common variable not read operation.

*/

//g++ -std=c++11 -pthread threadcreation.cpp -o threadcreation

#include<iostream>
#include<thread>
#include <chrono>
using namespace std;

int bankBalance=0;

//function pointer
void addMoney(int amount)
{
    bankBalance+=amount;
}


int main()
{
    std::thread t1(addMoney,100);
    std::thread t2(addMoney,200);
    //wait for thread to complete
    t1.join();
    t2.join();

    cout << bankBalance << endl;

    return 0;
}