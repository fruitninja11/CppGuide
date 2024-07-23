/*
There are few points regarding string literals as follows:
1. They are constant string and can't be changed!!
2. Pointer can be changed to point to some other string!!
3. As String Literals are constant by nature applying const keyword gives extra benefit.
4. Creating array of string is not string literals.
5. We can change non const array string.
6. Experiment with function passing.
7. RAW String In C++11.
*/

#include<iostream>
#include <cstring>
using namespace std;

int main()
{
    //string literal
    //const char *city ="Pune";
    char *city ="Pune";
    
    //not possible gives seg fault
    //city[3]='a';
    
    
    cout << city;

    char str[] = "Pune";
    cout << str;
    if (strcmp(str,city)==0)
    {
       cout << "True" << endl; 
    }

    //raw string with annotation R
    string s1 = R"(Cpp\nNuts)";
    cout << s1;
    return 0;
}