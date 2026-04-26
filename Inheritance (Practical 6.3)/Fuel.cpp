#include<iostream>
#include<string>
using namespace std;

class Fuel
{
protected:
    string fueltype;

public:
    Fuel(string f="")
    {
        fueltype=f;
    }
};

class Brand
{
protected:
    string brandname;

public:
    Brand(string b="")
    {
        brandname=b;
    }
};

class Car : public Fuel, public Brand
{
public:
    Car(string f="",string b="") : Fuel(f), Brand(b)
    {
    }

    void input()
    {
        cout<<"Enter Fuel Type : ";
        cin>>fueltype;
        cout<<"Enter Brand Name : ";
        cin>>brandname;
    }

    void display()
    {
        cout<<"Fuel Type : "<<fueltype<<endl;
        cout<<"Brand Name : "<<brandname<<endl;
        cout<<endl;
    }
};

int main()
{
    int ch,n,i;

    do
    {
        cout<<"1. Dynamic Method"<<endl;
        cout<<"2. Static Method"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            cout<<"Enter number of cars : ";
            cin>>n;

            Car *c = new Car[n];

            for(i=0;i<n;i++)
            {
                cout<<endl<<"Enter details of Car "<<i+1<<endl;
                c[i].input();
            }

            cout<<endl<<"Car Details"<<endl;
            for(i=0;i<n;i++)
            {
                c[i].display();
            }

            delete[] c;
            break;
        }

        case 2:
        {
            Car c[100];

            cout<<"Enter number of cars : ";
            cin>>n;

            for(i=0;i<n;i++)
            {
                cout<<endl<<"Enter details of Car "<<i+1<<endl;
                c[i].input();
            }

            cout<<endl<<"Car Details"<<endl;
            for(i=0;i<n;i++)
            {
                c[i].display();
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
