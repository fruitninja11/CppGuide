#include<iostream>
using namespace std;

char* strconcat(char* dest, const char* source){
    
    while (*dest)
    {
        dest++;
    }
    
    while (*source)
    {
        *dest++ = *source++;
    }
    *dest = '\0';
    
}


int main()
{
    char dest[20] = "world !";
    const char* source = "Hello";
    strconcat(dest, source);
    cout << "Concat string is " << dest;
    return 0;
}