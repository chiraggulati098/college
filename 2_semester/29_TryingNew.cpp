#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int;
    *ptr = 25;
    cout<<"value at ptr = "<<*ptr<<endl;
    cout<<"ptr = "<<ptr<<endl;
    delete ptr;
    return 0;
}