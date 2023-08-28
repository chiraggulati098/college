#include <iostream>
using namespace std;

template <typename T>
void swap_num(T& a,T& b) {
    T temp = b;
    b = a;
    a = temp;
}

int main()
{
    int x = 5,y = 6;
    cout<<"Before swapping:"<<endl;
    cout<<"x = "<<x<<"  y = "<<y<<endl;
    swap_num(x,y);
    cout<<"After swapping: "<<endl;
    cout<<"x = "<<x<<"  y = "<<y<<endl;
    return 0;
}