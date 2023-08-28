#include <iostream>
using namespace std;

int main()
{
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10},b;
    cout<<"original array:\t";
    for (int i=0;i<11;i++)   {
        cout<<a[i]<<"\t";
    }
    cout<<"\n"<<endl;
    cout<<"enter the index you want to delete: ";
    cin>>b;
    for (int i=0;b+i<11;i++)  {
        a[b+i] = a[b+i+1];
    }
    cout<<endl;
    cout<<"array after deletion: ";
    for (int i=0;i<10;i++)   {
        cout<<a[i]<<"      ";
    }
    cout<<endl;
    return 0;
}