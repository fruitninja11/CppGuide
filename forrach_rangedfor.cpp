#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int val){
    cout << val << endl;
}

int main(){

    vector<int> vec;

    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }

    for(int i : vec) //iterate over whole vector and get 1 element each time;
        cout<< i << endl;
    
    for_each(vec.begin(), vec.end(),[](int i){ //lambda expression for printing
        cout << i << endl; 
    });

    for_each(vec.begin(), vec.end(), print); //funciton parameter is used here so print function is called
    
    return 0;
}