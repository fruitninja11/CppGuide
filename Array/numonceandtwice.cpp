/*
find the number that appears once in an array 
where the others numbers appears twice;

*/

#include<bits/stdc++.h>
using namespace std;

//brute force 
// time complexity = O(n^2)
// cuz for every element we have to linear search every element and
// individually mark its counter
int fun_brute(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int count=0;
        for (int j = 0; j < n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        
        if(count == 1 )
        {
            cout << arr[i] << " appears " << count << " times " << endl;
        }
    }
    return 0;
}

//better approach
//use hashmap
// find out the max element in array
// make map with size n+1 and then insert data in map
// iterate in map and find once elements
// time complexity = O(n) + O(n) + O(n);
// space complexity O(size of hash)
int fun_better(int arr[], int n)
{
    map <int, int> mpp;
    int maxm=0;
    for (int i = 0; i < n; i++)
    {
        maxm =  max(maxm,arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    
    //iterate in map
    for(auto it : mpp)
    {
        if(it.second == 1)
        cout << endl << it.first << "->" << it.second << endl;
    }
        
    return 0;
}

int fun_optimal(int arr[],int n)
{
    int XOR=0;
    for (int i = 0; i < n; i++)
    {
        XOR =XOR ^ arr[i];
    }
    return XOR;

}


int main()
{
    int arr[] = {1,1,2,2,3,3,4,4,5,5,7}, n=11;
    fun_brute(arr,n);
    cout << endl << fun_optimal(arr,n);
    fun_better(arr,n);
    return 0;
}
