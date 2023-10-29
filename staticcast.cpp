#include<iostream>
using namespace std;

class Base
{
private:
    int x;
public:
    Base(/* args */){};
    Base(int x):x{x}{}
    friend void fun(Base &);
    ~Base(){};
};

void fun(Base &obj)
{
    cout << obj.x << endl;
    obj.x =20;
}

int main()
{
    Base b(100);
    fun(b);

    int a =100;
    const int *ptr1 = &a;// const integer pointer
    int *ptr2 = const_cast<int *>(ptr1); //cast away the constantness of ptr1 and dereferencing it and then pointing to ptr2
    *ptr2 = 200; //valid code, will not be a valid code if int a is const variable 
    return 0;
}
