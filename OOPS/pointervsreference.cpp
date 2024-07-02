// difference between reference and pointer


#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &ref = i; //reference
    int *ptr = &i; //pointer

    cout << &i << "\n" << &ref << "\n" << &ptr << endl;
    return 0;
}

//-----------------------------------------
//memory address : refrence dosnt have its own address, pointer has
// reassignment is not possible in reference it is tightly bound 
// reference cannot be NULL(empty), pointer can be
// Arithmatic Operations are not possible in reference


//When to use Reference
/*
1. pass big objects;
2. to avoid object slicing
3. to modify local variable of caller function
4. to achieve run time polymorphism
5. copy constructor
*/


//when to use pointer
/*
used in algoritms and data structures like linked-list, tree, graph
cause we can put NULL or nullptr
sometimes we use pointers to point to some other node or variable
*/