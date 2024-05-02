#include<bits/stdc++.h>
using namespace std;

//pass by value
//sending a copy of variable to function
void passbyvalue(int num)
{
    cout<< num << endl;
    num+= 5;
    cout<< num << endl;
    num+= 5;
    cout<< num << endl;
}

void passbyvaluestring( string s)
{
    s[0] = 'M';
    cout << s << endl;
}

//pass by reference
//sending actual data function
void passbyreference(int &num){
    cout<< num << endl;
    num+= 5;
    cout<< num << endl;
    num+= 5;
    cout<< num << endl;
}

void passbyrefarray(int arr[], int){

    arr[0] +=5;
    arr[1] +=5;
    arr[2] +=5;
    arr[3] +=5;
    arr[4] +=5;
}



int main()
{
    int num = 11, arr[5] = {5,6,9,11,20};
    string s = "Ninja";
    passbyvalue(num);
    passbyvaluestring(s);
    cout << s << endl;
    cout << num << endl;
    passbyreference(num);
    cout << num << endl;
    passbyrefarray(arr, 3);

    for(int i; i<5 ;i++)
        cout<<arr[i]<<endl;

    return 0;
}