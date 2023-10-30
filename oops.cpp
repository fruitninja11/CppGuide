# include<iostream>
using namespace std;

class Main{
    private:
    string name;
    int age;
    int id;

    public:
    Main(const string &name, int age, int id): name(name), age(age), id(id) {
    cout << name << " " << age << " " << id << endl;} //cosntrucutor with a member initializor list
    
    void fun()
    {
        cout << "" << endl;
    }
    void fun(int a)
    {
        cout << "Base Class" << endl;
    }
    friend int funct(Main &); //friend fucntion can access private members of a class
};

int funct(Main &obj)
{
    cout << obj.name << " " << obj.age << " " << obj.id << endl;
    return 0;
}

class DerivedA : public Main{
    void fun(){

    }
};

class DerivedB : public Main{
    void fun(){

    }
};


int main()
{
    Main m("Shubham",22,1233);
    //m.fun();
    funct(m);
    return 0;
}