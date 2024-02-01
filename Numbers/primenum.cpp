//objective is to find first n prime numbers


#include<iostream>
#include <valarray>
using namespace std;

bool isprime(int num){
    for (int i = 2; i <= sqrt(num); i++) //sqrt(num) isoptimized way but remember to add = while comparing  //for (int i = 2; i <num; i++)(normal way)
    {
        if (num%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n = 10; //find first 10 prime numbers;
    unsigned int num=2, count=0;

    while (count < n)
    {
        if (isprime(num))
        {
            cout << num << "\t";
            count ++;
        }
        num++;
    }
    return 0;
}