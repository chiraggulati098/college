#include<iostream>
using namespace std;

class Fact
{
    private:
        int a;

    public:
        int factorial(int a)    {
            int result = 1;
            for (int i = a;i>0;i--)
                result*=i;
            return result;
        }
};

int main()
{
    Fact f;
    int n;
    cout<<"find factorial of: ";
    cin>>n;
    int result = f.factorial(n);
    cout<<result<<endl;
    return 0;
}
