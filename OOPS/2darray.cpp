#include<iostream>
using namespace std;

void print2darray(int** arr)
{
    for ( int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<arr[i][j];
        }
        cout << endl;    
    }    
}


int** get2darray(int rows, int cols)
{
    int i;
    int** arr = new int*[rows];
    for ( i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];        
        for (int j = 0; j < rows; j++)
        {
            arr[i][j] = i+j;
        }   
    }

    return arr;
}


int main()
{
    int **arr;
    arr = get2darray(5,5);
    print2darray(arr);
    return 0;
}