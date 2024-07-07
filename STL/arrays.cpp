/*
syntax : std ::array<T , N> array;

1. std::array is a container that encapsulates fixed size arrays.
2. array size is needed at compile time.
3. Assign by value is actually by value.
4. Access Elements:
   a. at()  //will throw out of bound exception if access is beyond limits
   b. []    //will not throw any exception if access is beyond limits
   c. front()   //access first element
   d. back()    //access last element
   e. data() // gives access to the underlying array
*/

#include<iostream>
#include<array>

int main()
{
    //Declare
    std::array<int, 5> arr;
    arr.fill(11);

    //Initialization
    std::array<int, 5> arr1 = {1,2,3,4,5}; //initializer list
    std::array<int, 5> arr2 {1,2,3,4,5}; //uniform initialization

    std::cout << arr.at(2) << std::endl;
    std::cout << arr1.front() << std::endl;
    std::cout << arr1.back() << std::endl;
    return 0;
}