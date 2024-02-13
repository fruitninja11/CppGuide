/*
second largest element without sorting

//brute force method is sorting the array
then last element will be largest i.e. n-1
and second largest will be n-2.
time complexity is NlogN + N

//better method
first pass get the largest element.
second pass get the second largest.
time complexity is O(2N)


//optimal method 
time complexity is O(N)
*/


#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[],int n)
{
    int largest = arr[0];
    int secondlargest = -1;

    for (int i = 0; i < n; i++)
    {
       if (arr[i]>largest)
       {
            secondlargest = largest;
            largest = arr[i];
       }
       else if (arr[i]<largest&&arr[i]>secondlargest)
       {
            secondlargest = arr[i];
       }
       
    } 
    return secondlargest;
}

int secondSmallest(int arr[],int n)
{
    int smallest = arr[0];
    int secondsmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
       if (arr[i]<smallest)
       {
            secondsmallest = smallest;
            smallest = arr[i];
       }
       else if (arr[i] != smallest && arr[i] < secondsmallest)
       {
            secondsmallest = arr[i];
       }
       
    } 
    return secondsmallest;
}

int main()
{
    int arr[] = {34,41,7,11,23,54,66,65};
    int largest = arr[0];

    //first pass
    for (int i = 1; i < 8; i++)
    {
        if (arr[i]>largest)
        {
            largest = arr[i];
        }
    }
    
    //second pass
    int secondlargest = -1;
    for (int i = 0; i < 6; i++)
    {
        if(arr[i]>secondlargest && arr[i]<largest)
        {
            secondlargest = arr[i];
        }
    }

    //optimal method
    cout <<"secondlargest = "<< secondLargest(arr,8) ;
    
    return 0;
}
