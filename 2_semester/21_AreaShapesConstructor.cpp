#include <iostream>
using namespace std;

class Area  {
    private:
        int radius, height, base, width, breadth;
    public:
        Area(int a) {
            switch(a)   {
                case 1:
                    cout<<"enter radius: ";
                    cin>>radius;
                    cout<<"area is "<<3.14*radius*radius;
                    break;
                case 2:
                    cout<<"enter height and base:"<<endl;
                    cin>>height>>base;
                    cout<<"area is "<<0.5*base*height;
                    break;
                case 3:
                    cout<<"enter height and width:\n";
                    cin>>breadth>>width;
                    cout<<"area is "<<breadth*width;
                    break;
            }
        }
};

int main()
{
    int a;
    do  {
        cout<<"FIND AREA OF:\n\n1. Circle\n2. Triangle\n3. Rectangle\n\nEnter your Choice: ";
        cin>>a;
    }   while(a>4 && a<0);
    Area ar (a);
    cout<<endl;
    return 0;
}
