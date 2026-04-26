#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addItem()
{
    ofstream file("inventory.txt", ios::app);

    if(!file)
    {
        cout<<"Error opening file!"<<endl;
        return;
    }

    string name;
    int quantity;
    float price;

    cout<<"Enter Item Name: ";
    cin>>name;

    cout<<"Enter Quantity: ";
    cin>>quantity;

    cout<<"Enter Price: ";
    cin>>price;

    file<<name<<" "<<quantity<<" "<<price<<endl;

    file.close();

    cout<<"Item added successfully!"<<endl;
}

void viewItems()
{
    ifstream file("inventory.txt");

    if(!file)
    {
        cout<<"Error: File not found!"<<endl;
        return;
    }

    string name;
    int quantity;
    float price;

    cout<<"\nInventory Items\n";

    while(file>>name>>quantity>>price)
    {
        cout<<"Name: "<<name<<" | Quantity: "<<quantity<<" | Price: "<<price<<endl;
    }

    file.close();
}

void searchItem()
{
    ifstream file("inventory.txt");

    if(!file)
    {
        cout<<"Error: File not found!"<<endl;
        return;
    }

    string searchName;
    string name;
    int quantity;
    float price;
    int found=0;

    cout<<"Enter item name to search: ";
    cin>>searchName;

    while(file>>name>>quantity>>price)
    {
        if(name==searchName)
        {
            cout<<"\nItem Found!"<<endl;
            cout<<"Name: "<<name<<" | Quantity: "<<quantity<<" | Price: "<<price<<endl;
            found=1;
            break;
        }
    }

    if(found==0)
    {
        cout<<"Item not found!"<<endl;
    }

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout<<"\n Inventory Management System \n";
        cout<<"1. Add Item"<<endl;
        cout<<"2. View All Items"<<endl;
        cout<<"3. Search Item"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addItem();
                break;

            case 2:
                viewItems();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice!=4);

    return 0;
}
