#include<iostream>
#include<iomanip>
using namespace std;

ostream& currency(ostream& out)
{
    out<<"Rs. ";
    return out;
}

int main()
{
    int n;

    cout<<"Enter number of students: ";
    cin>>n;

    string name[100];
    float marks[100];
    float fees[100];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter student name of student "<<i+1<<" :";
        cin>>name[i];

        cout<<"Enter marks: ";
        cin>>marks[i];

        cout<<"Enter fees: ";
        cin>>fees[i];
    }

    cout<<endl;
    cout<<setfill('-')<<setw(55)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(15)<<"Name"<<setw(15)<<"Marks"<<setw(25)<<"Fees"<<endl;
    cout<<setfill('-')<<setw(55)<<"-"<<endl;
    cout<<setfill(' ');

    for(int i=0;i<n;i++)
    {
        cout<<setw(15)<<name[i]
            <<setw(15)<<fixed<<setprecision(2)<<marks[i]
            <<setw(20)<<currency<<fixed<<setprecision(2)<<fees[i]
            <<endl;
    }

    cout<<setfill('-')<<setw(55)<<"-"<<endl;

    return 0;
}
