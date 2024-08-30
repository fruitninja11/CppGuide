#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
class Pair
{
    public:
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
    Pair<double> p2(10.22,21.45);
    Pair<string> p3("Shubham","Meshram");
    Pair<const char*> p4("Shubham","Meshram");

    p1.display();
    p2.display();
    p3.display();
    p4.display();

    std::vector<Pair<int>> Vec;

    Vec.push_back(Pair<int>(1,21));
    Vec.push_back(Pair<int>(1,25));
    Vec.push_back(Pair<int>(1,12));
    Vec.push_back(Pair<int>(1,2));
    Vec.push_back(Pair<int>(1,1));
    
    sort(Vec.begin(),Vec.end(),[](const Pair<int> &v1, const Pair<int> &v2){
        return v1.second < v2.second;
    });

    for(auto& v : Vec)
    {
        v.display();
    }
    return 0;
}