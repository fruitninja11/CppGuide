//Toggle a string without string functions

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "Hello WORld";

    for (auto &c : str)
    {
        //range of uppercase
        if (c>=65 && c<=90)  //(c>='A' && c<='Z')
        {
            //convert ot lower case
            c=c+32;          // c = c + ('a' - 'A')
        }
        //range of lower case
        else if (c >= 97 && c <=122) //(c>='a' && c<='z')
        {
            //convert to upper case
            c= c-32;        //// c = c - ('a' - 'A')
        }
        
    }
    
    return 0;
}