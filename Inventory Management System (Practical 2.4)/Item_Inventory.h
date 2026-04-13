#include <iostream>
#include<string.h>
using namespace std;

class Item_Inventory
{
public:
    Item_Inventory()
    {
        Item_ID=0;
        Item_name="Nill";
        Item_price=0.0;
        Item_quantity=0;
    }
    Item_Inventory(int i,string n,float p,int q)
    {
        Item_ID=i;
        Item_name=n;
        Item_price=p;
        Item_quantity=q;
    }
    char Search_item(int);
    void Refill_item();
    void Sale_item();
    void Display_details();

protected:

private:
    int Item_ID;
    string Item_name;
    float Item_price;
    int Item_quantity;
};
