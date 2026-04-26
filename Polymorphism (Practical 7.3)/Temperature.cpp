#include<iostream>
using namespace std;

class Fahrenheit;

class Celsius
{
private:
    float c;

public:
    Celsius(float x=0)
    {
        c=x;
    }

    void input()
    {
        cout<<"Enter temperature in Celsius : ";
        cin>>c;
    }

    operator Fahrenheit();

    float getC()
    {
        return c;
    }
};

class Fahrenheit
{
private:
    float f;

public:
    Fahrenheit(float x=0)
    {
        f=x;
    }

    void input()
    {
        cout<<"Enter temperature in Fahrenheit : ";
        cin>>f;
    }

    operator Celsius()
    {
        float c = (f-32)*5/9;
        return Celsius(c);
    }

    bool operator == (Fahrenheit x)
    {
        if(f==x.f)
            return true;
        else
            return false;
    }

    float getF()
    {
        return f;
    }

    void display()
    {
        cout<<f<<endl;
    }
};

Celsius::operator Fahrenheit()
{
    float f = (c*9/5)+32;
    return Fahrenheit(f);
}

int main()
{
    int ch,n,i,front=0,rear=-1;
    Celsius c;
    Fahrenheit f;

    do
    {
        cout<<endl;
        cout<<"1. Celsius to Fahrenheit"<<endl;
        cout<<"2. Fahrenheit to Celsius"<<endl;
        cout<<"3. Compare Two Fahrenheit Temperatures"<<endl;
        cout<<"4. Dynamic Queue Storage"<<endl;
        cout<<"5. Static Array Storage"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter Choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            c.input();
            f = c;
            cout<<"Converted Fahrenheit = ";
            f.display();
            break;
        }

        case 2:
        {
            f.input();
            c = f;
            cout<<"Converted Celsius = "<<c.getC()<<endl;
            break;
        }

        case 3:
        {
            Fahrenheit f1,f2;
            f1.input();
            f2.input();

            if(f1==f2)
                cout<<"Both temperatures are equal"<<endl;
            else
                cout<<"Both temperatures are not equal"<<endl;
            break;
        }

        case 4:
        {
            cout<<"Enter number of Celsius temperatures : ";
            cin>>n;

            Fahrenheit *q = new Fahrenheit[n];

            for(i=0;i<n;i++)
            {
                Celsius temp;
                temp.input();
                q[++rear] = temp;
            }

            cout<<"Queue Stored Fahrenheit Values"<<endl;
            while(front<=rear)
            {
                q[front].display();
                front++;
            }

            delete[] q;
            front=0;
            rear=-1;
            break;
        }

        case 5:
        {
            cout<<"Enter number of Fahrenheit temperatures : ";
            cin>>n;

            Celsius arr[100];

            for(i=0;i<n;i++)
            {
                Fahrenheit temp;
                temp.input();
                arr[i] = temp;
            }

            cout<<"Stored Celsius Values"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<arr[i].getC()<<endl;
            }

            break;
        }

        case 6:
            break;

        default:
            cout<<"Invalid Choice"<<endl;
        }

    }while(ch!=6);

    return 0;
}
