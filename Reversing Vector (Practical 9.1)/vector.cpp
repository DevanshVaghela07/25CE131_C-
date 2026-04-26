#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,x,ch;

    cout<<"Enter number of elements : ";
    cin>>n;

    vector<int> v;

    cout<<"Enter elements : ";
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    do
    {
        cout<<endl;
        cout<<"1. Reverse using std::reverse()"<<endl;
        cout<<"2. Manual Reverse using Iterators"<<endl;
        cout<<"3. Display Vector"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            reverse(v.begin(),v.end());
            cout<<"Vector Reversed using std::reverse()"<<endl;
            break;
        }

        case 2:
        {
            vector<int>::iterator start=v.begin();
            vector<int>::iterator end=v.end()-1;

            while(start<end)
            {
                int temp=*start;
                *start=*end;
                *end=temp;
                start++;
                end--;
            }

            cout<<"Vector Reversed manually"<<endl;
            break;
        }

        case 3:
        {
            cout<<"Vector Elements : ";
            for(vector<int>::iterator it=v.begin();it!=v.end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
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
