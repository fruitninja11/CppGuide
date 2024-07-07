/*
Here we are implementing string class and some of its functions
--01
What and Why?
initializer list is used to initialize member variables of class
Where to use?
If some members are constant
If some are reference members
In such cases we cant go inside constructor body to initilaize with some variables.
Because such members can be initialized once and cant be changed again.

Again in a case if a another class(B) object is data member of your class
and if the class(B) dosent have a default constructor and only has a parameterised const and 
we have to initialize it, and we cant initialize in constrcutor body because the compiler
will look for a definition of default constructor and since its not there it will throw an error

--02
Why we use const in parameterised constructor is because we are passing a constant string


//move constructor --03
It's a optimization thing in/after c++11 where it says s2 give the resources to s4 and just die.
Earlier in copy constructor we used to have both remain in the memory unlike in move constructor.
No copying only pointing
Use:
Sometimes you call a function you create a temporary object to return and then you don't need it.
In such cases you can use move. Instead of copying whole thing we just point to new object.

IMP: Copy and Swap Idiom

*/


#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
    char* str;
    unsigned int length;
public:
    //default constructor
    String():str(nullptr),length(0){}; //using initializer list --01

    //parameterised constructor
    String(const char* ch)
    {
        length = strlen(ch);
        str = new char[length+1]; //+1 to put null character '\0'
        strcpy(str,ch);
    }

    //copy constructor
    String (const String& obj)
    {
        length = obj.length;
        str = new char[length+1];
        strcpy(str,obj.str);
    }

    //copy assignement operator
    String& operator=(const String& obj)
    {
        if (this != &obj) //check if its not a self assignment
        {
            delete[] this->str; //delete the memory occupied since it may have allocated soem memory before
            length = obj.length;
            str = new char[length+1];
            strcpy(str,obj.str);
        }
        return *this;
    }

    //move constructor
    String (String&& obj) //&& means Rvalue reference passing something as temporary object
    {
        length = obj.length;
        str = obj.str;
        obj.str = nullptr;
        obj.length = 0;
    }


    // Friend function for output & input operator
    //since we want to access str which is private
    friend ostream& operator<<(ostream& out,const String& obj);
    friend istream& operator>>(istream& out, const String& obj);
    
    //destructor
    ~String()
    {
        if(str)
        {
            delete[] str;
            str = nullptr;
            length = 0;
        }
        
    }
};

//global function and not called by anyone 
// here '<<' takes cout and s2 as parameters
ostream& operator<<(ostream& out, const String& obj)
{
    if (obj.str != nullptr)
    {
        out << obj.str;
    }
    else
    {
        out << "Empty String" << endl;
    }
    
    return out;
}

//global function and not called by anyone 
// here '>>' takes cin and s1 as parameters
istream& operator>>(istream& in, const String& obj)
{
    in >> obj.str;
    return in;
}


int main()
{
    String s1; //default constructor;
    String s2 = "test"; //parameterized constructor --02
    String s3 = s1; //copy constructor
    s3 = s2; //copy assignment operator
    cout << s2; //overloading << operator
    cin >> s3;  //overloading >> operator
    String s5 = move(s2); //move constructor --03
    return 0;
}