#include<iostream>
using namespace std;

class Emp
{
private:
    /* data */
    int id;
    int sal;
public:
    Emp(/* args */):id(1),sal(100){};
    
    int raiseSal(int sal)
    {
        sal = sal +100;
        return sal;
    }

    void fun()
    {
        cout << "this is base class";
    }
    
    //a virtual pointer is added and it will point to the vtable
    //hidden data member
    virtual void fun_virtual()
    {
        cout << "this is base class";
    }

    ~Emp(){
        cout << "\nthis is base dest";
    };
};

class Engineer : public Emp
{
public:
    Engineer(/* args */){};
    int raiseSal(int sal)
    {
        sal = sal +10000;
        return sal;
    }
    
    void fun()
    {
        cout << "this is derived class";
    }

    void fun_virtual()
    {
        cout << "\nthis is derived class";
    }
    ~Engineer(){
        cout << "\nthis is derived dest";
    };
};

int main()
{
    Emp* err = new Engineer; //upcasting -> pointer base class and object of derived class
    err->fun();
    err->fun_virtual();
    delete err;
    return 0;
}



