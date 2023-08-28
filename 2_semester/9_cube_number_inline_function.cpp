#include<iostream>
using namespace std;

inline int cube(int a)
{
    return a*a*a;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    cout << "cube of number = " << cube(n) << endl;
    return 0;
}
