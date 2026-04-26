#include<iostream>
#include<cmath>
using namespace std;

class NegativeNumberException
{
};

int main()
{
    float n;

    try
    {
        cout<<"Enter a number : ";
        cin>>n;

        if(n<0)
        {
            throw NegativeNumberException();
        }

        cout<<"Square Root = "<<sqrt(n)<<endl;
    }
    catch(NegativeNumberException)
    {
        cout<<"Negative number not allowed for square root"<<endl;
    }

    return 0;
}
