#include<iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n-1);
    
}


int main()
{
    unsigned n =3;
    cout << factorial(5) << endl;
    return 0;
}

/*
                                    -------factorial(3)
                                    |
                            --------3*factorial(2)            
                            |
                    -------3*2*factorial(1)
                    |
             -------3*2*1*factorial(0)      
             |
             3*2*1*1=6
*/