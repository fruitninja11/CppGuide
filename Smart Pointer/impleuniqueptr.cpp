/*
RAII
Smart pointer uses/implements the concept of RAII
Resource acquisition in initialization

So instead of using raw pointers which is a tradtional method
where we have to take care of delete, a wrapper class will take care of
the pointers of creation and deletion

Unique ptr:
When to use : when one resource is exclusively owned by one object;

*/

//unique ptr

#include<iostream>
#include<memory>
using namespace std;

//using template to create generic implementation of ptr
//pointer to int, double, string etc;

template <typename T>
class uniqueptr
{
private:
    T *res;

public:
    uniqueptr(T *a=nullptr):res(a)
    {
        cout << "Ctor" << endl;
    };

    //copy constructor not possible so delete
    uniqueptr(const uniqueptr<T> &ptr) = delete;

    //copy assignment operator not possible so delete
    uniqueptr& operator=(const uniqueptr<T> &ptr) = delete;

    //move constructor
    //transferred the ownership in move constructor
    uniqueptr(uniqueptr<T> &&ptr)
    {
        res = ptr.res;
        ptr.res = nullptr;
    }

    //move assignment operator
    uniqueptr& operator=(uniqueptr<T> &&ptr)
    {
        //check self move assignment
        if(this != &ptr)
        {
            if(res)
            {
                delete res;
            }
            res = ptr.res;
            ptr.res = nullptr;
        }
        return *this;
    }

    T* operator->()
    {
        return res;
    }

    T& operator*()
    {
        return *res;
    }

    T* get()
    {
        return res;
    }

    void reset(T* newres=nullptr)
    {
        if(res)
        {
            delete res;
        }

        res = newres;
    }

    ~uniqueptr()
    {
        cout << "Dtor" << endl;
        if(res)
        {
            delete res;
            res = nullptr;
        }
    };
};



int main()
{
    uniqueptr<int> ptr1(new int(10));
    //uniqueptr<int> ptr2(ptr1) ; //compilation error
    //uniqueptr<int> ptr3 = ptr1; //compilation error
    uniqueptr<int> ptr2(new int(500));

    //move constructor
    uniqueptr<int> ptr3 = std::move(ptr1);

    //move assignment operator
    ptr2 = std::move(ptr3);

    cout << *(ptr2);

    return 0;
}