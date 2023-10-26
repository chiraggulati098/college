#include <iostream>
using namespace std;

int num_of_processes_input()
{
    int x;
    cout<<"enter number of processes: ";
    cin>>x;
    return x;
}

void input_ab_times(int n,int atime[],int btime[],int wtime[])
{
    for (int i=0;i<n;i++)   {
        cout<<"enter arrival time and burst time of P"<<i+1<<":"<<endl;
        cin>>atime[i]>>btime[i];
    }

    for (int i = 0; i < n; i++) {
    wtime[i] = 0;
    }
}

bool process_remaining(int n,int btime[])
{
    for (int i=0;i<n;i++)   {
        if (btime[i] > 0)   {
            return true;
        }
    }
    return false;
}

int main()
{
    int num = num_of_processes_input();
    int btime[100],atime[100],wtime[100];
    int total_wtime = 0, turnaround_time = 0;
    int sys_time = 0,run_time;
    input_ab_times(num,atime,btime,wtime);

    int min_index,p_waiting;

    for (int i = 0;i<num;i++)   {
        turnaround_time += btime[i];
    }

    while (process_remaining(num, btime))   {
        run_time = 0;
        p_waiting = 0;
        min_index = -1; 

        for (int i = 0; i < num; i++) {
            if (atime[i] <= sys_time && btime[i] > 0) {
                p_waiting += 1;
                if (min_index == -1 || btime[i] < btime[min_index]) {
                    min_index = i;
                }
            }
        }

        for (int i = 0; i < num; i++)   {
            if (atime[i] <= sys_time && btime[i] != 0)   {
                if (i == min_index) {
                    continue;
                }  
                wtime[i] += 1;
            }
        }

        if (min_index == -1) {
            sys_time += 1; 
        } else {
            btime[min_index] -= 1;
            sys_time += 1;
        }
    }

    for (int i = 0;i<num;i++)   {
        total_wtime += wtime[i];
    }

    turnaround_time += total_wtime;

    cout<<"total waiting time = "<<total_wtime<<endl;
    cout<<"total turnaround time = "<<turnaround_time<<endl;
    cout<<"avg waiting time = "<<float(total_wtime)/num<<endl;
    cout<<"avg turnaround time = "<<float(turnaround_time)/num<<endl;
    cout<<"sys_time = "<<sys_time<<endl;
    
    return 0;
}