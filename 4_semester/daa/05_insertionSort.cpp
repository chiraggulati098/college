#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)    {
    int key, j;
    for (int i=1;i<n;i++)   {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key)  {
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)   {
    for (int i=0;i<n;i++)   {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {23,34,13,51,642,34,12,63,14};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Original Array:\t";
    printArray(arr,n);
    insertionSort(arr,n);
    cout<<"\nSorted Array:\t";
    printArray(arr,n);
    cout<<endl;
    return 0;
}