/*
In a string reverse the words 
string = "my name is shubham"

output = "ym eman si mahbuhs"
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
//to use isalpha 
#include<cctype>
using namespace std;


//brute force
//O(n^2)
void reverseWords(string &str)
{
    int start=0, end=0;
    int size = str.size();

    while (end <= size)
    {
        while (end < size && isalpha(str[end]))
        {
            end++;
        }

        reverse(str.begin()+start,str.begin()+end);

        start = end + 1;
        end = start;        
    }
}

//optimized
//Space = O(n)
//Time = O(n)
void optreverseWords(string &str)
{
    stack<char> stack;
    string temp;
    for(char c : str)
    {
        if (isalpha(c))
        {
            stack.push(c);
        }
        else
        {
            while (!stack.empty())
            {
                temp += stack.top();
                stack.pop();
            }
            // Add the delimiter character to the result
            temp += c;
        }
        
    }

    // Pop any remaining characters from the stack (for the last word)
    while (!stack.empty()) {
        temp += stack.top();
        stack.pop();
    }
    str = temp;
}

int main()
{
    string s1 ="my name is shubham";
    //reverseWords(s1);
    optreverseWords(s1);
    cout << s1;
    return 0;
}