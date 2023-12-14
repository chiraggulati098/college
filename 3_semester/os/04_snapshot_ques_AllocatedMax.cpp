#include <iostream>
using namespace std;

void calc_available(const int max_available[],int available[],int allocation[5][3])   
{
    for (int i=0;i<3;i++)   {
        available[i] = max_available[i];
    }
    for (int i=0;i<5;i++)   {
        for (int j=0;j<3;j++)   {
            available[j] -= allocation[i][j];
        }
    }
}

bool checkSafe(const int max_available[],int available[],int allocation[5][3])
{
    calc_available(max_available,available,allocation);
    bool safe = true;
    for (int i=0;i<3;i++)   {
        if (available[i]<0) {
            safe = false;
        }
    }
    return safe;
}

int main()
{
    int allocation[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int need_matrix[5][3];
    const int max_available[3] = {10,5,7};
    int available[3];
    bool isSafe = true;
    
    for (int i=0;i<5;i++)   {
        for (int j=0;j<3;j++)   {
            need_matrix[i][j] = max[i][j] - allocation[i][j];
        }
    }

    cout<<"Need Matrix: \n";
    for (int i=0;i<5;i++)   {
        for (int j=0;j<3;j++)   {
            cout<<need_matrix[i][j]<<"\t";
        }
        cout<<endl;
    }

    isSafe = checkSafe(max_available,available,allocation);
    if (isSafe == true) {
        cout<<"System in Safe Space"<<endl;
    }   else    {
        cout<<"System not in Safe Space"<<endl;
    }

    calc_available(max_available,available,allocation);
    
    return 0;
}