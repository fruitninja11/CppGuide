//aim is to find the highest and lowest frequency element

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[15]={7,4,4,4,6,7,6,7,6,7,1,6,6,7,7};
    int lowfreq=1, highfreq=0 , maxele=0, minele=0;

    map<int, int> mpp;

    for (int i = 0; i < 15; i++)
    {
        mpp[arr[i]]++;
    }
    
    for(auto i : mpp)
    {
        cout << i.first << "->" << i.second << endl;
    }
    for(auto i : mpp)
    {
        if (i.second > highfreq)
        {
            highfreq = i.second;
            maxele = i.first;
        }
        if(i.second <  lowfreq)
        {
            lowfreq = i.second;
            minele = i.first;
        }
        
    }

    cout << "Number with least frequency is "<< minele << endl;
    cout << "Number with most frequency is "<< maxele << endl;
    return 0;
}