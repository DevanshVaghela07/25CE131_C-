#include<iostream>
using namespace std;
class Savings_Account
{
    string Customer_Name;
    double Account_ID;
    long double Current_Balance;
public:
    void Create_Account();
    char Search_Account(double);
    void Deposit_Money();
    void Withdraw_Money();
    void Check_Balance();
};

void Savings_Account::Create_Account()
{
    fflush(stdin);
    cout<<endl<<"Enter the Account holder name:- ";
    cin>>Customer_Name;
    cout<<endl;

    cout<<"Enter the account ID :- ";
    cin>>Account_ID;
    cout<<endl;


    cout<<"Enter the account Balance :- ";
    cin>>Current_Balance;
    cout<<endl;


}

char Savings_Account::Search_Account(double x)
{
    if(x==Account_ID)
    {
        return 'V';
    }
    else
    {
        return 'I';
    }
}

void Savings_Account::Deposit_Money()
{
    long double Money1;
    cout<<endl<<"Enter the Amount of money to deposit :- ";
    cin>>Money1;
    cout<<endl;
    Current_Balance=Current_Balance+Money1;
}

void Savings_Account::Withdraw_Money()
{
    long double Money2;
    cout<<endl<<"Enter the Amount of money to withdraw :- ";
    cin>>Money2;
    cout<<endl;
    if(Money2<=Current_Balance)
    {
        Current_Balance=Current_Balance-Money2;
    }
    else
    {
        cout<<"Insufficient Balance"<<endl;
    }
}

void Savings_Account::Check_Balance()
{
    cout<<endl<<"Account Holder's Name :- "<<Customer_Name<<endl;
    cout<<"Account No. :- "<<Account_ID<<endl;
    fflush(stdin);
    cout<<"Balance of Account :- "<<Current_Balance<<endl;
}

int main()
{
    Savings_Account account[15];
    int ch,i,t=0;
lable:
    cout<<"1. Create Account"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Check Balance"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        account[t].Create_Account();
        t++;
        goto lable;

    case 2:
        double AD;
        cout<<"Enter the account ID :- "<<endl;
        cin>>AD;
        for(i=0; i<t; i++)
        {
            if(account[i].Search_Account(AD) == 'V')
            {
                account[i].Deposit_Money();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Account ID is invalid"<<endl;
        }
        goto lable;

    case 3:
        double AW;
        cout<<"Enter the account ID :- "<<endl;
        cin>>AW;
        for(i=0; i<t; i++)
        {
            if(account[i].Search_Account(AW) == 'V')
            {
                account[i].Withdraw_Money();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Account ID is invalid"<<endl;
        }
        goto lable;

    case 4:
        double AB;
        cout<<"Enter the account ID :- "<<endl;
        cin>>AB;
        for(i=0; i<t; i++)
        {
            if(account[i].Search_Account(AB) == 'V')
            {
                account[i].Check_Balance();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Account ID is invalid"<<endl;
        }
        goto lable;

    case 5:
        return 0;

    default:
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}
