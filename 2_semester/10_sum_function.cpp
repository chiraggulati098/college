#include<iostream>
using namespace std;

int add(int x,int y)
{
    return x+y;
}

int main()
{
    int a,b;
    cout << "enter 2 num:" << endl;
    cin >> a >> b;
    int result = add(a,b);
    cout << "sum is " << result << endl;
    return 0;
}
