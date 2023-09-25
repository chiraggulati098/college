#include <iostream>
using namespace std;

void print_stack(int s[],int top)  {
    cout<<"stack:\t";
    for (int i=0;i<=top;i++) {
        cout<<s[i]<<"\t";
    }
    cout<<endl;
}

void change(int s[],int top,int x,int i)
{
    s[top-i+1] = x;
}

int main()
{
    int s[10] = {21,3,37,219,79},top=4,x,i;
    print_stack(s,top);
    cout<<"enter the number of the element you want to change: ";
    cin>>i;
    if (top-i+1<=0) {
        cout<<"STACK UNDERFLOW"<<endl;
    }
    else    {
        cout<<"enter term you want to enter in place: ";
        cin>>x;
        change(s,top,x,i);
        print_stack(s,top);
    }
    return 0;
}