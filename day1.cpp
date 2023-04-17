#include<bits/stdc++.h>
//instead of adding lot of includes ,bits/stdc++.h it includes all the libraries (does take a lot of time)
using namespace std;

//using namespace std is considered as bad practice 
//Namespaces were introduced into C++ to resolve identifier name conflicts. 
//This ensured that two objects can have the same name and yet be treated differently if they belonged to different namespaces.

int sum(int num1 , int num2){
    int num3;
    num3 = num1 + num2;
    return num3;
}


int main() {

    //int , long, float, double, 
    //string and getline
    std::cout << "Hello Ninja!" << std:: endl;

    int x,y;
    cin >> x >> y;
    std::cout << "X value " << x << " and y value" << y << endl;

    int z = sum(x,y);
    std::cout << "Sum is " << z;
    return 0;
}