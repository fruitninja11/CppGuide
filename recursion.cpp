#include<bits/stdc++.h>
using namespace std;

int factorial(int num)
{
    if(num == 0 || num == 1)
    {
        return 1;
    }
    else
        return num * factorial(num-1);

}

int main()
{
 int result;
 result = factorial(5);
 cout << " Factorial is " << result;
 return 0;   
}