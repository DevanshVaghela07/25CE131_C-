#include "invcls.h"
#include <iostream>
using namespace std;
char invcls::Search_item(int x)
{
    if(x==Item_ID)
    {
        return 'V';
    }
    else
    {
        return 'I';
    }
}

void invcls::Refill_item()
{
    int q1;
    cout<<endl<<"Enter the Amount of stock to update :- ";
    cin>>q1;
    cout<<endl;
    Item_quantity=Item_quantity+q1;
}

void invcls::Sale_item()
{
    int q2;
    cout<<endl<<"Enter the Amount of stock to sale :- ";
    cin>>q2;
    cout<<endl;
    if(q2<=Item_quantity)
    {
        Item_quantity=Item_quantity-q2;
    }
    else
    {
        cout<<"Insufficient Stock"<<endl;
    }
}

void invcls::Display_details()
{
    cout<<endl<<"Item Id :- "<<Item_ID<<endl;
    cout<<"Item Name :- "<<Item_name<<endl;
    cout<<"Item price :- "<<Item_price<<endl;
    cin.ignore();
    cout<<"Item's Stock :- "<<Item_quantity<<endl;
}

