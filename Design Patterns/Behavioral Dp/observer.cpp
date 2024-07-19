/*
Observer is a behavioral design pattern that lets you define a subscription mechanism to notify multiple objects about any events that happen to the object they’re observing.
Also known as: Event-Subscriber, Listener

This implementation effectively illustrates the Observer pattern's ability to maintain loosely coupled relationships 
between objects, where the subject (Group) and observers (User objects) interact without being tightly bound to each other.
*/

#include<iostream>
#include<list>
using namespace std;


//we created this class and made it as an interface
// so that each subscriber that inherits this class should implement notify
// and this is what we want that each subscriber should get updates/notifications 


//Subscriber Interface
class Subscriber
{

public:
    virtual void notify(string msg)=0;
    
};




//In this case our subscriber is user and hence it inherits subscriber
//Concrete Subscriber / observers
class User : public Subscriber
{
private:
    int user_id;
public:
    User(int id):user_id(id){};

    void notify(string msg) override
    {
        cout << "User " << user_id << " has recieved update :: " << msg << endl;
    }
};


//subject
class Group
{
private:
    list<Subscriber*> subscribers;
public:
    
    //subscribe
    void subscribe(Subscriber *user)
    {
        subscribers.push_back(user);
    }

    //un-subscribe
    void unsubscribe(Subscriber *user)
    {
        subscribers.remove(user);
    }

    //notify
    void notify(string msg)
    {
        for(auto user : subscribers)
        {
            user->notify(msg);
        }
    }



};


int main()
{
    Group* group = new Group;

    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("New Update Available");

    group->unsubscribe(user3);

    group->notify("Another Update Available!!");

    return 0;
}

