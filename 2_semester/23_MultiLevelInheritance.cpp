#include <iostream>
using namespace std;

class Base
{
    public:
        Base()  {
            cout<<"In Base Class"<<endl;
        }
};

class Derived1 : public Base
{
    public:
        Derived1()  {
            cout<<"In Derived1 Class"<<endl;
        }
};

class Derived2 : public Derived1
{
    public:
        Derived2()  {
            cout<<"In Derived2 Class"<<endl;
        }
};

int main()
{
    Base a;
    Derived1 b;
    Derived2 c;
    return 0;
}