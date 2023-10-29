#include<iostream>
using namespace std;

namespace A
{
    int x =4;
    void printX(){
        cout << x << endl;
    }
}

namespace B
{
    int x =14;
    int printX(){
        cout << x << endl;
        return 0;
    }
}

using namespace B;

int main(int argc, char const *argv[])
{
    printX();
    return 0;
}
