#include<iostream>
using namespace std;

/* temp array technique*/
void revTempArray(int arr[], int n){
    int revarr[n];
    int m=n;
    n=n-1;

    for (int i=0; i < m; i++)
    {
        revarr[i]=arr[n];
        n--;
    }
    for (int i = 0; i < m; i++)
    {
        /* code */
        cout << revarr[i] << "->";
    }
    

}

/* swap technique (space optimized) */
void revSwapArray(int arr[], int n)
{
    int p1 = 0 , p2 =n-1;
    while (p1<p2)
    {
        swap(arr[p1],arr[p2]);
        p1++; p2--;
    }
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << "->";
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[]={5,4,3,2,1};
    int n=5;
    //revTempArray(arr,n);
    revSwapArray(arr,n);
    return 0;
}
