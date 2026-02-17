#include<iostream>
using namespace std;
class Student
{
    int rollno;
    string name;
    int marks1;
    int marks2;
    int marks3;
public:
    Student()
    {
        rollno=1;
        name="XYZ";
        marks1=0;
        marks2=0;
        marks3=0;
    }
    Student(int r, string n, int m1, int m2, int m3)
    {
        rollno=r;
        name=n;
        marks1=m1;
        marks2=m2;
        marks3=m3;
    }
    float calculate_average();
    void display_details();
    void display_average();
    char search_r(int);
};
float Student::calculate_average()
{
    return (marks1 + marks2 + marks3) / 3.0;
}
void Student::display_details()
{
    cout<<"Rollno of student :- "<<rollno<<endl;
    cout<<"Name of student :- "<<name<<endl;
    cout<<"Marks of subject 1 :- "<<marks1<<endl;
    cout<<"Marks of subject 2 :- "<<marks2<<endl;
    cout<<"Marks of subject 3 :- "<<marks3<<endl;
}
void Student::display_average()
{
    cout<<"Average Marks :- "<<calculate_average();
    cout<<endl;
}
char Student::search_r(int x)
{
    if(x==rollno)
    {
        return 'V';
    }
    else
    {
        return 'I';
    }
}
int main()
{
    Student s[100];
    int ch,i,t=0,n1,n2;
    int r,M1,M2,M3;
    string N;
lable:
    cout<<endl;
    cout<<"1. Input Data"<<endl;
    cout<<"2. Display Details"<<endl;
    cout<<"3. Display Average"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {

    case 1:
        cout<<"Enter Rollno of student :- ";
        cin>>r;
        cout<<endl;

        cout<<"Enter Name of student :- ";
        cin>>N;
        cout<<endl;

        cout<<"Enter marks of subject 1 :- ";
        cin>>M1;
        cout<<endl;

        cout<<"Enter marks of subject 2 :- ";
        cin>>M2;
        cout<<endl;

        cout<<"Enter marks of subject 3 :- ";
        cin>>M3;
        cout<<endl;
        s[t] = Student(r, N, M1, M2, M3);
        t++;
        goto lable;

    case 2:
        cout<<"Enter Rollno of student :- ";
        cin>>n1;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(s[i].search_r(n1)=='V')
            {
                s[i].display_details();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Rollno not found"<<endl;
        }
        goto lable;

    case 3:
        cout<<"Enter Rollno of Student :- ";
        cin>>n2;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(s[i].search_r(n2)=='V')
            {
                s[i].display_average();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Rollno not found"<<endl;
        }
        goto lable;

    case 4:
        break;

    default:
        cout<<"Invalid Choice"<<endl;
        goto lable;
    }
    return 0;
}
