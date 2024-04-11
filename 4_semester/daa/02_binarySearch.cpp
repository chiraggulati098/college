#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = (low+high)/2;

        if (arr[mid] == key)    {
            return mid;
        }

        if (arr[mid] > key) {
            high = mid - 1;
        }   else    {
            low = mid + 1;
        }
    }
    return -1;
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
    cout<<key<<" is found at index "<<binarySearch(arr, key, 0, n-1)<<endl;
    return 0;
}