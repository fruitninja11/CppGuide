/*
Create a map from vectors where vector is an array of strings a
key -> count of string characters
value-> actual string

In C++, the size_t type is often used instead of int for representing sizes and lengths

When you insert multiple strings with the same size into a std::map<size_t, std::string>, the behavior you observe is due to how std::map handles keys and values. Here’s a detailed explanation of what happens:

std::map Basics
Unique Keys: A std::map maintains unique keys. This means that if you try to insert an element with a key that already exists in the map, 
the new value will replace the existing value associated with that key.

Insertion: When you insert an element into the map using the operator[] or insert method, the map checks if the key already exists.

Replacement: If the key exists, the value is updated/replaced. If the key does not exist, a new key-value pair is added.
*/


#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;


map<size_t, string> vectomap( vector<string> vec)
{
    map<size_t, string> mpp;

    for(const auto &str : vec)
    {
        mpp[str.size()] =  str;   //map[str.length()] alternatively 
    }

    for (const auto &itr : mpp)
    {
        cout << "Key :" << itr.first  << ", Value:" << itr.second << endl;
    }
    


    return mpp;
}


int main()
{
    //create an vector of strings
    vector<string> vec;

    vec.push_back("Hey");
    vec.push_back("Man");
    vec.push_back("This");
    vec.emplace_back("was");
    vec.emplace_back("asked");
    vec.emplace_back("in");
    vec.emplace_back("LGSoft");

    map<size_t, string> mpp = vectomap(vec);

    return 0;
}