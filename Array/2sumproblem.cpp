// Two Sum : Check if a pair with given sum exists in Array

#include<bits/stdc++.h>
using namespace std;


//time complexity : O(n^2)
int fun_brute(vector<int> vec, int sum)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i+1; j < vec.size(); j++)
        {
            if(i==j)
                continue;

            if(vec[i]+vec[j]==sum)
            {
                cout << "Pair is " << vec[i] << " " << vec[j];
            }   
        }   
    }
    return 0; 
}


//using hashmap
//time complexity : O(N logN) unordered map : O(n) or O(n^2)
// space complexity O(N)
int fun_better(vector<int> vec, int sum)
{
    map<int, int> mpp;

    for (int i = 0; i < vec.size(); i++)
    {
        int a = vec[i];
        int more = sum - a;
        if(mpp.find(more) != mpp.end())
        {
            cout << "Pair is " << vec[i] << " " << vec[mpp[more]] ;
        }
        mpp[a] = i;
    }
    return 0;
}

//time complexity : O(N) + O(N logN)
int fun_optimal(vector<int> vec, int target)
{
    int left =0;
    int right = vec.size();
    sort(vec.begin(), vec.end());
    while (left < right)
    {
        int sum = vec[left]+vec[right];
        if(sum == target){
            return 1;
        }
        else if(sum < target)
        {
            left++;
        }
        else    
            right --;
    }
    return 0;
    
}

int main()
{
    int sum = 14;
    vector<int> vec{1,2,6,11,5,8};
    fun_brute(vec, sum);
    fun_better(vec, sum);
   
    return 0;
}