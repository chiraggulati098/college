#include <iostream>
using namespace std;

int num_of_processes()
{
    int x;
    cout<<"enter number of total processes: ";
    cin>>x;
    return x;
}

int main()
{
    int num_of_p=num_of_processes(),burst_time[100],waiting_time[100],total_waiting_time=0,turnaround_time=0;
    waiting_time[0] = 0;
    cout<<"\n";
    for (int i=0;i<num_of_p;i++)    {
        cout<<"enter burst time of P"<<i+1<<": ";
        cin>>burst_time[i];
    }
    for (int i=1;i<num_of_p;i++)    {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }
    for (int i=0;i<num_of_p;i++)    {
        total_waiting_time += waiting_time[i];
        turnaround_time = turnaround_time + waiting_time[i] + burst_time[i];
    }
    cout<<"avg waiting time = "<<total_waiting_time/float(num_of_p)<<endl;
    cout<<"avg turnaround time = "<<turnaround_time/float(num_of_p)<<endl;
    return 0;
}