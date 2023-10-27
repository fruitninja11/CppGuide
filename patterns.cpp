#include<bits/stdc++.h>
using namespace std;


void fivestarmtrx(int n){
    //5*5 star matrix
     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;        
     }
}

void rightangledpattern(int n){
    //star right angled pattern
     for (int i = 0; i < n; i++)
     {
        // inner loop count should be same as outer one   
        for (int j = 0; j <= i ; j++)
        {
            cout << "*";
        }
        cout << endl;        
     }
}

void rightangledpatternnum(int n){
    //number right angled pattern
     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= i ; j++)
        {
            //print inner column
            cout << j;
        }
        cout << endl;        
     }
}

void rightangledpatternrow(int n){
     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= i ; j++)
        {
            //print upper row
            cout << i;
        }
        cout << endl;        
     }
}

void upperstartriangle(int n){
     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= n-i+1 ; j++)
        {
             cout << i;
        }
        cout << endl;        
     }
}

void pyramid(int n)
{
    for (int i = 0; i < n; i++)
     {
        //space
        for (int j = 0; j < n-i-1 ; j++)
        {
            cout <<" ";
        }

        //star
        for (int j = 0; j <2*i+1 ; j++)
        {
            cout << "*";
        }

        //space
        for (int j = 0; j < n-i-1 ; j++)
        {
            cout <<" ";
        }
        cout << endl;        
     }
}

void invertedpyramid(int n)
{
    for (int i = 0; i < n; i++)
     {
        //space
        for (int j = 0; j < i ; j++)
        {
            cout <<" ";
        }

        //star
        for (int j = 0; j < 2*n -(2*i+1) ; j++)
        {
            cout << "*";
        }

        //space
        for (int j = 0; j < i ; j++)
        {
            cout <<" ";
        }
        cout << endl;        
     }
}

void arrow(int n){
    for (int i = 1; i <=2*n-1; i++)
    {
        int stars = i;

        if(i>n)
            stars = 2*n -i;
        for (int j = 1; j <=stars ; j++)
        {
            cout<< "*";
        }
         cout << endl;
    }
    
}

int main()
{
    int n=5;
    //cin >> n;

    fivestarmtrx(n);
    rightangledpattern(n);
    rightangledpatternnum(n);
    rightangledpatternrow(n);
    upperstartriangle(n);
    pyramid(n);
    invertedpyramid(n);
    arrow(n);
    return 0;
}
