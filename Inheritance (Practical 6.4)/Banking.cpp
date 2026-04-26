#include<iostream>
#include<string>
using namespace std;

class Account
{
protected:
    int accno;
    float balance;
    string history[100];
    int top;

public:
    Account(int a=0,float b=0)
    {
        accno=a;
        balance=b;
        top=-1;
    }

    virtual ~Account()
    {
    }

    void addHistory(string s)
    {
        top++;
        history[top]=s;
    }

    void undoLast()
    {
        if(top==-1)
        {
            cout<<"No transaction to undo"<<endl;
            return;
        }

        string last = history[top];

        if(last=="deposit")
        {
            float amt;
            cout<<"Enter amount of last deposit to undo : ";
            cin>>amt;
            balance=balance-amt;
        }
        else if(last=="withdraw")
        {
            float amt;
            cout<<"Enter amount of last withdraw to undo : ";
            cin>>amt;
            balance=balance+amt;
        }

        top--;
        cout<<"Last transaction undone"<<endl;
    }

    virtual void deposit(float amt)
    {
        balance=balance+amt;
        addHistory("deposit");
    }

    virtual void withdraw(float amt)
    {
        if(amt<=balance)
        {
            balance=balance-amt;
            addHistory("withdraw");
        }
        else
        {
            cout<<"Insufficient Balance"<<endl;
        }
    }

    virtual void display()
    {
        cout<<"Account Number : "<<accno<<endl;
        cout<<"Balance : "<<balance<<endl;
    }

    void showHistory()
    {
        if(top==-1)
        {
            cout<<"No Transactions"<<endl;
            return;
        }

        cout<<"Transaction History"<<endl;
        for(int i=top;i>=0;i--)
        {
            cout<<history[i]<<endl;
        }
    }
};

class SavingsAccount : public Account
{
private:
    float interest;

public:
    SavingsAccount(int a=0,float b=0,float i=0) : Account(a,b)
    {
        interest=i;
    }

    ~SavingsAccount()
    {
    }

    void input()
    {
        cout<<"Enter Account Number : ";
        cin>>accno;
        cout<<"Enter Balance : ";
        cin>>balance;
        cout<<"Enter Interest Rate : ";
        cin>>interest;
    }

    void display()
    {
        Account::display();
        cout<<"Interest Rate : "<<interest<<endl;
    }
};

class CurrentAccount : public Account
{
private:
    float overdraft;

public:
    CurrentAccount(int a=0,float b=0,float o=0) : Account(a,b)
    {
        overdraft=o;
    }

    ~CurrentAccount()
    {
    }

    void input()
    {
        cout<<"Enter Account Number : ";
        cin>>accno;
        cout<<"Enter Balance : ";
        cin>>balance;
        cout<<"Enter Overdraft Limit : ";
        cin>>overdraft;
    }

    void withdraw(float amt)
    {
        if(amt<=balance+overdraft)
        {
            balance=balance-amt;
            addHistory("withdraw");
        }
        else
        {
            cout<<"Overdraft Limit Exceeded"<<endl;
        }
    }

    void display()
    {
        Account::display();
        cout<<"Overdraft Limit : "<<overdraft<<endl;
    }
};

int main()
{
    int ch,type;
    float amt;

    cout<<"1. Savings Account"<<endl;
    cout<<"2. Current Account"<<endl;
    cout<<"Enter choice :- ";
    cin>>type;

    if(type==1)
    {
        SavingsAccount s;
        s.input();

        do
        {
            cout<<endl;
            cout<<"1. Deposit"<<endl;
            cout<<"2. Withdraw"<<endl;
            cout<<"3. Display"<<endl;
            cout<<"4. Show Transaction History"<<endl;
            cout<<"5. Undo Last Transaction"<<endl;
            cout<<"6. Exit"<<endl;
            cout<<"Enter choice :- ";
            cin>>ch;

            switch(ch)
            {
            case 1:
                cout<<"Enter amount : ";
                cin>>amt;
                s.deposit(amt);
                break;

            case 2:
                cout<<"Enter amount : ";
                cin>>amt;
                s.withdraw(amt);
                break;

            case 3:
                s.display();
                break;

            case 4:
                s.showHistory();
                break;

            case 5:
                s.undoLast();
                break;
            }

        }while(ch!=6);
    }
    else if(type==2)
    {
        CurrentAccount c;
        c.input();

        do
        {
            cout<<endl;
            cout<<"1. Deposit"<<endl;
            cout<<"2. Withdraw"<<endl;
            cout<<"3. Display"<<endl;
            cout<<"4. Show Transaction History"<<endl;
            cout<<"5. Undo Last Transaction"<<endl;
            cout<<"6. Exit"<<endl;
            cout<<"Enter choice :- ";
            cin>>ch;

            switch(ch)
            {
            case 1:
                cout<<"Enter amount : ";
                cin>>amt;
                c.deposit(amt);
                break;

            case 2:
                cout<<"Enter amount : ";
                cin>>amt;
                c.withdraw(amt);
                break;

            case 3:
                c.display();
                break;

            case 4:
                c.showHistory();
                break;

            case 5:
                c.undoLast();
                break;
            }

        }while(ch!=6);
    }
    else
    {
        cout<<"Invalid Choice"<<endl;
    }

    return 0;
}
