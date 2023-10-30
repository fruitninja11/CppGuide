#include<iostream>
#include<thread>
using namespace std;

void fun1()
{
    cout << "Some task1" << endl;
}

void fun2()
{
    cout << "Some task2" << endl;
}

int main()
{
    std::thread thread1(fun1);
    std::thread thread2(fun2);

    thread1.join();
    thread2.join();

    std::cout << "Main thread: All tasks completed." << std::endl;
    return 0;
}
