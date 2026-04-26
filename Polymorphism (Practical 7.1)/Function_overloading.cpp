#include<iostream>
using namespace std;

class Calculator
{
private:
    float result[100];
    int count;

public:
    Calculator()
    {
        count=0;
    }

    int add(int a,int b)
    {
        return a+b;
    }

    float add(float a,float b)
    {
        return a+b;
    }

    float add(int a,float b)
    {
        return a+b;
    }

    float add(float a,int b)
    {
        return a+b;
    }

    void store(float r)
    {
        result[count]=r;
        count++;
    }

    void display()
    {
        if(count==0)
        {
            cout<<"No Results Stored"<<endl;
            return;
        }

        cout<<endl<<"Stored Results"<<endl;
        for(int i=0;i<count;i++)
        {
            cout<<"Result "<<i+1<<" = "<<result[i]<<endl;
        }
    }
};

int main()
{
    Calculator c;
    int ch;
    int a1,b1;
    float a2,b2;
    int a3;
    float b3;
    float ans;

    do
    {
        cout<<endl;
        cout<<"1. Add Two Integers"<<endl;
        cout<<"2. Add Two Float Numbers"<<endl;
        cout<<"3. Add Integer and Float"<<endl;
        cout<<"4. Add Float and Integer"<<endl;
        cout<<"5. Display All Results"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter two integers : ";
            cin>>a1>>b1;
            ans=c.add(a1,b1);
            c.store(ans);
            cout<<"Answer = "<<ans<<endl;
            break;

        case 2:
            cout<<"Enter two float numbers : ";
            cin>>a2>>b2;
            ans=c.add(a2,b2);
            c.store(ans);
            cout<<"Answer = "<<ans<<endl;
            break;

        case 3:
            cout<<"Enter integer and float : ";
            cin>>a3>>b3;
            ans=c.add(a3,b3);
            c.store(ans);
            cout<<"Answer = "<<ans<<endl;
            break;

        case 4:
            cout<<"Enter float and integer : ";
            cin>>b3>>a3;
            ans=c.add(b3,a3);
            c.store(ans);
            cout<<"Answer = "<<ans<<endl;
            break;

        case 5:
            c.display();
            break;

        case 6:
            break;

        default:
            cout<<"Invalid Choice"<<endl;
        }

    }while(ch!=6);

    return 0;
}
