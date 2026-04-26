#include<iostream>
#include<string>
using namespace std;

class Grading
{
protected:
    float marks;

public:
    virtual void input()
    {
        cout<<"Enter Marks : ";
        cin>>marks;
    }

    virtual char computeGrade()=0;
};

class Undergraduate : public Grading
{
public:
    char computeGrade()
    {
        if(marks>=80)
            return 'A';
        else if(marks>=60)
            return 'B';
        else if(marks>=40)
            return 'C';
        else
            return 'F';
    }
};

class Postgraduate : public Grading
{
public:
    char computeGrade()
    {
        if(marks>=85)
            return 'A';
        else if(marks>=70)
            return 'B';
        else if(marks>=50)
            return 'C';
        else
            return 'F';
    }
};

int main()
{
    int n,i,type;

    cout<<"Enter number of students : ";
    cin>>n;

    Grading *g[100];
    string name[100];

    for(i=0;i<n;i++)
    {
        cout<<endl<<"Enter Student Name : ";
        cin>>name[i];

        cout<<"1. Undergraduate 2. Postgraduate : ";
        cin>>type;

        if(type==1)
            g[i]=new Undergraduate;
        else
            g[i]=new Postgraduate;

        g[i]->input();
    }

    cout<<endl<<"Student Grade Details"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Name : "<<name[i]<<endl;
        cout<<"Grade : "<<g[i]->computeGrade()<<endl;
        cout<<endl;
    }

    for(i=0;i<n;i++)
    {
        delete g[i];
    }

    return 0;
}
