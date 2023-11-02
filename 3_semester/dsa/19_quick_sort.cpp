#include <iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for (int i = 0;i<n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[high],i=(low-1);

    for (int j=low;j<=high;j++)   {
        if (arr[j]<pivot)   {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quick_sort(int arr[],int low,int high)
{
    if (high>low)   {
        int p = partition(arr,low,high);

        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}

int main()
{
    int arr[] = {64,25,12,22,11,74,42,12,53,65};
    int n = sizeof(arr)/sizeof(int);

    quick_sort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}