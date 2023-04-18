#include<bits/stdc++.h>
using namespace std;

//Algorithms, Containers, Functions, Iterators


/*
Pair is used to combine together two values that may be of different data types. Pair provides a way to store two heterogeneous objects as a single unit. 
It is basically used if we want to store tuples. 
The pair container is a simple container defined in <utility> header consisting of two data elements or objects. 

The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
Pair can be assigned, copied, and compared. The array of objects allocated in a map or hash_map is of type ‘pair’ by default 
in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
To access the elements, we use variable name followed by dot operator followed by the keyword first or second.
Syntax: 

pair <data_type1, data_type2> Pair_name
*/
//Pairs
void definePair()
{
    pair <int, int> p1 = {1,3};
    cout<< p1.first << " " << p1.second;

    pair <int, pair<int, int>> p2 = {11, {22, 33}};
    cout<< p2.first << " " << p2.second.first << " " <<p2.second.second;

    pair <int , int> arr[] = { {1,2}, {5,6}, {7,9}};
    cout << arr[0].first << " " << arr[0].second ;
}


/*
Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. 
Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, 
as sometimes the array may need to be extended. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

What is std::vector in C++?
std::vector in C++ is the class template that contains the vector container and its member functions. 
It is defined inside the <vector> header file. The member functions of std::vector class provide various functionalities to vector containers. 
Some commonly used member functions are written below:

Iterators
begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/

//Vector
void defineVector()
{
    //creates empty conatiner
    vector <int> v;

    //takes '1' into empty vector 
    v.push_back(1);

    //dynamically increases size and takes '2'
    //generally faster than push_back(); similar to push_back();
    v.emplace_back(2);

    vector <pair<int, int>> vec;

    vec.push_back({1,2});

    // there is a syntax change in emplace_back since emplace_back understands the datatype is list 
    vec.emplace_back(1,2);

    //if we want to declare a vector container of size '5' containing values as '100'
    vector<int> v1(5, 100);

    //declare a vector of size 5 with garbage values(depends on compiler) or zero (0)
    vector<int> v(5);

    //if we want to copy the container to another container
    vector<int> v2(v1);

    //Access elements in vector
    cout << v[0];

    //another method (not used)
    cout<<v.at(0);

    //iterator method
    //it points to the memory address where the vector is stored
    vector<int>::iterator itr = v.begin();
    
    //works like an array
    itr++;
    itr = itr +2;

    //since v.begin() gives memory address, to access value at memory (which is contiguous memory) we use '*'
    cout<< *(itr) << " ";

    //end will not point at last location but at a location right after last element, we use itr-- in order to access last element through v.end()
    //vector<int>::iterator it =v.end();

    //reverse end is one memory location before first element
    //vector<int>::iterator it = v.rend();

    //reverse begin starts from last element of vector
    //vector<int>::iterator it = v.rbegin();

    //vector<int>::iterator it = v.back();

    //printing a vector
    for (vector <int>::iterator it = v.begin(); it !=v.end(); it++)
    {
        cout << *(it) << " ";
    }

    //another way, auto assigns AUTOMATIC datatype to the variable
    for (auto it = v.begin(); it !=v.end(); it++)
    {
        cout << *(it) << " ";
    }

    //for each loop (iterates on datatype)
    for(auto it : v){
        cout << it << " ";

    }
    
}


//List
void definelist()
{
    list<int> ls;

    ls.push_back(2); //{2}
    ls.emplace_back(3); //{2,3}
    ls.push_front(5); //{5,2,3}
    ls.emplace_front(); //{2,3}

    //other function same as vector
    //insert in a vector is costlier than list, since list does an internal operation
    //doubly linked list is maintained for a list whereas for a vecor single linked list is maintained
}
int main()
{
    definePair();
    return 0;
}
