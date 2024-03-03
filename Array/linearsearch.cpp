#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,22,3,2,10,6,5};

    int s =3;
    for (int i = 0; i < 7; i++)
    {
        if(arr[i]==s)
            return 1;
        else
            return 0;
    }
    
    return 0;
}