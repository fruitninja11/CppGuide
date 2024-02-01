/*
select maximun and swap -> push maximum to the last using adjacent swaps
opposite of selection sort

time complexity is O(n^2) which is best , avg and worst;
*/

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = n-1; i >= 0; i--)  
    {
        for (int j = 0; j <= i-1; j++) 
        {
            if(arr[j]>arr[j+1]) 
            {
                swap(arr[j],arr[j+1]);
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

    bubble_sort(arr,10);

    return 0;
}