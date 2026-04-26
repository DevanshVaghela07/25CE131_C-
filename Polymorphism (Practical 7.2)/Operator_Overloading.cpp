#include<iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    Complex(float r=0,float i=0)
    {
        real=r;
        imag=i;
    }

    void input()
    {
        cout<<"Enter Real Part : ";
        cin>>real;
        cout<<"Enter Imaginary Part : ";
        cin>>imag;
    }

    Complex operator + (Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator - (Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    void display()
    {
        if(imag>=0)
        {
            cout<<real<<" + "<<imag<<"i"<<endl;
        }
        else
        {
            cout<<real<<" - "<<-imag<<"i"<<endl;
        }
    }
};

int main()
{
    int ch,n,i;
    Complex c1,c2,c3;

    do
    {
        cout<<endl;
        cout<<"1. Add Two Complex Numbers"<<endl;
        cout<<"2. Subtract Two Complex Numbers"<<endl;
        cout<<"3. Batch Addition of Complex Numbers"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice :- ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter First Complex Number"<<endl;
            c1.input();
            cout<<"Enter Second Complex Number"<<endl;
            c2.input();
            c3 = c1 + c2;
            cout<<"Result = ";
            c3.display();
            break;

        case 2:
            cout<<"Enter First Complex Number"<<endl;
            c1.input();
            cout<<"Enter Second Complex Number"<<endl;
            c2.input();
            c3 = c1 - c2;
            cout<<"Result = ";
            c3.display();
            break;

        case 3:
        {
            cout<<"Enter number of complex numbers : ";
            cin>>n;

            Complex *arr = new Complex[n];
            Complex sum;

            for(i=0;i<n;i++)
            {
                cout<<"Enter Complex Number "<<i+1<<endl;
                arr[i].input();
                sum = sum + arr[i];
            }

            cout<<"Sum of All Complex Numbers = ";
            sum.display();

            delete[] arr;
            break;
        }

        case 4:
            break;

        default:
            cout<<"Invalid Choice"<<endl;
        }

    }while(ch!=4);

    return 0;
}
