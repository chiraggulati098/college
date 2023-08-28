#include <iostream>
using namespace std;

template <typename T> 
T myMin(T arr[],int n)
{
    T min = arr[0];
    for (int i=0;i<n;i++)  {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    float b[] = {7.8,3.4,5.6};
    int asize = sizeof(a)/sizeof(a[0]);
    int bsize = sizeof(b)/sizeof(b[0]);
    cout<<"Min of a is "<<myMin<int>(a,asize)<<endl;
    cout<<"Min of b is "<<myMin<float>(b,bsize)<<endl;
    return 0;
}