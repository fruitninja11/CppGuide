#include <iostream>
using namespace std;

template <typename T>
T** get2darray(int rows, int cols)
{
    T **arr = new T*[rows];
      
    for(int i = 0; i < rows; i++)
    {
        arr[i] = new T[cols];
    }
    return arr;
}

template <typename T>
void print2darray(T** arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    // No need to specify <int> explicitly; it will be deduced from the usage
    int** arr = get2darray<int>(5, 5);
    
    // Example usage of the array
    arr[0][0] = 1;
    cout << arr[0][0] << endl;

    // Printing the array
    print2darray(arr, 5, 5);

    // Deallocate memory
    for(int i = 0; i < 5; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
