#include <iostream>
using namespace std;

int main()
{
    int n=5;    // num of processes
    int r=3;    // num of resources

    int allocation[n][r] = {{0,1,0},    // allocated matrix
                            {2,0,0},
                            {3,0,2},
                            {2,1,1},
                            {0,0,2}};

    int max[n][r] = {{7,5,3},   // max need matrix
                    {3,2,2},
                    {9,0,2},
                    {2,2,2},
                    {4,3,3}};

    const int max_available[r] = {10,5,7};  // max resources available
    int need[n][r];  // need matrix
    int available[r];   // available resources

    // calculating availale resources 
    for (int i=0;i<r;i++)   {
        available[i] = max_available[i];
    }
    for (int i=0;i<n;i++)   {
        for (int j=0;j<3;j++)   {
            available[j] -= allocation[i][j];
        }
    }

    // calculating need matrix 
    for (int i=0;i<n;i++)   {
        for (int j=0;j<r;j++)   {
            need[i][j] = max[i][j]-allocation[i][j];
        }
    }

    // printing need matrix
    cout<<"Need Matrix:"<<endl;
    for (int i=0;i<n;i++)   {
        for (int j=0;j<r;j++)   {
            cout<<need[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    int f[n],ans[n],ind=0;  // f - control allocated resource, ans - holds safe sequence, ind - helps with index of safe sequence 
    for (int k=0;k<n;k++)   {
        f[k] = 0;
    }

    for (int k=0;k<5;k++)   {
        for (int i=0;i<n;i++)   {
            if (f[i]==0)    {
                int flag = 0;
                for (int j=0;j<r;j++)   {
                    if(need[i][j]>available[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag==0) {
                    ans[ind]=i;
                    ind++;
                    for (int y=0;y<r;y++)   {
                        available[y]+=allocation[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    cout<<"The Safe Sequence is:"<<endl;
    for (int i=0;i<n;i++)   {
        cout<<"P"<<ans[i];
        if (i<n-1)  {
            cout<<"->";
        }
    }
    cout<<endl;

    return 0;
}