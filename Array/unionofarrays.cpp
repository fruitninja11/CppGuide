#include<bits/stdc++.h>
using namespace std;

//union of two sorted arrays
// when unique use set or map
//use ordered set for order, dont use unordered set

//optimal approach
//use two pointer
vector<int> unionArray(int arr1[], int arr2[],int n,int m)
{
    
}




int main()
{
    int arr1[]={1,1,2,3,4};
    int arr2[]={2,2,3,4,5};

    //brute force approach
    set<int> st;
    for (int i = 0; i < size(arr1); i++)
        st.insert(arr1[i]); //O(n1logn)

    for (int i = 0; i < size(arr2); i++)
        st.insert(arr2[i]); //O(n2logn)
    
    vector<int> temp;
    for(auto it : st)
    {
        temp.push_back(it);
    }
    return 0;
}