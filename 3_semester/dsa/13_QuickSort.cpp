#include <iostream>
using namespace std;

void print_array(int arr[],int n)
{
    for (int i=0;i<n;i++)   {
        cout<<arr[i]<<"\t";
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
    int arr[] = {60,80,75,77,1,25,15,5,10,22,19,17};
    int n = sizeof(arr)/sizeof(int);

    cout<<"initial array:\t";
    print_array(arr,n);

    quick_sort(arr,0,n-1);

    cout<<"sorted array:\t";
    print_array(arr,n);

    return 0;
}