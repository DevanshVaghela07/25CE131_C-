#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Loan_EMI
{
public:
    Loan_EMI()
    {
        Loan_ID=0;
        Applicant_name="Nill";
        Total_loan_amount=0.0;
        Annual_interest_rate=0.0;
        Loan_tenure=0;
    }
    Loan_EMI(double i,string n,long double a,float in,int t)
    {
        Loan_ID=i;
        Applicant_name=n;
        Total_loan_amount=a;
        Annual_interest_rate=in;
        Loan_tenure=t;
    }
    char Search_ID(double);
    double Calculate_EMI();
    void Display_details();
private:
    double Loan_ID;
    string Applicant_name;
    long double Total_loan_amount;
    float Annual_interest_rate;
    int Loan_tenure;
};

char Loan_EMI::Search_ID(double x)
{
    if(x==Loan_ID)
    {
        return 'V';
    }
    else
    {
        return 'I';
    }
}

double Loan_EMI::Calculate_EMI()
{
    float r = (Annual_interest_rate / 100) / 12;  // monthly rate
    int n = Loan_tenure * 12;                     // months

    double emi = (Total_loan_amount * r * pow(1+r, n)) /
                (pow(1+r, n) - 1);

    return emi;
}

void Loan_EMI::Display_details()
{
    cout<<endl<<"Loan Id :- "<<Loan_ID<<endl;
    cout<<"Applicant's Name :- "<<Applicant_name<<endl;
    cout<<"Total loan amount :- "<<Total_loan_amount<<endl;
    cout<<"Annual Interest Rate :- "<<Annual_interest_rate<<"%"<<endl;
    cout<<"Loan Tenure :- "<<Loan_tenure<<endl;
    cout<<"EMI :- "<<Calculate_EMI()<<endl;
}

int main()
{
    Loan_EMI account[15];
    int ch,i,t=0,time;
    double id;
    string name;
    float interest;
    long double price;
lable:
    cout<<"1. Add Loan Details"<<endl;
    cout<<"2. Display details"<<endl;
    cout<<"3. Exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter the loan ID :- ";
        cin>>id;
        cout<<endl;

        cin.ignore();

        cout<<"Enter the applicant name:- ";
        getline(cin,name);
        cout<<endl;

        cout<<"Enter the total loan amount :- ";
        cin>>price;
        cout<<endl;

        cout<<"Enter the annual interest rate :- ";
        cin>>interest;
        cout<<endl;

        cout<<"Enter the total loan tenure :- ";
        cin>>time;
        cout<<endl;

        account[t]=Loan_EMI(id,name,price,interest,time);
        t++;
        goto lable;

    case 2:
        double ID;
        cout<<"Enter the id :- ";
        cin>>ID;
        cout<<endl;
        for(i=0; i<t; i++)
        {
            if(account[i].Search_ID(ID) == 'V')
            {
                account[i].Display_details();
                break;
            }
        }
        if(i==t)
        {
            cout<<"Id is invalid"<<endl;
        }
        goto lable;

    case 3:
        return 0;

    default:
        cout<<"Invalid Choice"<<endl;

    }
    return 0;
}
