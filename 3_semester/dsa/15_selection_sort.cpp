#include <iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for (int i = 0;i<n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void selection_sort(int arr[],int n)    
{
    int min_index;
    for (int i=0;i<n-1;i++) {
        min_index = i;
        for (int j=i+1;j<n;j++) {
            if (arr[j]<arr[min_index])  {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

int main()
{
    int arr[] = {64,25,12,22,11,74,42,12,53,65};
    int n = sizeof(arr)/sizeof(int);

    selection_sort(arr,n);
    printArray(arr,n);

    return 0;
}