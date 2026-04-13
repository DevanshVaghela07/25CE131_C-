#include<iostream>
using namespace std;
class Bank_Account
{
    char Bank_Account_Holder_Name[40];
    double Account_No;
    long double Account_Balance;
public:
    void Create_Account();
    char Search_Account(double);
    void Deposit_Money();
    void Withdraw_Money();
    void Check_Balance();
};

void Bank_Account::Create_Account()
{
    fflush(stdin);
    cout<<endl<<"Enter the account holder name:- ";
    cin>>Bank_Account_Holder_Name;
    cout<<endl;

    cout<<"Enter the account No. :- ";
    cin>>Account_No;
    cout<<endl;


    cout<<"Enter the account Balance :- ";
    cin>>Account_Balance;
    cout<<endl;


}

char Bank_Account::Search_Account(double x)
{
    if(x==Account_No)
    {
        return 'V';
    }
    else
    {
        return 'I';
    }
}

void Bank_Account::Deposit_Money()
{
    long double Account1;
    cout<<endl<<"Enter the Amount of money to deposit :- ";
    cin>>Account1;
    cout<<endl;
    Account_Balance=Account_Balance+Account1;
}

void Bank_Account::Withdraw_Money()
{
    long double Account2;
    cout<<endl<<"Enter the Amount of money to withdraw :- ";
    cin>>Account2;
    cout<<endl;
    if(Account2<=Account_Balance)
    {
        Account_Balance=Account_Balance-Account2;
    }
    else
    {
        cout<<"Insufficient Balance"<<endl;
    }
}

void Bank_Account::Check_Balance()
{
    cout<<endl<<"Account Holder's Name :- "<<Bank_Account_Holder_Name<<endl;
    cout<<"Account No. :- "<<Account_No<<endl;
    fflush(stdin);
    cout<<"Balance of Account :- "<<Account_Balance<<endl;
}

int main()
{
    Bank_Account account[15];
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
        cout<<"Enter the account No. :- "<<endl;
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
            cout<<"Account no. is invalid"<<endl;
        }
        goto lable;

    case 3:
        double AW;
        cout<<"Enter the account No. :- "<<endl;
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
            cout<<"Account no. is invalid"<<endl;
        }
        goto lable;

    case 4:
        double AB;
        cout<<"Enter the account No. :- "<<endl;
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
            cout<<"Account no. is invalid"<<endl;
        }
        goto lable;

    case 5:
        return 0;

    default:
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}
