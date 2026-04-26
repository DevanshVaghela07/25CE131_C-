#include<iostream>
#include<string>
using namespace std;

class WordFrequency
{
private:
    string para;
    string words[200];
    int freq[200];
    int count;

public:
    WordFrequency()
    {
        count=0;
    }

    void to_lower(string &s)
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]+32;
            }
        }
    }

    void read_paragraph()
    {
        cout<<"Enter paragraph :- ";
        getline(cin,para);
    }

    void separate_words()
    {
        string temp="";

        for(int i=0;i<=para.length();i++)
        {
            if(para[i]==' ' || para[i]=='\0' || para[i]=='.' || para[i]==',' || para[i]=='!' || para[i]=='?')
            {
                if(temp!="")
                {
                    to_lower(temp);
                    int found=0;

                    for(int j=0;j<count;j++)
                    {
                        if(words[j]==temp)
                        {
                            freq[j]++;
                            found=1;
                            break;
                        }
                    }

                    if(found==0)
                    {
                        words[count]=temp;
                        freq[count]=1;
                        count++;
                    }

                    temp="";
                }
            }
            else
            {
                temp=temp+para[i];
            }
        }
    }

    void display()
    {
        cout<<endl<<"Word Frequencies :- "<<endl;
        for(int i=0;i<count;i++)
        {
            cout<<words[i]<<" = "<<freq[i]<<endl;
        }
    }
};

int main()
{
    WordFrequency w;
    w.read_paragraph();
    w.separate_words();
    w.display();
    return 0;
}
