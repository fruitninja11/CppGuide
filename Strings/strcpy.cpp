#include<iostream>
using namespace std;

char* stringcopy(char* destn, const char* source)
{
    while (*source != '\0')
    {
        *destn ++ = *source ++;
    }
    ++*destn = '\0';
    return destn;
}

int main()
{
    const char* source ="hello, shubham";
    char dest[50];

    //copy function
    stringcopy(dest, source);
    cout << "original string : " << source << endl;
    cout << "copied string : " << dest << endl;
    
    return 0;
}