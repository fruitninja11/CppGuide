#include<iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0 ,i=0;
    while (name[i] != '\0')
    {
        count++;
        i++;
    }
    
    return count;
}


char * reverseString(char name[] ,int n)
{
    int start =0;
    int end = n-1;

    while (start < end)
    {
       swap(name[start++],name[end--]);
    }
    
    return name;
}



int main()
{
    char name[20] = "Shubham";
    cout << "Length : " << getLength(name) << endl;
    cout << "Reversed : " << reverseString(name, getLength(name));
    
    return 0;
}