#include<iostream>
using namespace std;

//what is strucutal padding and packing?
// its a way to speedup cpu optimization
//process of adding some bits (or padding) to size of class or struct is padding

//1 word is 4 bytes in 32bit processor (1 page size)
//1 word is 8 bytes in 64 bit processor

//pages in hard drive
//segments in RAM

//#pragma pack(1) 
//use this to avoid padding
struct base
{
    char a;
    char b;
    int i;
};
// memory layout -->  |a|b|-|-|i|i|i|i|--
//                     0 1 2 3 4 5 6 7
struct base_new
{
    char a;
    char b;
    int i;
    char c;
};
//memory layout -->  |a|b|-|-|i|i|i|i|c|-|-|-|
//                    0 1 2 3 4 5 6 7 8 9 10 11


int main()
{
    cout<< sizeof(base) << "base size";
    cout<< sizeof(base_new) << "new base size";
    return 0;
}