/*
How to return array from a function in cpp?

1. if we make array as static.
    since static variables run throughout the code they can be accessed
2. if we assign its memory on heap\
    heap is accessible, stack is not

*/
#include<iostream>
using namespace std;

int * fun()
{
    static int arr[] = {1,2,3};

    int *arr1 = new int[3];

    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    return arr1;
}

int main()
{
    int *arr = fun();
    cout << arr[0];
    cout << arr[1];
    cout << arr[2];
    return 0;
}