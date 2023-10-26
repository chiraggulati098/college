#include <iostream>
using namespace std;

int num_of_processes_input()
{
    int x;
    cout<<"enter number of total processes: ";
    cin>>x;
    return x;
}

void input_wtime(int num,int arr[])
{
    for(int i=0;i<num;i++)  {
        cout<<"enter burst time of P"<<i+1<<": ";
        cin>>arr[i];
    }
}

void sort_wtime(int num,int arr[])
{
    for (int i=0;i<num;i++) {
        int min = arr[i];
        for (int j=i+1;j<num;j++)   {
            if (arr[j]<arr[i])  {
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;
            }
        }
    }
}

int main()
{
    int num_of_processes = num_of_processes_input(),btime[100],wtime[100],total_wtime,ttime=0;
    wtime[0] = 0;
    input_wtime(num_of_processes,btime);
    sort_wtime(num_of_processes,btime);
    for (int i=1;i<num_of_processes;i++)    {
        wtime[i] = btime[i-1] + wtime[i-1];
    }
    for (int i=0;i<num_of_processes;i++)    {
        total_wtime += wtime[i];
        ttime = ttime + wtime[i] + btime[i];
    }
    cout<<"avg waiting time = "<<total_wtime/float(num_of_processes)<<endl;
    cout<<"avg turnaround time = "<<ttime/float(num_of_processes)<<endl;
    return 0;
}