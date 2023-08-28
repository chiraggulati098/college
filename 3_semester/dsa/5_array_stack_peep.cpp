#include <iostream>
using namespace std;

int main()
{
    int s[10] = {21,3,37,219,79},top=5,x;
    cout<<"there are "<<top<<" terms in the stack"<<endl;
    cout<<"enter the pos of term to seach: ";
    cin>>x;
    if ((top-x)<0)  {
        cout<<"underflow!"<<endl;
    }
    else    {
        cout<<"term = "<<s[top-x]<<endl;
    }
}