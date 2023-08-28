#include <iostream>
using namespace std;

class Base
{
    private:
        int x = 23;
        int y = 21;
    protected:
        void printprotected()   {
            cout<<"This is the protected data in Base Class"<<endl;
        }
        int pro = 21;
    public:
        Base()  {
            cout<<"In Base Class"<<endl;
        }
        void printy()   {
            cout<<"y in base class private is "<<y<<endl;
        }
        int pub = 21;
};

class DerPublic : public Base
{
    public:
        DerPublic() {
            cout<<"In Public Derived Class"<<endl;
            cout<<pub<<endl;
            cout<<pro<<endl;
        }
};

class DerProtected: protected Base
{
    public:
        DerProtected() {
            cout<<"In Protected Derived Class"<<endl;
            cout<<pub<<endl;
            cout<<pro<<endl;
        }
};

class DerPrivate : private Base
{
    public:
        DerPrivate() {
            cout<<"In Private Derived Class"<<endl;
            cout<<pub<<endl;
            cout<<pro<<endl;
        }
};

int main()
{
    Base a;
    a.printy();
    DerPublic b;
    b.printy();
    DerProtected c;
    DerPrivate d;
    return 0;
}