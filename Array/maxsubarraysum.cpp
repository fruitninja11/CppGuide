/*
Find the sub array with maximun sum
*/


#include<iostream>
#include<vector>

//Time complexity O(n^2)
void funbetter(std::vector<int> vec)
{
    int sum=0, maxsum=0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum=0;
        for(int j=i; j<vec.size(); j++)
        {
            sum += vec[j];
            maxsum=std::max(sum,maxsum);
        }   
    }
    std::cout << maxsum << std::endl;
}

//Time complexity O(n)
int funoptimal(std::vector<int> vec)
{
    int sum=0, maxsum=INT16_MIN;

    //just to keep a track of indexes where sub array is formed
    int start=-1, end=-1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (sum == 0)
            start = i;
        
        
        sum += vec[i];

        if (sum > maxsum)
        {
            maxsum = sum;
            end = i;
        }
        
        if(sum < 0)
        {
            sum = 0;
        }
    }

    if(maxsum < 0)
        maxsum = 0;

    std:: cout<< start << "->" << end << std::endl;

    return maxsum;
    
}

int main()
{
    std::vector<int> vec ={-2,-3,4,-1,-2,1,5,-3};

    funbetter(vec);

    std::cout << funoptimal(vec) << std::endl;

    return 0;
}