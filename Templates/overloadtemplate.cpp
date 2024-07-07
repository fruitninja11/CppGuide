#include<iostream>
using namespace std;

int const& max(int const& a, int const& b)
{
    cout << "max (int, int)" << endl;
    return a>b ? a:b;
}

template <typename t>
t const& max(t const& a, t const& b)
{
    cout << "max (t, t)" << endl;
    return a>b ? a:b;
}

template <typename t>
t const& max(t const& a, t const& b, t const& c)
{
    cout << "max (t, t , t)" << endl;
    return max(max(a,b),c);
}

int main()
{
    ::max(12.0,15.0);//calls template max 
    ::max('a','z');//calls template max 
    ::max(10,20); //calls int max first one
    ::max<>(10,20);//calls template max 
    ::max<double>(10,20); //calls template max 
    ::max(10,20,30); //calls int max first one
    return 0;
}