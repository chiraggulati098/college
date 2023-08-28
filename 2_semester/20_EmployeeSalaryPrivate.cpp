#include<iostream>
using namespace std;

class Employee
{
    private:
        int salary;
    public:
        void set_salary(int s)  {
            salary = s;
        }
        int tax()   {
            return 0.1*salary;
        }
};

int main()
{
    Employee emp1;
    emp1.set_salary(50000);
    cout<<"10% tax = "<<emp1.tax()<<endl;
    return 0;
}
