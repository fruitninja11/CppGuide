/*


*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {11,23,34,41,54};
    int largest = arr[0];

    for (int i = 0; i < 5; i++)
    {
        if (arr[i]>largest)
        {
            largest = arr[i];
        }
    }
    
    return 0;
}
