#include<iostream>
#include<string.h>
using namespace std;

class String
{
private:
    char* res;
    unsigned int len; //since length cant be less than zero
public:

    //default constructor
    String(/* args */):res(nullptr),len(0){};  //why use member initializer list? if we have members like const or reference members because they can be initialized once 
    // other cases : suppose if this Stringclass has an object of another classB and the classB has only parameterized constructor and not a default const 
    // and we have to initialize object of classB in this class then the compiler will look for the default constructor of classB and will throw an error 
    
    //parameterized constructor
    String(const char* ch) //using const because the user gives a const string in main
    {
        len = strlen(ch); //length of string
        res = new char[len+1]; //+1 to store the '/0' for end of string
        strcpy(res,ch); //copy ch to res
    };

    //copy constuctor
    String (const String &obj) //using const because we dont want to change the resource //'&' for reference
    {
        len = obj.len;
        res = new char[len+1];
        strcpy(res,obj.res);
    };

    //copy assignment
    String& operator=(const String &obj)
    {
        if (this != &obj)
        {
            /* check if someone has not done str3 = str3 */
            // it means str3 already has some resource
            delete[] res; //delete[] to deallocate the memory of previously occupied resource , [] used since its an array 
            len = obj.len;
            res = new char[len+1];
            strcpy(res,obj.res);
        }
        return *this;
        
    }

    unsigned int length()
    {
        return len;
    }

    //String (const String&& obj)
    //{
        //len = obj.len;
        //res = obj.res;
        //obj = nullptr;
        //obj.len = 0;
    //}

    friend ostream& operator<<(ostream& , String& );
    friend istream& operator>>(istream& , String& );

    ~String() //destructor
    {
        delete[] res;
        res = nullptr;
        len = 0;
    };
};

ostream& operator<<(ostream& out, String& obj)
{
    out << obj.res;
    return out;
}

istream& operator>>(istream& out, String& obj)
{
    out >> obj.res;
    return out;
}


int main()
{
    String str1; //default constrcutor
    String str2 = "Shubham"; //parameterized constructor
    String str3 = str1; //copy constructor
    str3 = str2; //copy assignment operator //basically overloading '=' operator
    int len = str2.length();
    cout<<str2; //operator "<<" overloading
    cin>>str2; //operator ">>" overloading
    String str6 = move(str2); //move constructor, moves resources and destroyes itself so str2 will be nullptr //optimization technique
    return 0;
}