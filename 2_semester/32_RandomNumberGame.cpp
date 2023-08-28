#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout<<"--- NUMBER GUESSER GAME ---"<<endl<<endl;
    int answer = (rand()%10)+1,choice;
    while (true)    {
        cout<<"make your guess: ";
        cin>>choice;
        if (choice == answer)   {
            cout<<"\nCONGRATULATIONS!!YOU MADE THE RIGHT GUESS!!"<<endl;
            break;
        }
        else if (choice > answer)   {
            cout<<"guess too high\n"<<endl;
        }
        else    {
            cout<<"choice too low\n"<<endl;
        }
    }
    return 0;
}