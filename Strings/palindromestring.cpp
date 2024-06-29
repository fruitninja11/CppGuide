#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char s[], int length)
{
    int left =0, right = length-1;
    while(left<right)
    {
        if(s[left++]!=s[right--])
        {
            return false;
        }
    }
    return true;
}


int main(int argc, char const *argv[])
{
    char str1[]= "abcdcba";
    int length = strlen(str1);

    if(isPalindrome(str1,length))
        cout<<"Palindrome";
    else
        cout << "Not palindrome";
    return 0;
}
