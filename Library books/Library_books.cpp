#include<iostream>
#include<string.h>
using namespace std;
class library
{
    int Book_id;
    string title;
    string author;
    int copies;
public:
    char search_book(int);
    void add_book();
    void issue_book();
    void return_book();
    void display_book();
};
char library::search_book(int x)
{
    if(x==Book_id)
    {
        return 'A';
    }
    else
    {
        return 'N';
    }
}
void library::add_book()
{
    cout<<"Enter book id:- ";
    cin>>Book_id;
    cout<<endl;
    cout<<"Enter book Title:- ";
    cin>>title;
    cout<<endl;
    fflush(stdin);
    cout<<"Enter book Author's name:- ";
    cin>>author;
    cout<<endl;
    cout<<"Enter copies of the book:- ";
    cin>>copies;
    cout<<endl;
}
void library::issue_book()
{
    if(copies>0)
    {
        cout<<"Book Issued";
        copies--;
        cout<<endl;
    }
    else
    {
        cout<<"Copies not available";
        cout<<endl;
    }
}
void library::return_book()
{
    cout<<"Book Returned";
    copies++;
    cout<<endl;
}
void library::display_book()
{
    cout<<"Book's Id:- "<<Book_id;
    cout<<endl;
    cout<<"Title of the book:- "<<title;
    cout<<endl;
    cout<<"Author's Name:- "<<author;
    cout<<endl;
    cout<<"No. of copies:- "<<copies;
    cout<<endl;
}
int main()
{
    library l[50];
    int ch,t=0;
lable:
    cout<<"1. Add a New Book"<<endl;
    cout<<"2. Issue a Book"<<endl;
    cout<<"3. Return a Book"<<endl;
    cout<<"4. Display Book"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        l[t].add_book();
        t++;
        goto lable;
    case 2:
        int id,i;
        cout<<"Enter book id to be issued :- ";
        cin>>id;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(l[i].search_book(id)=='A')
            {
                l[i].issue_book();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Invalid Book Id"<<endl;
            cout<<endl;
        }
        goto lable;
    case 3:
        int id1;
        cout<<"Enter book id to return :- ";
        cin>>id1;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(l[i].search_book(id1)=='A')
            {
                l[i].return_book();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Invalid Book Id"<<endl;
            cout<<endl;
        }
        goto lable;
    case 4:
        int id2;
        cout<<"Enter book id:- ";
        cin>>id2;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(l[i].search_book(id2)=='A')
            {
                l[i].display_book();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Invalid Book Id"<<endl;
            cout<<endl;
        }
        goto lable;
    case 5:
        break;
    default:
        cout<<endl;
        cout<<"Invalid Input";
        cout<<endl;
        goto lable;
    }
    return 0;
}
