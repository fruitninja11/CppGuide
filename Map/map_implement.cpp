#include<bits/stdc++.h>
using namespace std;


/*
Since we have taken reference from hashing in this implementation, 
what we find is the space complexity decreases as we dont have to declare
an has array with some max limit. We declare a map here which stores the values.

Map stores all the values in the sorted order.
in this code we are storing the frequency of the number

storing and fetching time complexity is log(N) in all the cases 
where N is the numbers of elements in the map data structure

In map dats stucture any data type can be a key
*/

int main()
{
    int array[10] = {1,4,3,2,5,5,1,2,7,3};
    //input

    //precompute
    //in this loop we have added code to fill map with key and values;
    map<int, int> mpp;

    for (int i = 0; i < 10; i++)
    {
        mpp[array[i]]++;
    }

    //iterate in map
    //for(auto it : mpp)
    //    cout << it.first << "->" << it.second << endl;

    //fetch
    int arr[5]={11,2,3,7,5};

    for(int i =0; i<5 ;i++)    
    cout << mpp[arr[i]] << endl;

    return 0;
}