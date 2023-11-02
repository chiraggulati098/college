#include <iostream>
using namespace std;

int binary_search(int arr[],int low,int high,int key)
{
    while (low <= high)  {
        int m = (low+high)/2;

        if (arr[m] == key)  {
            return m;
        }

        if (key>arr[m]) {
            low = m+1;
        }   else    {
            high = m-1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    int key;

    cout<<"enter element to search: ";
    cin>>key;

    int result = binary_search(arr,0,n-1,key);
    if (result == -1)   {
        cout<<key<<" not in array"<<endl;
    }   else    {
        cout<<key<<" at index "<<result<<endl;
    }
    
    return 0;
}