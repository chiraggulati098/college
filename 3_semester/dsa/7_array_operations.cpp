#include <iostream>
using namespace std;

void print_array(int arr[],int n)   // function to print array taking in array and size as argument
{
    cout<<"\narray:\t";
    for (int i=0;i<n;i++)   {
        cout<<arr[i]<<"\t";
    }
}   

void enter_elements(int arr[],int n)    // function to input elements of array
{
    cout<<"enter "<<n<<" terms: \n";
    for (int i=0;i<n;i++)   {
        cin>>arr[i];
    }
}

int enter_size()    // function to input size of array from user
{
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    return n;
}

void array_insert(int arr[],int n)  // function to insert an element in the array
{   
    int num,pos;
    cout<<"enter index you want to insert at: ";
    cin>>pos;
    cout<<"enter integer you want to insert: ";
    cin>>num;
    for (int i=n;i>pos;i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = num;
}

int array_search(int arr[],int n)   // searching using linear search
{
    int num;
    cout<<"enter number to search: ";
    cin>>num;
    for (int i=0;i<n;i++)   {
        if (arr[i] == num)  {
            return i;
            break;
        }
    }
    return 0;
}

void array_sort(int arr[],int n)    // sorting with selection sort
{
    int min,temp;
    for (int i = 0;i<n;i++) {
        min = arr[i];
        for (int j=i+1;j<n;j++)   {
            if (arr[j]<min) {
                min = arr[j];
                temp = arr[i];
                arr[i] = min;
                arr[j] = temp;
            }
        }
    }
}

void array_deletion(int arr[],int n)    // deleting element using either value or index
{
    int choice;
    cout<<"choose option:\n1. Enter number to delete\n2. Enter index to delete\nenter option: ";
    cin>>choice;
    switch(choice)  {
        case 1: {
            int index = array_search(arr,n);
            cout<<endl;
            for (int i=index;i<n;i++)   {
                arr[i] = arr[i+1];
            }
            break;
        }
        case 2: {
            int index;
            cout<<"\nenter index: ";
            cin>>index;
            for (int i=index;i<n;i++)   {
                arr[i] = arr[i+1];
            }
            break;
        }
        default:    {
            cout<<"enter valid option";
        }
    }
}

int main()
{
    bool on = true; // to continue after 1 operation
    int arr[200],operation,n=enter_size();  // input size of array
    enter_elements(arr,n);  // enter elements of array
    print_array(arr,n); // display array to user
    while (on == true)  {
        cout<<"\nenter operation:\n1. Insertion\n2. Deletion\n3. Search\n4. Sorting\nEnter choice: ";
        cin>>operation;
        cout<<"\n";

        switch(operation)   {   // switch case for operation option
            case 1: {
                array_insert(arr,n);
                n+=1;
                break;
            }   
            case 2: {
                array_deletion(arr,n);
                n-=1;
                break;
            }
            case 3: {
                int index = array_search(arr,n);
                cout<<"the required number was found at index "<<index<<endl;
                break;
            }
            case 4: {
                array_sort(arr,n);
                break;
            }
            default:    {
                cout<<"enter a valid option\n";
            }
        }
        cout<<endl;
        print_array(arr,n);
        int continue_choice = 1;
        cout<<"\nPress 1 to continue or 0 to end: ";
        cin>>continue_choice;
        if (continue_choice == 0)   {
            on = false;
        }
    }

    return 0;
}