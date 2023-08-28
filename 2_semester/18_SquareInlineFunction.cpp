#include<iostream>
using namespace std;

class Square
{
    public:
        inline int square(int a)
        {
            return a*a;
        }
};

int main()
{
    Square s;
    int num;
    cout<<"enter num: ";
    cin>>num;
    cout<<"square of "<<num<<" = "<<s.square(num)<<endl;
    return 0;
}
