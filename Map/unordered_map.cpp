#include<bits/stdc++.h>
using namespace std;


/*

unordered_map stores all the values in the unordered manner 
in this code we are storing the frequency of the number

storing and fetching time complexity is avg -> O(1)  best -> O(1) worst -> O(N)
where N is the numbers of elements in the map data structure

Most of the times the first prioirity is given to unordered map because of the time complexity

unordered_map can only have individual dataytypes as key like int, double, char, string. (not pair, vectors, etc)
*/

int main()
{
    int array[10] = {1,4,3,2,5,5,1,2,7,3};
    //input

    //precompute
    //in this loop we have added code to fill unordered_map with key and values;
    unordered_map<int, int> mpp;
    
    for (int i = 0; i < 10; i++)
    {
        mpp[array[i]]++;
    }

    //iterate in unordered_map
    //for(auto it : mpp)
    //    cout << it.first << "->" << it.second << endl;

    //fetch
    int arr[5]={11,2,3,7,5};

    for(int i =0; i<5 ;i++)    
    cout << mpp[arr[i]] << endl;

    return 0;
}