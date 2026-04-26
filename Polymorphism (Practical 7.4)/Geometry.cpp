#include<iostream>
using namespace std;

class Shape
{
public:
    virtual float Area()
    {
        return 0;
    }

    virtual void input()
    {
    }
};

class Rectangle : public Shape
{
private:
    float length;
    float width;

public:
    void input()
    {
        cout<<"Enter Length : ";
        cin>>length;
        cout<<"Enter Width : ";
        cin>>width;
    }

    float Area()
    {
        return length*width;
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    void input()
    {
        cout<<"Enter Radius : ";
        cin>>radius;
    }

    float Area()
    {
        return 3.14*radius*radius;
    }
};

int main()
{
    int ch,n,i,type;

    do
    {
        cout<<endl;
        cout<<"1. Dynamic Storage"<<endl;
        cout<<"2. Static Storage"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            cout<<"Enter number of shapes : ";
            cin>>n;

            Shape **s = new Shape*[n];

            for(i=0;i<n;i++)
            {
                cout<<"1. Rectangle 2. Circle : ";
                cin>>type;

                if(type==1)
                    s[i] = new Rectangle;
                else
                    s[i] = new Circle;

                s[i]->input();
            }

            cout<<endl<<"Areas"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<"Area = "<<s[i]->Area()<<endl;
            }

            for(i=0;i<n;i++)
            {
                delete s[i];
            }
            delete[] s;
            break;
        }

        case 2:
        {
            Shape *s[100];

            cout<<"Enter number of shapes : ";
            cin>>n;

            for(i=0;i<n;i++)
            {
                cout<<"1. Rectangle 2. Circle : ";
                cin>>type;

                if(type==1)
                    s[i] = new Rectangle;
                else
                    s[i] = new Circle;

                s[i]->input();
            }

            cout<<endl<<"Areas"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<"Area = "<<s[i]->Area()<<endl;
            }

            for(i=0;i<n;i++)
            {
                delete s[i];
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
