#include <iostream>

using namespace std;

template<typename T>
T maximum(T arr[],int size)
{
    T max=arr[0];
    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

template<typename T>
void reverse(T arr[],int size)
{
    for(int i=size-1; i>=0; i--)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

int main()
{
    int n,ch,ch1;
lable:
    cout<<"1. Integer"<<endl;
    cout<<"2. Float"<<endl;
    cout<<"3. Char"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice :-";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
    case 1:
    {
        cout<<"Enter the no. of items :- ";
        cin>>n;
        cout<<endl;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        cout<<"1. Find Maximum Value"<<endl;
        cout<<"2. Reverse the array"<<endl;
        cout<<"3. Display Elements"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice :-";
        cin>>ch1;
        cout<<endl;
        switch(ch1)
        {
        case 1:
            cout<<"Maximum Value :- "<<maximum(a,n)<<endl;
            goto lable;
        case 2:
            reverse(a,n);
            goto lable;
        case 3:
            for(int i=0; i<n; i++)
            {
                cout<<" "<<a[i];
            }
            cout<<endl;
            goto lable;
        case 4:
        {
            break;
        }
        default:
            cout<<"Invalid Input"<<endl;
            goto lable;
        }
        goto lable;
    }
    case 2:
    {
        cout<<"Enter the no. of items :- ";
        cin>>n;
        cout<<endl;
        float a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        cout<<"1. Find Maximum Value"<<endl;
        cout<<"2. Reverse the array"<<endl;
        cout<<"3. Display Elements"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice :-";
        cin>>ch1;
        cout<<endl;
        switch(ch1)
        {
        case 1:
            cout<<"Maximum Value :- "<<maximum(a,n)<<endl;
            goto lable;
        case 2:
            reverse(a,n);
            goto lable;
        case 3:
            for(int i=0; i<n; i++)
            {
                cout<<" "<<a[i];
            }
            cout<<endl;
            goto lable;
        case 4:
        {
            break;
        }
        default:
            cout<<"Invalid Input"<<endl;
            goto lable;
        }
        goto lable;
    }
    case 3:
    {
        cout<<"Enter the no. of items :- ";
        cin>>n;
        cout<<endl;
        char a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        cout<<"1. Find Maximum Value"<<endl;
        cout<<"2. Reverse the array"<<endl;
        cout<<"3. Display Elements"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice :-";
        cin>>ch1;
        cout<<endl;
        switch(ch1)
        {
        case 1:
            cout<<"Maximum Value :- "<<maximum(a,n)<<endl;
            goto lable;
        case 2:
            reverse(a,n);
            goto lable;
        case 3:
            for(int i=0; i<n; i++)
            {
                cout<<" "<<a[i];
            }
            cout<<endl;
            goto lable;
        case 4:
        {
            break;
        }
        default:
            cout<<"Invalid Input"<<endl;
            goto lable;
        }
        goto lable;
    }
    case 4:
    {
        break;
    }
    default:
        cout<<"Invalid Input"<<endl;
        goto lable;
    }
    return 0;
}
