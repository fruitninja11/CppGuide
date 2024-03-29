#include<iostream>
using namespace std;

char* strconcat(char* dest, char* source){
    
    while (*dest)
    {
        dest++;
    }
    
    while (*source)
    {
        *dest++ = *source++;
    }
    *dest = '\0';
    return dest;
}


int main()
{
    char dest[20] = "Hello";
    char source[20]= " world !";
    strconcat(dest, source);
    cout << "Concat string is " << dest;
    return 0;
}