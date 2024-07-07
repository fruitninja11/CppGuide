/*
1 There are two different types of overloading.
  a. Local Overloading (inside class/struct)
  b. Global Overloading 
2. Syntax for Overloading operator new
  void* operator new (size_t size);
3. Syntax for Overloading operator delete
     void operator delete(void*);
4. Both new and delete operator are static members functions. So they don't have access to this pointer (we don't have to write static keyword it is automatically static).
5. Don't forget to overload for array version of both (new/delete).
6. We can have multiple overloaded new/delete operator functions.

why we overload new and delete operators to give developers control of the heap allocations
1. garbage collection
2. initialize something to the whole memory after the heap allocates the memory

*/


#include<iostream>
using namespace std;

class Test
{
private:
    int x;
public:
    Test(int x=0):x{x}{};

    void* operator new(size_t size)
    {
        cout << "Overloaded new operator with size " << size << endl;
        void *p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        cout << "Overloaded delete operator";
        free(p);
    }

    ~Test();
};


// if we put them outside class scope they ill be globally overloaded
/*
    void* operator new(size_t size)
    {
        cout << "Overloaded new operator with size " << size << endl;
        void *p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        cout << "Overloaded delete operator";
        free(p);
    }

*/

void* operator new(size_t size)
{
    cout << "Global Overloaded new operator with size " << size << endl;
    void *p = malloc(size);
    return p;
}

void* operator new(size_t size ,int val)
{
    cout << "Global Overloaded new operator with argument size " << size << endl;
    void *p = malloc(size);
    if(p!=nullptr)
    {
        *static_cast<int *>(p) = val;
    }
    return p;
}

void operator delete(void *p)
{
    cout << "Global Overloaded delete operator" << endl;
    free(p);
}

//Array version
void* operator new [](size_t size)
{
    cout << "Global Overloaded new operator with size " << size << endl;
    void *p = malloc(size);
    return p;
}

void operator delete [](void *p)
{
    cout << "Global Overloaded delete operator" << endl;
    free(p);
}
int main()
{
    //Test *t = new Test();
    int *x = new int;
    delete x;

    int *y = new int[10];
    delete[] y;

    int *z = new(1) int;
    delete z;
    return 0;
}