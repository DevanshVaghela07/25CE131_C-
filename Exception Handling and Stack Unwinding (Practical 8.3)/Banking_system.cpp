#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
private:
    float balance;

public:
    BankAccount(float b=0)
    {
        balance=b;
    }

    void deposit(float amt)
    {
        if(amt<=0)
        {
            throw "Invalid deposit amount";
        }
        balance=balance+amt;
    }

    void withdraw(float amt)
    {
        if(amt>balance)
        {
            throw "Insufficient balance";
        }
        balance=balance-amt;
    }

    float getBalance()
    {
        return balance;
    }
};

string logs[100];
int top=-1;

void addLog(string s)
{
    top++;
    logs[top]=s;
}

void performWithdraw(BankAccount &b,float amt)
{
    addLog("Entered performWithdraw()");
    b.withdraw(amt);
    addLog("Exit performWithdraw()");
}

void transactionProcess(BankAccount &b,float amt)
{
    addLog("Entered transactionProcess()");
    performWithdraw(b,amt);
    addLog("Exit transactionProcess()");
}

int main()
{
    float bal,amt;
    int ch;

    cout<<"Enter initial balance : ";
    cin>>bal;

    BankAccount b(bal);

    try
    {
        cout<<"1. Deposit"<<endl;
        cout<<"2. Withdraw"<<endl;
        cin>>ch;

        if(ch==1)
        {
            addLog("Entered main() Deposit");
            cout<<"Enter deposit amount : ";
            cin>>amt;
            b.deposit(amt);
            addLog("Deposit Successful");
        }
        else if(ch==2)
        {
            addLog("Entered main() Withdraw");
            cout<<"Enter withdraw amount : ";
            cin>>amt;
            transactionProcess(b,amt);
            addLog("Withdraw Successful");
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }
    }
    catch(const char *msg)
    {
        addLog("Exception Caught in main()");
        cout<<msg<<endl;
    }

    cout<<endl<<"Final Balance = "<<b.getBalance()<<endl;

    cout<<endl<<"Transaction Logs"<<endl;
    for(int i=0;i<=top;i++)
    {
        cout<<logs[i]<<endl;
    }

    return 0;
}
