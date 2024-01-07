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

void merge(int arr[],int left,int mid,int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    int a[n1],b[n2];
    for (int i=0;i<n1;i++)   {
        a[i] = arr[left+i];
    }
    for (int i=0;i<n2;i++)   {
        b[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while (i<n1 && j<n2)    {
        if (a[i]<b[j])  {
            arr[k] = a[i];
            k++;
            i++;
        }   else    {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i<n1)    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j<n2)    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[],int left,int right)    
{
    int mid;
    if (left<right) {
        mid = (left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main()
{
    int arr[] = {64,25,12,22,11,74,42,12,53,65};
    int n = sizeof(arr)/sizeof(int);
    int choice;

    cout<<"Original Array:\t";
    printArray(arr,n);
    cout<<"Press 1 for Quick Sort or 2 for Merge Sort: ";
    cin>>choice;
    if (choice == 1)    {
        quick_sort(arr,0,n-1);
        cout<<"Quick Sort:  ";
    }   else    {
        merge_sort(arr,0,n-1);
        cout<<"Merge Sort:  ";
    }
    printArray(arr,n);

    return 0;
}