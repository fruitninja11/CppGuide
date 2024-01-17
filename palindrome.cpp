#include<iostream>
using namespace std;

int reverse(int num)
{
    int digit, y=0;

    while (num > 0)
    {
       digit = num %10;
       y = y * 10 + digit;
       num = num /10;
    }
    return y;
}

int main()
{
    unsigned int num=1001, revnum;
    //cout << "Enter a number";
    //cin >> num;
    revnum=reverse(num);
    if (revnum == num)
        cout << "Palindrome " << endl;
    else
        cout << "Not Palindrome " << endl;
    

    return 0;
}