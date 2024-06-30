#include<iostream>
#include<string>
#include<vector>

using namespace std;

string sortString(string str)
{
    vector<int> freq(26,0);
    // Initialize output with the same length as input
    string output(str.length(), ' ');

    //adding frequency of every character
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        freq[index]++;
    }

    //create sorted string
    int j=0;
    for (int i = 0; i < 26; i++)
    {
        while (freq[i]>0)
        {
            output[j++]= i + 'a';
            freq[i]--;
        }
        
    }
    return output;


}

int main()
{
    string str = "geeksforgeeks";

    cout << sortString(str) << endl;
    return 0;
}