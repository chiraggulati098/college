#include <iostream>
using namespace std;

class Animal
{
    public:
        int legs = 4, tail = 1;
};

class Dog : public Animal
{
    public:
        void bark() {
            cout<<" Barks!!!";
        }
};

class Puppy : public Dog
{
    public:
        void weeps()    {
            cout<<" Weeps!!";
        }
};

int main()
{
    Puppy p1;
    cout<<"Puppy has "<<p1.legs<<" legs"<<endl;
    cout<<"Puppy has "<<p1.tail<<" tails"<<endl;
    cout<<"Puppy";
    p1.bark();
    cout<<endl;
    cout<<"Puppy";
    p1.weeps();
    cout<<endl;
    return 0;
}