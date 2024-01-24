#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int left =0, right = s.length()-1;
    while(left<right)
    {
        if(s[left]!=s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    string str1= "abcdfcba";
    if(isPalindrome(str1))
        cout<<"Palindrome";
    else
        cout << "Not palindrome";
    return 0;
}
