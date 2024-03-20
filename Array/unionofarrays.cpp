#include<bits/stdc++.h>
using namespace std;

//union of two sorted arrays
// when unique use set or map
//use ordered set for order, dont use unordered set

//optimal approach
//use two pointer
// time complexity is O(n+m);
// space complexity is O(n+m) only to return answer
vector<int> unionArray(int arr1[], int arr2[],int n,int m)
{
    int i=0,j=0;
    vector<int> unionArr;

    while (i<n && j <m)
    {
       if(arr1[i] <= arr2[j])
       {
        if(unionArr.size()==0 || unionArr.back() != arr1[i] )
            unionArr.push_back(arr1[i]);
        i++;
       }
       else
       {
        if(unionArr.size()==0 || unionArr.back()!=arr2[j] )
            unionArr.push_back(arr2[j]);
        j++;
       } 
    }
    //if arr2 gets completed still have to iterate over arr1
    while (i<n)
    {
        if(unionArr.size()==0 || unionArr.back()!=arr1[j] )
            unionArr.push_back(arr1[j]);
        i++;
    }
    //if arr1 gets completed still have to iterate over arr2
    while (j<m)
    {
        if(unionArr.size()==0 || unionArr.back()!=arr2[j] )
            unionArr.push_back(arr2[j]);
        j++;
    }
    
    return unionArr;
    
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

    unionArray(arr1,arr2,5,5);
    return 0;
}