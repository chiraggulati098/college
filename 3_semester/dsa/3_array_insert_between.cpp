#include <iostream>
using namespace std;

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8},b,pos;
    cout<<"original array:\t";
    for (int i=0;i<9;i++)   {
        cout<<a[i]<<"\t";
    }
    cout<<"\n"<<endl;
    cout<<"enter a number you want to insert: ";
    cin>>b;
    cout<<"enter index where you want to insert "<<b<<": ";
    cin>>pos;
    for (int i = 9;i>pos;i--)   {
        a[i] = a[i-1];
    }
    a[pos] = b;
    cout<<endl;
    cout<<"new array:\t";
    for (int i=0;i<10;i++)   {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}