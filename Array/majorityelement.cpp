// Find the Majority Element that occurs more than N/2 times


#include <bits/stdc++.h>
using namespace std;

//brute force 
// take each element and search that element in array
// if its count is more than n/2 then that is the answer
// time complexity = O(n^2)
int fun_brute(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int count=0;
        for (int j = 0; j < vec.size(); j++)
        {
            if(vec[i]==vec[j])
            {
                count++;
            }

            if(count > vec.size()/2)
            {
                return vec[i];
            }
        }
        
    }
    return -1;
}

//better method 
//Use hash map -> element is key and value is count;
// time complexity = O(n)+ O(nlogn)
// space complexity = O(n)
int fun_better(vector<int> vec)
{
    map<int, int> mpp;

    for (int i = 0; i < vec.size(); i++)
    {
        mpp[vec[i]]++;
    }

    for(auto it : mpp)
    {
        if(it.second > vec.size()/2)
        {
            return it.first;
        }
    }
    return -1;
}

//optimal method
//moore's voting algorithm
/*
Approach: 
Initialize 2 variables:
Count –  for tracking the count of element
Element – for which element we are counting
Traverse through the given array.
If Count is 0 then store the current element of the array as Element.
If the current element and Element are the same increase the Count by 1.
If they are different decrease the Count by 1.
The integer present in Element should be the result we are expecting 
*/
// time complexity = O(n)
// space complexity = O(n)
int fun_optimal(vector<int> vec)
{
    int count =0, elem;
    for (int i = 0; i < vec.size(); i++)
    {
        if(count==0)
        {
            elem = vec[i];
            count++;
        }
        else if(vec[i] == elem)
        {
            count++;
        }
        else{
            count--;
        }
    }
    
    int count1=0;
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i]==elem)
            count1++;
    }

    if(count1 > vec.size()/2)
    {
        return elem;
    }

    return -1;
    
}

int main()
{
    int k = 3;
    vector<int> vec{1,2,1,1,1,1,2,3,4};
    
    return 0;
}