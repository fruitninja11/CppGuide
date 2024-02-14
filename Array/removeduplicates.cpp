/*
remove duplicates from a SORTED array
use inplace algorithm.
leetcode question

brute force:
we can use set because set has a property of uniqueness
put each element of array in a set then at the 
end of loop you will have a set of unique elements.
insertion opeartion in set take logN time
time complexity : N + NlogN


optimal:
we use two pointer approach
time complexity : N

*/


#include<bits/stdc++.h>
using namespace std;

//optimal method
int removeDuplicates(int arr[], int n)
{
    int i=0,j;

    for (int j = 1; j < n; j++)
    {
       if(arr[j]!=arr[i])
       {
            arr[i+1]=arr[j];
            i++;
       }
    }

    return i+1;   
}

int main()
{
    int arr[] = {1,1,2,2,3};
    set<int> st;
    int index =0;

    cout << "Unique Elements are " << removeDuplicates(arr,5) << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    } 

// set method (brute force)for unique elements
    for (int i = 0; i < 5; i++)
    {
        st.insert(arr[i]);
    }
    
    for(auto it : st)
    {
        arr[index] = it;
        index ++;
    }

    return 0;
}

