#include<iostream>
using namespace std;
int main()
{
    int n,m,temp=0,a,t;

    cout<<"Enter the size of arrays(eg 1 2) :- ";
    cin>>n>>m;
    cout<<endl;

    int *array1 = new int[n];

    int *array2 = new int[m];

    cout<<"Enter Elements of first array :- ";
    for(int i=0; i<n; i++)
    {
        cin>>array1[i];
    }

    cout<<"Enter Elements of second array :- ";
    for(int i=0; i<m; i++)
    {
        cin>>array2[i];
    }

    int *mArray = new int[n+m];

    for(int i=0; i<n; i++)
    {
        mArray[i]=array1[i];
    }

    a=n;

    for(int i=0; i<m; i++)
    {
        mArray[a]=array2[i];
        a++;
    }

    t=m+n;

    for(int i=0; i<t; i++)
    {
        for(int j=i+1; j<t; j++)
        {
            if(mArray[i]>mArray[j])
            {
                temp=mArray[i];
                mArray[i]=mArray[j];
                mArray[j]=temp;
            }
        }
    }

    cout<<endl;

    cout<<"Final Merged array :- ";

    for(int i=0; i<t; i++)
    {
        cout<<mArray[i]<<" ";
    }
    delete [] array1;
    delete [] array2;
    return 0;
}
