#include<iostream>
#include<string.h>
#include "Item_Inventory.h"
using namespace std;
int main()
{
    Item_Inventory item[15];
    int ch,i,t=0,id,stock;
    string name;
    float price;
lable:
    cout<<"1. Add Items"<<endl;
    cout<<"2. New stock addition"<<endl;
    cout<<"3. Item sale"<<endl;
    cout<<"4. Display details"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter the item ID :- ";
        cin>>id;
        cout<<endl;

        cin.ignore();
        cout<<"Enter the item name:- ";
        cin>>name;
        cout<<endl;

        cout<<"Enter the price of item :- ";
        cin>>price;
        cout<<endl;


        cout<<"Enter the stock of item :- ";
        cin>>stock;
        cout<<endl;
        item[t]=Item_Inventory(id,name,price,stock);
        t++;
        goto lable;

    case 2:
        int ID1;
        cout<<"Enter the item id :- ";
        cin>>ID1;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(item[i].Search_item(ID1) == 'V')
            {
                item[i].Refill_item();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Item Id is invalid"<<endl;
        }
        goto lable;

    case 3:
        int ID2;
        cout<<"Enter the item id :- ";
        cin>>ID2;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(item[i].Search_item(ID2) == 'V')
            {
                item[i].Sale_item();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Item Id is invalid"<<endl;
        }
        goto lable;

    case 4:
        int ID3;
        cout<<"Enter the item id :- ";
        cin>>ID3;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(item[i].Search_item(ID3) == 'V')
            {
                item[i].Display_details();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Item Id is invalid"<<endl;
        }
        goto lable;

    case 5:
        return 0;

    default:
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}
