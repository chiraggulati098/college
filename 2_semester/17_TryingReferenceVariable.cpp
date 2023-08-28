#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int &ans = a;
    a++;
    ans++;
    cout<<"a = "<<a<<"\tans = "<<ans<<endl;
}
