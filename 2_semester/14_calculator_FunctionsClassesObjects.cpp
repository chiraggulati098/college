#include<iostream>
using namespace std;

class Calculator
{
    float a,b;
    public:
        void result()
        {
            cout<<"enter 1st num: ";
            cin>>a;
            cout<<"enter 2nd num: ";
            cin>>b;
        }

        float add()
        {
            return a+b;
        }

        float sub()
        {
            return a-b;
        }

        float mul()
        {
            return a*b;
        }

        float div()
        {
            return a/b;
        }
};

int main()
{
    int ch;
    Calculator c;
    cout<<"\nenter:\n1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n\nyour choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            c.result();
            cout<<c.add()<<endl;
            break;
        case 2:
            c.result();
            cout<<c.sub()<<endl;
            break;
        case 3:
            c.result();
            cout<<c.mul()<<endl;
            break;
        case 4:
            c.result();
            cout<<c.div()<<endl;
            break;
    }
    return 0;
}
