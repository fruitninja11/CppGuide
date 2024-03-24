#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,1,1,0,1,1,1,0,1,1,1,1}, n=12;
    
    int maxm=0, count=0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1)
        {
            count ++;
            maxm = max(maxm,count); 
        }
        else
        {
            count =0;
        }
           
    }
    
    cout << count << endl;

    return 0;
}
