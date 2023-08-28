#include <iostream>
using namespace std;

class NumberInput
{
    public:
        int num;
        NumberInput()   {
            cout<<"Enter the number: ";
            cin>>num;
        }
};

class RevNumber : public NumberInput
{
    public:
        RevNumber() {
            int revnum = 0,temp;
            while (num>0)   {
                revnum *= 10;
                int temp = num%10;
                revnum += temp;
                num /= 10;
            }
            cout<<"Reverse of the number is "<<revnum<<endl;
        }
};

class FactNumber : public NumberInput
{
    public:
        FactNumber()    {
            int fact = 1;
            while (num>0)   {
                fact *= num;
                num--;
            }
            cout<<"Factorial of the number is "<<fact<<endl;
        }
};

int main()
{
    int end;
    bool continuing = true;
    while (continuing == true)  {
        int choice;
        cout<<"Enter 1 to find reverse of the number\nEnter 2 to find factorial of the number\nYour Choice: ";
        cin>>choice;
        switch (choice) {
        case 1:
        {
            RevNumber a;
            break;
        }
        case 2:
        {
            FactNumber b;
            break;
        }
        default:
        {
            cout<<"Enter either 1 or 2"<<endl;
            continue;
        }
        }
        cout<<"Press 0 to exit or 1 to retry: ";
        cin>>end;
        if (end == 0)   {
            continuing = false;
        }
    }
    return 0;
}