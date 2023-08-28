#include<iostream>
using namespace std;

int m = 10;
int main()
{
    int m = 20;
    {
        int k = m;
        int m = 3;
        cout << "in inner:\nk = " << k << "\nm = " << m << "\n::m = " << ::m << endl;
    }
    cout << "\nin outer:\nm = " << m << "\n::m = " << ::m << endl;
    return 0;
}
