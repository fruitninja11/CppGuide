#include<iostream>
using namespace std;

void sumN(int n, int sum)
{
    if (n<1)
    {
        cout<< sum << endl;
        return;
    }

    sumN(n-1,sum+n);
    
}


int main()
{
    unsigned int n=100;
    sumN(n,0);
    return 0;
}