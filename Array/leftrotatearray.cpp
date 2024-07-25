/*
left rotate the array by 1 place
time complexity :O(N)
space complexity :O(N)


left rotate the array by d place
brute force:
time complexity :O(D) + O(n-D) + O(D) = O(n+D)
space complexity : O(D)

optimal solution
*/

#include<bits/stdc++.h>
using namespace std;

//brute force solution
void leftNRotate(int arr[], int n, int D)
{
    D = D % n;
    int temparr[D];
    for (int i = 0; i < D; i++)
    {
        //fill temp array to keep the values to add at the end
        temparr[i] = arr[i];   
    }

    //now left shift the values 
    for (int i = D; i < n; i++)
    {
        arr[i-D] = arr[i];
    }

    //now add the temp elements to main array
    for (int i = n-D; i < n; i++)
    {
        arr[i]=temparr[i-(n-D)];
    }
     
}

void rightNRotate(int arr[], int n, int D)
{
    D = D % n;
    int temparr[D];
    for (int i = 0; i < D; i++)
    {
        //fill temp array to keep the values to add at the end
        temparr[i] = arr[n-D+i];   
    }

    //now right shift the values 
    for (int i = n-1; i >=D ; i--)
    {
        arr[i] = arr[i-D];
    }

    //now add the temp elements to main array
    for (int i = 0; i < D; i++)
    {
        arr[i]=temparr[i];
    }
     
}

void leftNRotateoptimal(int arr[], int n, int D)
{
    reverse(arr,arr+D);
    reverse(arr+D,arr+n);
    reverse(arr, arr+n);
}

int main()
{
    int arr[] = {21,2,31,55,7};

    //left rotate the array by D place
    //leftNRotate(arr,5,3);
    //for (int i = 0; i < 5; i++)
    //   cout << arr[i] << endl;

    //leftNRotateoptimal(arr,5,2);

    rightNRotate(arr,5,1);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << endl;



    //for (int i = 0; i < 5; i++)
        //cout << arr[i] << endl;
    
    return 0;
}