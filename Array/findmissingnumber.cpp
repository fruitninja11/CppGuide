#include<bits/stdc++.h>
using namespace std;
/*
find the missing number from the given array
array is given from 1 to n 
*/

/*
logic:  sum of n natural numbers in sum = n(n+1)/2;
*/
int fun_optimal(int arr[], int n)
{
    int sum = n*(n+1)/2;
    int arr_sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        arr_sum = arr_sum + arr[i]; 
    }

    cout << sum - arr_sum;
    return sum-arr_sum;
    
}


/*
logic:  XOR of two numbers is 0 if both are same
and its 1 if they are not same then its 1;
*/
int fun_optimal2(int arr[], int n)
{
    int xor1=0,xor2=0;
    for (int i = 0; i < n-1; i++)
    {
        xor2=xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
    
}



/*
Better approach: use hashing
time complexity = O(n)+O(n)
space complexity = O{n}
*/

int fun_better(int arr[], int n)
{
    int hash[n+1]={0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]=1;
    }

    for (int i = 0; i < n; i++)
    {
        if(hash[i]==0)
        {
            cout << i << " is not there" << endl;
            return i;
        }
    }
    
    return 0;
}



/*
brute force
time complexity = O(n^2) :: since 2 for loops
*/
int fun_brute(int arr[], int n)
{
    
    for (int i = 1; i <= n; i++)
    {
        int flag=0;
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j]==i)
            {
                flag=1;
                break;
            }         
        }

        if(flag==0)
        {
            cout << i << " is not there" << endl;
            return i;
        }
        
    }
   return 0; 
}

int main()
{
    int arr[] = {1,2,4,5}, n=5;
    
    fun_brute(arr,5);
    fun_better(arr,n);
    fun_optimal(arr,5);
    cout << fun_optimal2(arr,5);
    return 0;
}
