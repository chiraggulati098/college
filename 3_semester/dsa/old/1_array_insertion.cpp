#include <iostream>
using namespace std;

int main()
{
    int a[10] = {0,1,2,3,4},b;
    cout<<"original array:\t";
    for (int i=0;i<5;i++)   {
        cout<<a[i]<<"\t";
    }
    cout<<"\n"<<endl;
    cout<<"enter a number you want to insert: ";
    cin>>b;
    a[5] = b;
    cout<<"\nArray is:\t";
    for (int i=0;i<6;i++)   {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}