#include<iostream>
using namespace std;

class Largest
{
    public:
        void largest(int a,int b, int c) {
            if (a>b && a>c)   {
                cout<<a;
            }
            else if (b>a && b>c)  {
                cout<<b;
            }
            else    {
                cout<<c;
            }
        }
};

int main()
{
    Largest l;
    l.largest(2,3,4);
    cout<<" is the largest number of the 3"<<endl;
    return 0;
}
