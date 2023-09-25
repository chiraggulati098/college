#include <iostream>
#include <string>
using namespace std;

int input_row_column(string x)  
{
    int num;
    cout<<"enter number of "<<x<<": ";
    cin>>num;
    return num;
}

void input_array(int arr[][300],int r,int c)
{
    for (int i = 0;i<r;i++) {
        for (int j=0;j<c;j++)   {
            cin>>arr[i][j];
        }
    }
}

void print_array(int arr[][300],int r,int c)
{
    cout<<"\narray:\n";
    for (int i = 0;i<r;i++) {
        for (int j=0;j<c;j++)   {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void insert_array(int arr[][300],int r,int c)   
{
    int r_insert,c_insert,value_insert;
    cout<<"\nenter row and column to insert at: ";
    cin>>r_insert>>c_insert;
    cout<<"enter value to insert: ";
    cin>>value_insert;
    arr[r_insert-1][c_insert-1] = value_insert;
}

void delete_array(int arr[][300],int r,int c)   
{
    int r_del,c_del;
    cout<<"\nenter row and column to delete: ";
    cin>>r_del>>c_del;
    arr[r_del-1][c_del-1] = 0;
}

int main()  
{
    int row = input_row_column("rows"),col = input_row_column("columns");
    int arr[300][300],choice;
    bool continue_true = true;
    cout<<"\nenter "<<row*col<<" terms: \n";
    input_array(arr,row,col);
    print_array(arr,row,col);

    while (continue_true)   {
        cout<<"\nOperations:\n1. Insert Element\n2. Delete Element\n3. Exit\nChoose: ";
        cin>>choice;


        switch (choice) {
            case 1: {
                insert_array(arr,row,col);
                print_array(arr,row,col);
                break;
            }
            case 2: {
                delete_array(arr,row,col);
                print_array(arr,row,col);
                break;
            }
            case 3: {
                continue_true = false;
                break;
            }
            default:    {
                cout<<"enter a valid option\n";
            }
        }
    }

    return 0;
}