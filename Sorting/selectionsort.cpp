/*
select minimum and swap
all about selection sort

the loops runs about the same times as the total elements in the array 
n, n-1, n-3, .... 1;
so it resembles summation of n natural numbers.
ie. n*(n+1)/2

time complexity is O(n^2) which is best , avg and worst;
*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)   //till n-1 because last element will be sorted itself
    {
        for (int j = i; j < n; j++) //from first to last element find the smallest element
        {
            if(arr[j]<arr[i]) //for comparison we consider arr[i] as samllest
            {
                swap(arr[i],arr[j]);
            }
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " - " ;
    }
    
}

int main()
{
    int arr[10] = {22,11,6,7,35,77,99,64,32,25};

    selection_sort(arr,10);

    return 0;
}