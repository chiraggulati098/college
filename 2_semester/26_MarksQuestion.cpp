#include <iostream>
using namespace std;

class student_marks
{
    public:
        int mark1,mark2;
        void mark_input() {
            cout<<"Enter the two highest marks:"<<endl;
            cin>>mark1>>mark2;
        }
};

class cocurricular_marks
{
    public:
        int cmarks;
        void cmarks_input()    {
            cout<<"Enter the marks for CoCurricular Activities: ";
            cin>>cmarks;
        }
};

class Result : public student_marks, public cocurricular_marks
{
    public:
        void show_result()  {
            int total_marks = mark1+mark2+cmarks;
            int avg_marks = total_marks/3;
            cout<<"Total marks: "<<total_marks<<endl;
            cout<<"Average marks: "<<avg_marks<<endl;
        }
};

int main()
{
    int roll;
    cout<<"Enter the Roll No.: ";
    cin>>roll;
    student_marks a;
    cocurricular_marks b;
    Result r1;
    r1.mark_input();
    r1.cmarks_input();
    cout<<"Roll No: "<<roll<<endl;
    r1.show_result();
    return 0;
}