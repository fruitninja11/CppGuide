// Problem Statement: Given an array and a sum k, 
//we need to print the length of the longest subarray that sums to k.

#include<bits/stdc++.h>
using namespace std;

/*logic: create sub arrays in such a way that 
  length of sub arrays is maximum and their sum is k
  Time Complexity : O(n^2)
*/

int fun_brute(vector<int> vec, int sumk)
{
    int sum,len=0;

    for (int i = 0; i < vec.size(); i++)
    {
        sum=0;
        for (int j = i; j < vec.size(); j++)
        {
            sum += vec[j];
            /*
            for (int k = i; k <= j; k++)
            {
                sum = sum + vec[k];
            }
            */
            if(sum == sumk)
            {
                len = max(len,j-i+1);
            }
        }        
    }
    
    return len;
}


// for arrays with positive integers and zeros
// Time Complexity : O(2n)
int fun_optimal(vector<int> vec, int k)
{
    int left=0, right=0, sum, maxlen=0;
    // if sum > k, reduce the subarray from left
    // until sum becomes less or equal to k:
    
    sum = vec[0]; 
    while (right < vec.size())
    {
        while ( left <= right && sum > k)
        {
            sum -= vec[left];
            left++;
        }
        
        if(sum == k)
        {
            maxlen = max(maxlen, right - left + 1);
        }

        right++ ;
    
        if(right < vec.size())
            sum += vec[right];
    }
    return maxlen;
}

// better for arrays with positive integers and negative integers and zeroes
// optimal method for arrays with positive, negative integers
// Time Complexity : O(2n)

int fun_better(vector<int> vec, int k)
{
    map<int , int> preSumMap;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];

        if(k == sum)
        {
            maxLen = max(maxLen,i+1);
        }

        int rem = sum - k;  
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }

        // consider the edge case ex: {2,0,0,3}
        // if we dont use if condition,the answer will be maxLen=1
        // but it should be considered 3 {0,0,3}
        // so before puttin sum in map we should check 
        //if its already present or not


        if(preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;    
}

int main()
{
    int k = 3;
    vector<int> vec{1,2,3,1,1,1,4,2,3,3};
    cout << "\n The length of the longest subarray is: " << fun_brute(vec,k);
    cout << "\n The length of the longest subarray is: " << fun_optimal(vec,k);
    
    return 0;
}