#include <iostream>
using namespace std;

int sequential_search(int arr[],int n,int key)
{
    for (int i=0;i<n;i++)   { 
        if (key == arr[i])  {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    int key;

    cout<<"enter element to search: ";
    cin>>key;

    int result = sequential_search(arr,n,key);
    if (result == -1)   {
        cout<<key<<" not in array"<<endl;
    }   else    {
        cout<<key<<" at index "<<result<<endl;
    }
    
    return 0;
}