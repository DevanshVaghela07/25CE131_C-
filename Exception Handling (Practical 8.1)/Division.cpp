#include<iostream>
using namespace std;

int main()
{
    int a,b;

    try
    {
        cout<<"Enter numerator : ";
        if(!(cin>>a))
        {
            throw "Invalid input for numerator";
        }

        cout<<"Enter denominator : ";
        if(!(cin>>b))
        {
            throw "Invalid input for denominator";
        }

        if(b==0)
        {
            throw "Division by zero not allowed";
        }

        cout<<"Result = "<<a/b<<endl;
    }
    catch(const char *msg)
    {
        cout<<msg<<endl;
    }

    return 0;
}
