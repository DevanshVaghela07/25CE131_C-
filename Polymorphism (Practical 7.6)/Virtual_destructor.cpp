#include<iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout<<"Base Destructor Called"<<endl;
    }
};

class Derived : public Base
{
private:
    int *ptr;

public:
    Derived()
    {
        ptr = new int[5];
        cout<<"Resource Allocated in Derived"<<endl;
    }

    ~Derived()
    {
        delete[] ptr;
        cout<<"Derived Destructor Called and Resource Released"<<endl;
    }
};

int main()
{
    Base *b;

    b = new Derived;

    delete b;

    return 0;
}
