#include<iostream>
using namespace std;

class array1
{
public:
    void insert_element(int *&arr, int &n);
    void delete_element(int *&arr, int &n);
    void display(int arr[], int n);
};

void array1::insert_element(int *&arr, int &n)
{
    int value;
    cout<<"Enter element to insert :- ";
    cin>>value;
    cout<<endl;

    int *new_array = new int[n+1];

    for(int i=0;i<n;i++)
    {
        new_array[i]=arr[i];
    }

    new_array[n]=value;

    delete[] arr;
    arr=new_array;
    n++;
}

void array1::delete_element(int *&arr, int &n)
{
    if(n==0)
    {
        cout<<"Array is empty"<<endl;
        return;
    }

    int pos;
    cout<<"Enter position to delete :- ";
    cin>>pos;
    cout<<endl;

    if(pos<1 || pos>n)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    int *new_array = new int[n-1];
    int j=0;

    for(int i=0;i<n;i++)
    {
        if(i!=pos-1)
        {
            new_array[j]=arr[i];
            j++;
        }
    }

    delete[] arr;
    arr=new_array;
    n--;
}

void array1::display(int arr[], int n)
{
    if(n==0)
    {
        cout<<"Array is empty"<<endl;
        return;
    }

    cout<<"Array Elements are :- ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    array1 a;
    int n,i,ch;

    cout<<"Enter the size of array :- ";
    cin>>n;
    cout<<endl;

    int *arr = new int[n];

    cout<<"Enter elements :- ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    do
    {
        cout<<endl;
        cout<<"1. Insert Element"<<endl;
        cout<<"2. Delete Specific Element"<<endl;
        cout<<"3. Display Elements"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>ch;
        cout<<endl;

        switch(ch)
        {
        case 1:
            a.insert_element(arr,n);
            break;

        case 2:
            a.delete_element(arr,n);
            break;

        case 3:
            a.display(arr,n);
            break;

        case 4:
            break;

        default:
            cout<<"Invalid Choice"<<endl;
        }

    }while(ch!=4);

    delete[] arr;
    return 0;
}
