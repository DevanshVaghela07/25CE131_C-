#include<iostream>
#include<string>
using namespace std;

class Account_info
{
private:
    double account_no;
    string account_name;
    double account_balance;

public:
    static int count;

    Account_info()
    {
        account_no = 0;
        account_name = "";
        account_balance = 0;
    }

    void input_data()
    {
        cout << "Enter Account Number : ";
        cin >> account_no;

        cin.ignore();
        cout << "Enter Account Holder Name : ";
        getline(cin, account_name);

        cout << "Enter Initial Balance : ";
        cin >> account_balance;

        count++;
    }

    bool search(double acc)
    {
        return (acc == account_no);
    }

    void deposit(double amount)
    {
        account_balance += amount;
    }

    bool withdraw(double amount)
    {
        if(amount <= account_balance)
        {
            account_balance -= amount;
            return true;
        }
        else
        {
            cout << "Insufficient Balance!\n";
            return false;
        }
    }

    void update_data()
    {
        cin.ignore();
        cout << "Enter New Account Holder Name : ";
        getline(cin, account_name);

        cout << "Enter New Balance : ";
        cin >> account_balance;
    }

    void display()
    {
        cout << "Account Number   : " << account_no << endl;
        cout << "Account Holder   : " << account_name << endl;
        cout << "Current Balance  : " << account_balance << endl;
    }
};

int Account_info::count = 0;

int main()
{
    Account_info *ac = NULL;
    int size = 0;
    int choice;

    do
    {
        cout << endl;
        cout << "BANK ACCOUNT SYSTEM";
        cout << endl;
        cout << "1. Add New Account\n";
        cout << "2. Transfer Money\n";
        cout << "3. Update Account Details\n";
        cout << "4. Display Particular Account\n";
        cout << "5. Display All Accounts Summary\n";
        cout << "6. Display Total Number of Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            Account_info *temp = new Account_info[size + 1];

            for(int i = 0; i < size; i++)
            {
                temp[i] = ac[i];
            }

            delete[] ac;
            ac = temp;

            ac[size].input_data();
            size++;
            break;
        }

        case 2:
        {
            if(size == 0)
            {
                cout << "No Accounts Available.\n";
                break;
            }

            double sender, receiver, amount;
            int s = -1, r = -1;

            cout << "Enter Sender Account Number : ";
            cin >> sender;

            cout << "Enter Receiver Account Number : ";
            cin >> receiver;

            for(int i = 0; i < size; i++)
            {
                if(ac[i].search(sender))
                    s = i;

                if(ac[i].search(receiver))
                    r = i;
            }

            if(s == -1 || r == -1)
            {
                cout << "Invalid Sender or Receiver Account Number.\n";
                break;
            }

            cout << "Enter Amount to Transfer : ";
            cin >> amount;

            if(ac[s].withdraw(amount))
            {
                ac[r].deposit(amount);
            }

            break;
        }

        case 3:
        {
            double acc;
            int found = -1;

            cout << "Enter Account Number to Update : ";
            cin >> acc;

            for(int i = 0; i < size; i++)
            {
                if(ac[i].search(acc))
                {
                    found = i;
                    break;
                }
            }

            if(found != -1)
                ac[found].update_data();
            else
                cout << "Account Not Found.\n";

            break;
        }

        case 4:
        {
            double acc;
            int found = -1;

            cout << "Enter Account Number to Display : ";
            cin >> acc;

            for(int i = 0; i < size; i++)
            {
                if(ac[i].search(acc))
                {
                    found = i;
                    break;
                }
            }

            if(found != -1)
                ac[found].display();
            else
                cout << "Account Not Found.\n";

            break;
        }

        case 5:
        {
            if(size == 0)
            {
                cout << "No Accounts Available.\n";
            }
            else
            {
                cout << "\n ALL ACCOUNT SUMMARY \n";
                for(int i = 0; i < size; i++)
                {
                    ac[i].display();
                }
            }
            break;
        }

        case 6:
        {
            cout << "Total Number of Accounts Created : " << Account_info::count << endl;
            break;
        }

        case 7:
        {
            break;
        }

        default:
            cout << "Invalid Choice.\n";
        }

    } while(choice != 7);

    delete[] ac;
    return 0;
}
