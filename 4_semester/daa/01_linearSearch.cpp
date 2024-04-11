#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    int ind = -1;
    for (int i=0;i<n;i++)   {
        if (arr[i] == key)  {
            ind = i;
            return ind;
        }
    }
    return ind;
}

void printArray(int arr[], int n)   {
    cout<<"Array:\t";
    for (int i=0;i<n;i++)   {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {23,34,13,51,642,34,12,63,14};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr,n);
    cout<<"Enter key: ";
    int key;
    cin>>key;
    cout<<key<<" is found at index "<<linearSearch(arr,n,key)<<endl;
    return 0;
}