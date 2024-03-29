#include<bits/stdc++.h>
using namespace std;

//here input is an array of numbers which contains numbers which are repeating
// and query is the input for which we tell from the input array that how mant times the number has appeared
// lets say query is 2 so we will check how mant times 2 has appeared in the array

/*
the brute force method is the one where we take an input and in the for loop we search the element and 
increase the count. and then do it for every query. so time required will be no. of queries q*O(n) (i.e O(n) is time complexity to for input arr)
so if the number of queries and size of the array both increase then the time consumed will be a lot more. so we introduce hashmap here.

so here hashing comes in -> prestroring and then fetching.
saves a lot of time;

now in case of integers we have to take care about sizes. here we took a hash of 15 for more sizes
i.e. 10^9 in such cases segfault occurs if we declare that in main;
so in the main function upto 10^6 is allowed but beyond that is not(tested in the code)
so in case of values above 10^6 lets say 10^7 we have to declare it globally;
*/

int hashh[10000000]; //no zero is initialized since global values are initialized to 0

int main()
{
    int inp_arr[10]={1,3,2,2,1,4,1,7,3,9};
    //let us assume that the max number here in the array would be 15;
    //so we have the input array now we precompute it in another array called hash

    //precompute
    int hash[1000000] = {0}; //init every count to 0
    for (int i = 0; i < 10; i++)
    {
        hash[inp_arr[i]]+=1;
        //hash will store the count of elements;
    }
    
    //now for the queries 
    int query[5]={1,7,3,4,9};

    for (int i = 0; i < 5; i++) //starting form 0 since index of 0 in hash will have 0 
    {
        cout<<"Count of " << query[i]<< " is "<<hash[query[i]] << endl;
    }
    
    return 0;
}