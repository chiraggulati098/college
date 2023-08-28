#include<iostream>
using namespace std;

int main()
{
    int x,y;
    x = 5;
    y = ++x * ++x;
    cout << x << y;
    x = 5;
    y = x++ * ++x;
    cout << x << y << endl;
    return 0;
}
