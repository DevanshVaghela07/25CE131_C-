#include<iostream>
using namespace std;
class rectangle
{
    int r;
    float length,breadth;
public:
    void input();
    float area();
    float perimeter();
    void display();
    void update();
    char search_r(int);
};

void rectangle::input()
{
    cout<<"Enter rectangle no. :- ";
    cin>>r;
    cout<<endl;
    cout<<"Enter the length of rectangle:- ";
    cin>>length;
    cout<<endl;
    cout<<"Enter the breadth of rectangle:- ";
    cin>>breadth;
    cout<<endl;
}

float rectangle::area()
{
    return length*breadth;
}

float rectangle::perimeter()
{
    return 2*(length+breadth);
}

void rectangle::display()
{
    cout<<"Perimeter of Rectangle :- "<<perimeter()<<endl;
    cout<<"Area of Rectangle :- "<<area()<<endl;
}

void rectangle::update()
{
    cout<<"Enter the new length of rectangle:- ";
    cin>>length;
    cout<<endl;
    cout<<"Enter the new breadth of rectangle:- ";
    cin>>breadth;
    cout<<endl;
}

char rectangle::search_r(int x)
{
    if(x==r)
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
    rectangle R[20];
    int ch,i,t=0;
lable:
    cout<<endl;
    cout<<"1. Input Data"<<endl;
    cout<<"2. Display Area"<<endl;
    cout<<"3. Display Perimeter"<<endl;
    cout<<"4. Display all"<<endl;
    cout<<"5. Update Data"<<endl;
    cout<<"6. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        R[t].input();
        t++;
        goto lable;
    case 2:
        int n;
        cout<<"Enter no. of the Rectangle for its area:- ";
        cin>>n;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(R[i].search_r(n)=='V')
            {
                cout<<"Area of Rectangle :- "<<R[i].area();
                cout<<endl;
                break;
            }
        }
        if(i==t)
        {
            cout<<"Rectangle not found"<<endl;
        }
        goto lable;
    case 3:
        int n1;
        cout<<"Enter no. of the Rectangle for its perimeter:- ";
        cin>>n1;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(R[i].search_r(n1)=='V')
            {
                cout<<"Perimeter of Rectangle :- "<<R[i].perimeter();
                cout<<endl;
                break;
            }
        }
        if(i==t)
        {
            cout<<"Rectangle not found"<<endl;
        }
        goto lable;
    case 4:
        int n3;
        cout<<"Enter no. of the Rectangle to display its details:- ";
        cin>>n3;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(R[i].search_r(n3)=='V')
            {
                R[i].display();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Rectangle not found"<<endl;
        }
        goto lable;
    case 5:
        int n4;
        cout<<"Enter no. of the Rectangle to update:- ";
        cin>>n4;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(R[i].search_r(n4)=='V')
            {
                R[i].update();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Rectangle not found"<<endl;
        }
        goto lable;
    case 6:
        break;
    default:
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}
