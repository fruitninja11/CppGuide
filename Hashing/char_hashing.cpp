#include<bits/stdc++.h>
using namespace std;

//for small case letters
//so ascii value for a to z is from 97 to 125
// we use this value to make a hasharray of characters
int main()
{
    string str ="abddeabccff";

    //precompute
    int hash[26]={0};
    int i=0;
    while (str[i]!='\0')
    {
        hash[str[i]-'a']+=1;
        i++;
    }
    
    //fetch
    string query = "abcfd";
    for (int i = 0; i < query.size(); i++)
    {
        cout << "letter " << query[i] << " has occured " << hash[query[i]-'a'] << " times" << endl;
    }
    
    return 0;
}