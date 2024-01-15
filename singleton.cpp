#include <iostream>
using namespace std;

class singleton
{
private:
    //private constructor to prevent direct instantiation
    singleton(/* args */){};
public:
    // static method to get the singleton instance;
    static singleton &getInstace()
    {
        // The instance is created only on the first call to getInstance
        static singleton instace;
        return instace;
    }

    // Example member function
    void printMessage() {
        std::cout << "Hello, I am a Singleton!" << std::endl;
    }
};

int main()
{
    //Acessing the singleton instance
    singleton& singletoninstance = singleton::getInstace();

    singletoninstance.printMessage();
    return 0;
}