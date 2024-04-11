#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)    {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i=0;i<n-1;i++) {
            if (arr[i]>arr[i+1])    {
                swap(arr[i],arr[i+1]);
                swapped = true;
            }
        }
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
    bubbleSort(arr,n);
    cout<<"\nSorted Array:\t";
    printArray(arr,n);
    cout<<endl;
    return 0;
}