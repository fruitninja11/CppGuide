#include<iostream>
using namespace std;

template <typename T>
class Pair
{
    private:
    T first;
    T second;

    public:
    Pair(T f, T s):first(f),second(s){};

    void display()
    {
        cout << first << " " << second << endl; 
    }

};

int main()
{
    Pair<int> p1(1,2);
    Pair<int> p2(10.22,21.45);
    Pair<string> p3("Shubham","Meshram");
    Pair<const char*> p4("Shubham","Meshram");

    p1.display();
    p2.display();
    p3.display();
    p4.display();

    return 0;
}