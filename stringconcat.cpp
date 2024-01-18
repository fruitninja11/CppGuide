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
    char dest[20] = "Ninja";
    const char* source = "Fruit";
    strconcat(dest, source);
    cout << "Concat string = " << dest;
    return 0;
}