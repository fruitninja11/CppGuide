/*
1. std::map is associative container that store elements in key value combination
   where key should be unique, otherwise it overrides the previous value.
2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
3. It store key value pair in sorted order on the basis of key (ascending/decending).
4. std::map is generally used in Dictionay type problems.
*/


#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    map<int, string> mpp;
    string s1 = "Shubham";
    string s2 = "Shubham1";
    string s3 = "Shubham21";
    string s4 = "Shubha";
    string s5 = "Shubham444";

    mpp.insert(make_pair(3,"Cat"));
    mpp.insert(pair<int, string>(4,"dogs"));
    mpp.insert({11,"Simba"});
    
    mpp[s1.length()] = s1;
    mpp[s2.length()] = s2;
    mpp[s3.length()] = s3;
    mpp[s4.length()] = s4;
    mpp[s5.length()] = s5;

    for(const auto& itr : mpp)
    {
        cout << itr.first << "-" << itr.second << endl;
    }
    

    map<string, vector<int>> Map;

    Map["Sam"].push_back(12345);
    Map["Sam"].push_back(3453456);
    Map["Elia"].push_back(22134);

    for(const auto& itr : Map)
    {
        cout << itr.first << endl;

        for (auto &i : itr.second)
        {
            cout << i << endl;
        }
        cout << endl;

    }

    //map<string, vector<int>>::iterator it = Map.find("Sam");

    auto it = Map.find("Sam");

    if (it != Map.end())
    {
        cout << "Found key" << " Sam" << " with value " << endl;
        for (auto &&i : it->second)
        {
            cout << i << endl;
        }
        cout << endl;
        
    }
    else
    {
        cout << "Not present" << endl;
    }
    
    Map.clear();
    mpp.clear();
    return 0;
}