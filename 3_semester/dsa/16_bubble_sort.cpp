#include <iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for (int i = 0;i<n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void bubble_sort(int arr[],int n)    
{
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int j=0;j<n-1;j++) {
            if (arr[j]>arr[j+1])    {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
    }
}

int main()
{
    int arr[] = {64,25,12,22,11,74,42,12,53,65};
    int n = sizeof(arr)/sizeof(int);

    bubble_sort(arr,n);
    printArray(arr,n);

    return 0;
}