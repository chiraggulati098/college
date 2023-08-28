#include<iostream>
using namespace std;

void swapptr(int *x,int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void swapref(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int a = 26;
    int b = 37;
    cout << "before swapping:" << endl << "a = " << a <<"\tb = " << b << endl;
    swapptr(&a,&b);
    cout << "after using swap by pointer:\ta = " << a << "\tb = " << b << endl;
    swapref(a,b);
    cout << "after using swap by reference:\ta = " << a << "\tb = " << b << endl;
    return 0;
}
