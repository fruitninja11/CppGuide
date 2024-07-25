//g++ -std=c++11 -pthread threadcreation.cpp -o threadcreation

#include<iostream>
#include<thread>
using namespace std;

//function pointer
void fun(int x)
{
    cout << x << endl;
}

class Wrapper
{

public:
    //static member function
    static void fun(int x)
    {
        cout << x << endl;
    }

    //non static member function
    void run(int x)
    {
        cout << x << endl;
    }
};




int main()
{
    std::thread t1(fun,10);
    t1.join();

    //lambda at thread creation time
    std::thread t2([](int x)
    {
        cout << x << endl;
    },20);
    t2.join();


    //how to call the funtion of a class using thread
    //create an object since we cant access it without object
    Wrapper obj;

    //pass the address of funtion and object in thread and also parameters if any
    std:: thread t3(&Wrapper::run, &obj, 11);

    //to call static member function
    std:: thread t4(&Wrapper::fun, 12);

    return 0;
}