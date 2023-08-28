#include <iostream>
using namespace std;

int choice_picker()
{
    int x;
    cout<<"enter operation:"<<endl;
    cout<<"1. push\t2. pop\t0. exit"<<endl<<endl;
    cout<<"enter: ";
    cin>>x;
    return x;
}

int main()
{
    int arr[5] = {12,25,16},top = 3,choice,push;
    bool start = true;
    cout<<"original array:\t";
    for (int i=0;i<top;i++) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    while (start == true)   {
       choice = choice_picker();
        switch (choice) {
            case 0:
                start = false;
                break;
            case 1:
                if (top == 5)   {
                    cout<<"array overloaded"<<endl;
                    start = false;
                }   
                else    {
                    top += 1;
                    cout<<"enter element to add: ";
                    cin>>push;
                    arr[top-1] = push;
                }
                break;
            case 2:
                if (top == 0)   {
                    cout<<"array underloaded"<<endl;
                    start = false;
                }   
                else    {
                    top -= 1;
                    arr[top] = 0;
                }
                break;
        } 
    cout<<"array:\t";
    for (int i=0;i<top;i++) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<endl;
    }
    return 0;
}