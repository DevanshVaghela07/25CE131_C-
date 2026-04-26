#include<iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int a=0,int b=0)
    {
        x=a;
        y=b;
    }

    Point& move(int dx,int dy)
    {
        this->x=this->x+dx;
        this->y=this->y+dy;
        return *this;
    }

    void display()
    {
        cout<<"X Coordinate :- "<<x<<endl;
        cout<<"Y Coordinate :- "<<y<<endl;
    }
};

void update_point(Point *p,int dx,int dy)
{
    p->move(dx,dy);
}

int main()
{
    int x,y,dx,dy,ch;

    cout<<"Enter initial x coordinate :- ";
    cin>>x;
    cout<<"Enter initial y coordinate :- ";
    cin>>y;

    Point p(x,y);

    do
    {
        cout<<endl;
        cout<<"1. Move Point"<<endl;
        cout<<"2. Chain Move Point"<<endl;
        cout<<"3. Update Point using Pointer"<<endl;
        cout<<"4. Display Point"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter Choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter dx and dy :- ";
            cin>>dx>>dy;
            p.move(dx,dy);
            break;

        case 2:
            int dx1,dy1,dx2,dy2;
            cout<<"Enter first dx and dy :- ";
            cin>>dx1>>dy1;
            cout<<"Enter second dx and dy :- ";
            cin>>dx2>>dy2;
            p.move(dx1,dy1).move(dx2,dy2);
            break;

        case 3:
            cout<<"Enter dx and dy :- ";
            cin>>dx>>dy;
            update_point(&p,dx,dy);
            break;

        case 4:
            p.display();
            break;

        case 5:
            break;

        default:
            cout<<"Invalid Choice"<<endl;
        }

    }while(ch!=5);

    return 0;
}
