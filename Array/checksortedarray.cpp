/*
check if the array is sorted or not
*/

#include<bits/stdc++.h>
using namespace std;

bool checkSortedArray(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i-1])
        {
            
        }
        else
            return false;
        
    }
    return true;
}

int main()
{
    int arr[] = {11,21,41,31,33};
    int arr2[] = {11,21,31,41,43};
    if(checkSortedArray(arr2,5))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}

