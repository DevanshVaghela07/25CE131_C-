#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    string filename;
    ifstream file;
    string line;
    int num1,num2;
    int lineNo=0;
    int sum=0;

    while(true)
    {
        cout<<"Enter file name : ";
        cin>>filename;

        file.open(filename.c_str());

        if(file)
        {
            break;
        }
        else
        {
            cout<<"File not found. Try again? (y/n) : ";
            char ch;
            cin>>ch;
            if(ch=='n' || ch=='N')
            {
                return 0;
            }
            file.clear();
        }
    }

    while(getline(file,line))
    {
        lineNo++;

        stringstream ss(line);

        if(ss>>num1>>num2)
        {
            int total = num1 + num2;
            sum = sum + total;
            cout<<"Line "<<lineNo<<" Sum = "<<total<<endl;
        }
        else
        {
            cout<<"Corrupted data at line "<<lineNo<<endl;
        }
    }

    file.close();

    cout<<endl<<"Final Sum of All Valid Lines = "<<sum<<endl;

    return 0;
}
