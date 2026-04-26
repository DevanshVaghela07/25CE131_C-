#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n="",int a=0)
    {
        name=n;
        age=a;
    }

    void displayPerson()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

class Employee : public Person
{
protected:
    int empid;

public:
    Employee(string n="",int a=0,int id=0) : Person(n,a)
    {
        empid=id;
    }

    int getId()
    {
        return empid;
    }

    void displayEmployee()
    {
        displayPerson();
        cout<<"Employee ID : "<<empid<<endl;
    }
};

class Manager : public Employee
{
private:
    string department;

public:
    Manager(string n="",int a=0,int id=0,string d="") : Employee(n,a,id)
    {
        department=d;
    }

    void input()
    {
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Age : ";
        cin>>age;
        cout<<"Enter Employee ID : ";
        cin>>empid;
        cout<<"Enter Department : ";
        cin>>department;
    }

    void displayManager()
    {
        displayEmployee();
        cout<<"Department : "<<department<<endl;
        cout<<endl;
    }
};

int main()
{
    int ch,n,i;

    do
    {
        cout<<"1. Efficient Retrieval Method"<<endl;
        cout<<"2. Static Storage Method"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            cout<<"Enter number of managers : ";
            cin>>n;

            Manager *m = new Manager[n];

            for(i=0;i<n;i++)
            {
                cout<<endl<<"Enter details of Manager "<<i+1<<endl;
                m[i].input();
            }

            int sid;
            cout<<endl<<"Enter Employee ID to search : ";
            cin>>sid;

            int found=0;

            for(i=0;i<n;i++)
            {
                if(m[i].getId()==sid)
                {
                    cout<<endl<<"Manager Found"<<endl;
                    m[i].displayManager();
                    found=1;
                    break;
                }
            }

            if(found==0)
            {
                cout<<"Manager not found"<<endl;
            }

            delete[] m;
            break;
        }

        case 2:
        {
            Manager m[100];

            cout<<"Enter number of managers : ";
            cin>>n;

            for(i=0;i<n;i++)
            {
                cout<<endl<<"Enter details of Manager "<<i+1<<endl;
                m[i].input();
            }

            cout<<endl<<"All Manager Details"<<endl;

            for(i=0;i<n;i++)
            {
                m[i].displayManager();
            }

            break;
        }

        case 3:
            break;

        default:
            cout<<"Invalid Choice"<<endl;
        }

    }while(ch!=3);

    return 0;
}
