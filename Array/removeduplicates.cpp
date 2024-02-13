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

*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,2,2,1,3};
    set<int> st;
    int index =0;

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

