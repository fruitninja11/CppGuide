//explicit const in cpp
//use of explicit keyword in cpp
// ANs: it avods implicit call to the constructor

#include<iostream>
using namespace std;

class Base
{
private:
    int var_A;
public:
    Base(/* args */){};
    //explicit Base(int var) : var_A(var) {}   // explicit keyword is usedto stop the implicit calling of constructors //code won't compile
    Base(int var) : var_A(var) {}
    void print()
    {
        cout<< var_A << endl;
    }
};

void fun(Base b)
{
    b.print();
}

int main(int argc, char const *argv[])
{
    Base obj1(100); //normal call to contrcutor
    Base obj2 = 20; //implicit call to constructor how? because if we declare a contructor with a parameters and if the type is same i.e. type of parameter then the constrcutor will implicitly call the constructor


    fun(obj1); //normal call to contrcutor
    fun(30);   //implicit call to constructor
    return 0;
}


