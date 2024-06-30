#include<iostream>
#include<string>
#include <map>
#include <unordered_map>
using namespace std;

/*
Time Complexity: O(N), Traversing the string of length N one time.
Auxiliary Space: O(N), where N is the size of the string
*/
int getMaxOccCharoptimized(string s)
{
    unordered_map<char,int> mpp;
    int n = s.length() , count=0;
    char ans,ch;

    for (int i=0; i < s.length(); i++)
    {
        s[i]=tolower(s[i]);
        mpp[s[i]]++;

        if (count < mpp[s[i]])
        {
            ans = s[i];
            count = mpp[s[i]];
        }
        
    }

    cout << ans << endl;
    return 0;
}

int getMaxOccChar(string s)
{   
    int alpha[26]={0};
    int n=0,ans;
    for (int i=0; i < s.length(); i++)
    {
        char ch = s[i];

        //lowercase
        if (ch >='a' && ch <= 'z')
        {
            n= ch-'a';
        }
        else
        {
            n = ch - 'A';
        }
        alpha[n]++;
    }
    
    int maxi = -1;

    for (int i=0; i < 26; i++)
    {
        if (maxi < alpha[i])
        {
            ans = i;
            maxi = alpha[i];
        }
        
    }

    char c = 'a' + ans;

    cout << c << endl;

    return 0;
}


int main()
{
    string str = "geeksforgeeks";

    getMaxOccChar(str);
    getMaxOccCharoptimized(str);

    return 0;
}