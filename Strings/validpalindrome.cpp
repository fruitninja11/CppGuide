/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//time complexity O(n)
//space complecity O(1)
bool optValidPalindrome(string s)
{
    int left=0; 
    int right=s.size()-1;
    
    //two pointer approach left and right pointer
    while(left < right)
    {
        //check whether the character is non alpha numeric
        //i.e. skip the character if its not alphabet or number 
        if(!isalnum(s[left]))
        {
            left++;
        }
        else if(!isalnum(s[right]))
        {
            right--;
        }
        //main idea is to traverse both the pointers to characters and then compare
        //if charcters are not same then not a valid palindrome immediately return
        else if(tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        //required to move the pointer if first and last charcters are same
        else
        {
            left++;
            right--;
        }

    }

    return true;
}

bool isValid(char ch)
{
    if((ch >='A' && ch <='Z') || (ch >='a' && ch <='z') || (ch >='0' && ch <='9'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    string temp="";

    //remove extra characters and make a valid string
    for (int i = 0; i < s.size(); i++)
    {
        if(isValid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    //convert the string into lower case
    for (int i = 0; i < temp.size(); i++)
    {
        if(temp[i]>='A' && temp[i]<='Z')
        {
            //temp[i] +=32;
            temp[i] = temp[i] + ('a'-'A');
        }
    }

    int left = 0;
    int right = temp.size()-1;

    while(left < right)
    {
        if(temp[left]!=temp[right])
        {
            return false;
        }
        left++;
        right--;
    }


    return true;
}


int main()
{
    string input ="A man, a plan, a canal: Panama";
    if(optValidPalindrome(input))
    {
        cout << "Valid Palindrome " << endl;
    }
    else
        cout << "Not Valid Palindrome " << endl;

    if(isPalindrome(input))
    {
        cout << "Valid Palindrome " << endl;
    }
    else
        cout << "Not Valid Palindrome " << endl;
    return 0;
}
