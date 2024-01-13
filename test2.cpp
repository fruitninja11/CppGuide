#include<iostream>
#include<string>
using namespace std;

class Base {
public: 
  std::string f1() {
    return "fb";
  }
};

class Derived: public Base {
public:
  std::string f1() {
    return Base::f1() + "ft";
  }
};

int main()
{
    Derived *d = new Derived();
    cout<<d->f1();
    return 0;
}