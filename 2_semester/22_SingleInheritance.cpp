#include <iostream>
using namespace std;

class Base
{
    public:
        Base()  {
            cout<<"In Base Class"<<endl;
        }
};

class Derived : public Base
{
    public:
        Derived()  {
            cout<<"In Derived Class"<<endl;
        }
};

int main()
{
    Base b1;
    Derived d1;
    return 0;
}