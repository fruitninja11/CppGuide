/*
1. Condition variables allow us to synchronise threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronise two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition

*/
//g++ -std=c++17 -pthread conditionvar.cpp -o cvar


/*
Heres what happens in the code
1. the threads t1 and t2 call their respecive functions
2. while true is added in both the functions because we have to check everytime and wait everytime
3. whichever threads executes first acquires the mutex and locks it and checks the condition wait and if conditons are
    satisfied goes furthur and prints and notifies the other thread to check its wait condition


*/
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::condition_variable cv;
std::mutex mtx;
unsigned int num=1;
unsigned int max=10;


void printEven()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]{ return num%2==0 || num > max; });  // Wait until num is even or exceeds max
        if(num > max)  break;   // Check if num exceeds max
        std::cout << num << std::endl; 
        num++;
        cv.notify_one();    
    }
    cv.notify_one();    // Notify the other thread to check termination condition
    
}


void printOdd()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]{ return num%2==1 || num > max; });   // Wait until num is odd or exceeds max
            if(num > max)  break;   // Check if num exceeds max
            std::cout << num << std::endl; 
            num++;
            cv.notify_one();
    }
    cv.notify_one();    // Notify the other thread to check termination condition
}



int main()
{
    std::thread t1(printEven);
    std::thread t2(printOdd);
    t1.join();
    t2.join();
    return 0;
}