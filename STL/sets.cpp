/*
set<T> objectname;
1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
2. It is usually implemented using Red-Black Tree /self balancing tree.
3. Insertion, Removal, Search have logarithmic complexity. (log(n))
4. If we want to store user defined data type in set then we will have to provide 
   compare function so that set can store them in sorted order.
5. We can pass the order of sorting while constructing set object.


It stores unique elements and they are stored in sorted order

*/

#include<iostream>
#include<set>
#include<functional>
#include<string>
using namespace std;

class Person
{
private:
    /* data */
public:
    int age;
    string name;

    bool operator <(const Person& rhs) const { 
        return age<rhs.age;
        } 

    bool operator >(const Person& rhs) const { 
        return age>rhs.age;
        } 
};



int main()
{
    set<int> Set = {1,2,3,4,5,1,2,3,4,5};

    for (auto &s : Set)
    {
        cout << s << endl;
    }
    

    //used to store elements in asceding order , is by default
    set<Person,less<Person>> p = {{22,"Shubham"},{21,"Chainika"},{19,"Gaurav"}};
    
    for (auto &s : p)
    {
        cout << s.age  << "<" << s.name << endl;
    }
    
    //used to store elements in descending order
    set<Person , std::greater<Person>> p1 = {{22,"Shubham"},{21,"Chainika"},{19,"Gaurav"}};
    for (auto &s : p1)
    {
        cout << s.age  << "<" << s.name << endl;
    }
}