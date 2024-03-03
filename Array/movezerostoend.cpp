#include<bits/stdc++.h>
using namespace std;


//time complexity O(2N)
//space complexity O(temp_size)
int brute_moveZero(int n, vector<int> vec)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if(vec[i]!=0)
        {
            temp.push_back(vec[i]);
        }
    }
    
    int size = temp.size();
    for (int i = 0; i < size; i++)
    {
        vec[i] = temp[i];
    }
    
    for (int i = size; i < n; i++)
    {
        vec[i] = 0;
    }
    
    return 0;
}

//time complexity O(N)
//space complexity O(1)
vector<int> optimal_moveZero(int n, vector<int> vec)
{
    int j =-1;

    //find the first 0
    for (int i = 0; i < n; i++)
    {
        if(vec[i]==0)
        {
            j = i;
            break;
        }
    }
    
    if(j == -1) return vec;
    //swap the values of non-zero values with zeros    
    for (int i = j+1; i < n; i++)
    {
        if(vec[i]!=0) //check non-zero
        {
            swap(vec[i],vec[j]);
            j++;
        }
    }
    
    return vec;
}

int main()
{
    int arr[] = {1,2,0,3,0,2,0};
    vector<int> vec{1,2,0,1,0,3,0};

    //int a = brute_moveZero(7,vec);
    vec = optimal_moveZero(7, vec);
    for (int i = 0; i < 7; i++)
    {
        cout << vec[i] << "-" ;
    }
    return 0;
}