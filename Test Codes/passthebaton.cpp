/*There are friends standing in a line, each numbered from 1 through nindusive. 
The first one, friend 1, holds a baton Each second, the baton is passed to the next friend in line. 
Once it reaches the end of the line, the direction of passing is reversed and passing continues. 
Determine who will pass and who will receive the baton at a given time.

1. Question 1

Example

Friends are numbered / through 4. Friend / holds the baton at time 0. 
At time 1, it is passed to friend 2. Over 5 seconds, the baton is passed as 1->2->3->4->3->2. 
The friend passing the baton at time 5 is friend 3. 
The friend receiving the baton is friend 2. Return (3, 2).

Complete the function batonPass in the editor below. The function must return an integer array.

batonPass has the following parameters:

int time, the time to report who on the baton

int[2]: the friend who has the baton (index 0) and the friend who receives the baton (index 1)
*/



/*

1 - 2 - 3 - 4 - 5
  1   2   3   4

*/

#include<bits/stdc++.h>
using namespace std;

int result[2] = {0};
int* passBaton(vector <int> friends, int time)
{
    int n = friends.size();
    int q = (time-1) / (n-1);
    int r = (time-1) % (n-1);

    cout << " n " << n << "q" << q << "r" << r << endl;   
    
    if(q % 2 == 0)
    {
        cout << friends[r] << "->" << friends[r+1];
        result[0] = friends[r];
        result[1] = friends[r+1];
    }
    else
    {
        cout << friends[n-r-1] << "->" << friends[n-r-2];
        result[0] = friends[n-r-1];
        result[1] = friends[n-r-2];
    }

    return 0;
}


int main()
{
    vector<int> friends{1,2,3,4};
    int time = 5;
    
    int* result = passBaton(friends, time);
    //std::cout << "(" << result[0] << ", " << result[1] << ")" << std::endl;
    return 0;
}