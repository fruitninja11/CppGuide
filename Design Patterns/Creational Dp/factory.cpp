/*
The Factory Design Pattern is a creational design pattern that provides a way to create objects without specifying the exact class of object that will be created. 
This pattern is used when we have a super class with multiple sub-classes and based on input, we need to return one of the sub-class. 
This pattern takes out the responsibility of instantiating a class from the client program to the factory class.

Factory Method is a creational design pattern that provides an interface for creating objects in a superclass, 
but allows subclasses to alter the type of objects that will be created.

Factory, in this context means creating , it will take care of creation logic without exposing it to client.
Now it is being loosely coupled.

Client uses the factory to create the product.
*/


#include <iostream>
using namespace std;

class Item{
    public:
    virtual void display()=0;
};

class Phone : public Item{
    public:
    void display()
    {
        cout << "Phone displayed" << endl;
    }
};
class IPhone : public Item{
    public:
    void display()
    {
        cout << "IPhone displayed" << endl;
    }
};
class Laptop : public Item{
    public:
    void display()
    {
        cout << "Laptop displayed" << endl;
    }
};
class Computer : public Item{
    public:
    void display()
    {
        cout << "Computer displayed" << endl;
    }
};
class Charger : public Item{
    public:
    void display()
    {
        cout << "Charger displayed" << endl;
    }
};


//we created a factory which will take take of all the creation logic
class Itemfactory
{
public:
// we created a static method here so that no object is created in client code 
// And this fucntion will take care of this and will return a type;
// But we can also create an object of factory in client and then call this
    static Item* getItem(string type)
    {
        Item *item;
        if (type == "Iphone") 
        {
           item = new IPhone();
           item->display();
           return item;
        }
        else if (type == "Phone") 
        {
            item = new Phone();
            item->display();
            return item;
        }
        else if (type == "Laptop") 
        {
            item = new Laptop();\
            item->display();
            return item;
        }
        else if (type == "Computer") 
        {
            item = new Computer();
            item->display();
            return item;
        }
        else if (type == "Charger") 
        {
            item = new Charger();
            item->display();
            return item;
        }
        else
        {
            cout << "Item not in inventory" << endl;
        }
        return nullptr;
    }
};

/*
=============================================================================
*/
// Client Side code / Client App
class Amazon
{

public:
    Amazon(){};

    //EARLIER without the factory, if we had to add an item so we had to write the logic
    // in client side app and would have to recompile the client code or redownload the client app
    // so we move this logic to itemfactory
    /*
    Item* getItem(string type)
    {
        if (type == "Iphone") 
        {
           return new IPhone();

        }
        else if (type == "Phone") 
        {
            return new Phone();

        }
        return nullptr;
    }
    */

   //with itemfactory we just need to call the function and pass the type
   // and it will return a type
    Item* getItem(string type)
    {
        return Itemfactory::getItem(type);
    }
};


//client code
int main()
{
    string type;
    cin >> type;
    Amazon app;
    Item *it = app.getItem(type);

    return 0;
}