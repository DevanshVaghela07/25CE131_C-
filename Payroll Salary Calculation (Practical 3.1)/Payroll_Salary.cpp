#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
    string emp_name;
    double basic_salary;
    double bonus;

public:

    Employee(string name = "", double basic = 0, double bon = 1000)
    {
        emp_name = name;
        basic_salary = basic;
        bonus = bon;
    }

    void Add_data()
    {
        cout << "Enter Employee Name : ";
        cin.ignore();
        getline(cin, emp_name);

        cout << "Enter Basic Salary : ";
        cin >> basic_salary;

        int choice;
        cout << "1. Default Bonus" <<endl;
        cout << "2. Custom Bonus" <<endl;
        cout << "Enter Choice : ";
        cin >> choice;

        if(choice == 1)
        {
            bonus = 1000;
        }
        else
        {
            cout << "Enter Custom Bonus : ";
            cin >> bonus;
        }
    }

    inline double Total_salary()
    {
        return basic_salary + bonus;
    }

    void Display_data()
    {
        cout << "Employee Name   : " << emp_name << endl;
        cout << "Basic Salary    : " << basic_salary << endl;
        cout << "Bonus Amount    : " << bonus << endl;
        cout << "Total Salary    : " << Total_salary() << endl;
    }
};

int main()
{
    int n, ch, i;

    cout << "Enter the number of employees : ";
    cin >> n;

    Employee *emp = new Employee[n];

    do
    {
        cout << "\n PAYROLL MANAGEMENT SYSTEM \n";
        cout << "1. Add Data of Employee\n";
        cout << "2. Display Data of Employee\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            for(i = 0; i < n; i++)
            {
                cout << "\nEnter Details of Employee " << i + 1 << endl;
                emp[i].Add_data();
            }
            break;

        case 2:
            cout << "\n EMPLOYEE PAYROLL DETAILS \n";
            for(i = 0; i < n; i++)
            {
                emp[i].Display_data();
            }
            break;

        case 3:
            break;

        default:
            cout << "Invalid Input\n";
        }

    } while(ch != 3);

    delete[] emp;
    return 0;
}
