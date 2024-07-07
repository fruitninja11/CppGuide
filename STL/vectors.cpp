/*
std::vector<T>

1. std::vector is a sequence container and also known as Dynamic Array or Array List.
2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

ELEMENT ACCESS
at(), [], front(), back(), data()

MODIFIERS:
insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

*/

#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> vec;
    vec.reserve(100); // to avoid doubling of vector capacity when the limit is reached
    vector<int> vec1 = {1,2,4,5,6}; //initilizer list
    vector<int> vec2 {1,2,4,5,6}; //uniform initialization

    return 0;
}