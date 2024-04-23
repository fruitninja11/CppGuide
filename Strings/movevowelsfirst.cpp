#include<cstring>
#include<iostream>
using namespace std;

bool isVowel(char ch)
{
    /*if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' )
    {
        return true;
    }
    
    return false;
    */
   switch(tolower(ch)) // Check if the character is a vowel (case-insensitive)
   {
    case 'a' :
    case 'e' :
    case 'i' :
    case 'o' :
    case 'u' :
        return true;

    default :
        return false;
   }
}


int main()
{
    string name = "shubham";
    string result;
    
    //iterator 
    for (char c: name)
    {
        if (isVowel(c))
        {
            result.insert(result.begin(),c);  //Insert value at the beginning
        }
        else
        {
            result.push_back(c); //Append non-vowel character at the end
        }
        
    }

    cout << "After moving vowels to front: " << result << endl;
    return 0;

}