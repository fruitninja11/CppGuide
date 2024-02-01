//how delete[] know how many objects to delete?
// 1.over allocation 
// what over allocation does is it creates an array with extra word size 
// creates an array with over allocation and then the pointer of object (bp) is pointed to
// the start of memory where object starts storing
//uses "placement new" operators
//and this will hold the size of n (size of array (hre array of objects))
// 

//2.Associative array
//same but creates a normal array without adding the size n 
//but will also create an associative array where size will be stored
// then while deleting the associative array is called and n value is fetched
#include <iostream>

int const n =10;

class Base{
public:
    int var;
};

int main()
{
    Base *bp = new Base[n];
    delete[] bp;
    return 0;
}