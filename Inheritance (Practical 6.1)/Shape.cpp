#include<iostream>
using namespace std;

class Shape
{
private:
    float radius;

public:
    void setRadius(float r)
    {
        radius = r;
    }

    float getRadius()
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    float area()
    {
        return 3.14 * getRadius() * getRadius();
    }
};

int main()
{
    int ch,n,i;

    do
    {
        cout<<endl;
        cout<<"1. Dynamic Method"<<endl;
        cout<<"2. Static Method"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter Choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            cout<<"Enter number of circles :- ";
            cin>>n;

            Circle *c = new Circle[n];

            for(i=0;i<n;i++)
            {
                float r;
                cout<<"Enter radius of circle "<<i+1<<" :- ";
                cin>>r;
                c[i].setRadius(r);
            }

            cout<<endl<<"Areas of Circles"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<"Circle "<<i+1<<" Area = "<<c[i].area()<<endl;
            }

            delete[] c;
            break;
        }

        case 2:
        {
            Circle c[100];

            cout<<"Enter number of circles :- ";
            cin>>n;

            for(i=0;i<n;i++)
            {
                float r;
                cout<<"Enter radius of circle "<<i+1<<" :- ";
                cin>>r;
                c[i].setRadius(r);
            }

            cout<<endl<<"Areas of Circles"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<"Circle "<<i+1<<" Area = "<<c[i].area()<<endl;
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
