#include<iostream>
#include<string>
using namespace std;

int super_digit(long long num)
{
    if (num < 10)
        return num;

    long long sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return super_digit(sum);
}

int main()
{
    int k,i;
    string s="";
    cout<<"Enter the no. :- ";
    cin>>s;
    cout<<endl;
    cout<<"Enter the no. of repetition :- ";
    cin>>k;
    cout<<endl;
    long long sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i]-'0');
    }
    sum = sum * k;
    cout<<super_digit(sum);
    return 0;
}
