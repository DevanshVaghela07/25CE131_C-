#include<iostream>
using namespace std;

int Recursive(int arr[], int n)
{
    if (n == 0)
        return 0;

    return arr[n - 1] + Recursive(arr, n - 1);
}

int Iterative(int arr[],int n)
{
    int sum1=0;
    for(int i=0;i<n;i++)
    {
        sum1+=arr[i];
    }
    return sum1;
}

int main()
{
    int n,ch;

    lable:

    cout<<"Enter the Size of array :- ";
    cin>>n;
    int *arr = new int[n];
    cout<<endl;

    cout<<"Enter elements :- ";
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        cin>>arr[i];
    }

    cout<<"1. Recursive function"<<endl;
    cout<<"2. Iterative function"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice :- ";
    cin>>ch;
    cout<<endl;

    switch(ch)
    {
    case 1:
        cout<<"Sum through recursive function :- "<<Recursive(arr,n);
        cout<<endl;
        goto lable;

    case 2:
        cout<<"Sum through iterative function :- "<<Iterative(arr,n);
        cout<<endl;
        goto lable;

    case 3:
        break;

    default:
        cout<<endl;
        cout<<"Invalid Input"<<endl;
        goto lable;

    }
    delete [] arr;
    return 0;
}
