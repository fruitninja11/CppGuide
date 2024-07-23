//Templates
/*
1. Templates are way to write generic programs.
2. There are two places where we can apply templates
    function templates
    class templates
3. we pass data type as parameter to function or class
*/

#include<iostream>

template <typename T> //template <class T>
T getMaximum(T arg1, T arg2)
{
    return arg1>arg2 ? arg1 : arg2;
}
 


int main()
{
    int num1 = 122;
    int num2 = 231;

    char ch1 = 'a';
    char ch2 = 'z';

    std::cout << getMaximum(num1, num2) << std::endl;

    //since in char the fuction will return ascii value the value needs to be typcasted
    std::cout << getMaximum(ch1, ch2) << std::endl;
    
    return 0;
}