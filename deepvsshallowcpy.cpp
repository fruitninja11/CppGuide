#include<iostream>
using namespace std;

//deep copy vs shallow copy 
// when should we use compiler's copy constructor or our own copy constructor?
// compiler's copy assignment operator or our own copy assignment operator

class Wrapper
{
private:
    int* ptr;
    int data;
public:
    Wrapper():ptr(new int(0)),data(0){}; //defaut constructor
    Wrapper(int ptr1,int data1) //parameterized constructor
    {
        *ptr = ptr1;
        data = data1;
    }
    
    //copy constructor
    Wrapper(Wrapper &obj)
    {
        ptr = new int;
        *ptr = *obj.ptr;
        data = obj.data;
    }

    void printobj()
    {
        cout << *ptr << data << endl;
    }

    ~Wrapper(){
        delete ptr;
    }
};


int main()
{
    Wrapper w1(10,20);
    Wrapper w2 = w1;
    w1.printobj();
    w2.printobj();
    
    return 0;
}