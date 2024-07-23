/*
NOTES:
0. unique_ptr is a class template.
1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
   when unique_ptr object goes out of scope.
3. similar to actual pointers we can use arrow and * on the object of unique_ptr,  because it is overloaded in unique_ptr class.
4. When exception comes then also it will de-allocate the memory hence no memory leak.
5. Not only object we can create array of objects of unique_ptr.

operations
release, reset, swap, get, get_deleter
*/

#include<iostream>
#include<memory>
using namespace std;


class Wrapper
{
private:
    int mem;
public:
    explicit Wrapper(int x=0):mem(x){};
    int get()
    {
        return mem;
    };

    ~Wrapper()
    {
        cout << "dest" << endl;
    }
};


int main()
{
    unique_ptr<Wrapper> p1(new Wrapper(100));
    
    //exception safe
    unique_ptr<Wrapper> p2 = make_unique<Wrapper>(20);


    cout << p1->get() << endl;
    cout << (*p2).get() << endl;

    Wrapper *p = p2.release();
    
    return 0;
}