#include <iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for (int i = 0;i<n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void insertion_sort(int arr[],int n)    
{
    int key,j;
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

int main()
{
    int arr[] = {64,25,12,22,11,74,42,12,53,65};
    int n = sizeof(arr)/sizeof(int);

    insertion_sort(arr,n);
    printArray(arr,n);

    return 0;
}