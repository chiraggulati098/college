#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)    {
    int min_index;
    for (int i=0;i<n;i++)   {
        min_index = i;
        for (int j=i+1;j<n;j++) {
            if (arr[j]<arr[min_index])  {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
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
    selectionSort(arr,n);
    cout<<"\nSorted Array:\t";
    printArray(arr,n);
    cout<<endl;
    return 0;
}