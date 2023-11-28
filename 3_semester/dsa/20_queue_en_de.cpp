#include <iostream>
using namespace std;

int queue[10] = {12,13,11,8,23};
int MAX_SIZE = 10;
int back = 5;
int front = 0;

void dispQ(int a[],int n)   {
    cout<<"Queue:\t";
    for (int i=front;i<n;i++)   {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

void enqueue()  {
    int x;
    cout<<"enter data to enqueue: ";
    cin>>x;
    if (back == MAX_SIZE)   {
        cout<<"Overflow Error!\n";
    }   else    {
        queue[back] = x;
        back++;
    }
}

void dequeue()  {
    if (back == front)  {
        cout<<"Underflow Error!\n";
    }   else    {
        front++;
    }
    
}

int main()
{
    int choice;
    bool status = true;
    dispQ(queue,back);
    while(status)   {
        cout<<"1. enqueue\t2. dequeue\t0. exit\nchoice: ";
        cin>>choice;
        switch (choice)   {
            case 0: {
                dispQ(queue,back);
                status = false;
                break;
            }
            case 1: {
                enqueue();
                dispQ(queue,back);
                break;
            }
            case 2: {
                dequeue();
                dispQ(queue,back);
                break;
            }
        }
    }
    return 0;
}