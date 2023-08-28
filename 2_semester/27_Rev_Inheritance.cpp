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

int main()
{
    RevNumber a;
    return 0;
}