#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream fp;
    string filename;

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    cout<<"Enter the file name: ";
    cin>>filename;

    fp.open(filename.c_str());

    if(!fp)
    {
        cout<<"Error: File could not be opened or does not exist."<<endl;
        return 1;
    }

    char line[1000];

    while(fp.getline(line,1000))
    {
        lineCount++;
        bool inWord = false;

        for(int i=0; line[i]!='\0'; i++)
        {
            charCount++;

            if(line[i]!=' ' && line[i]!='\t')
            {
                if(inWord==false)
                {
                    wordCount++;
                    inWord = true;
                }
            }
            else
            {
                inWord = false;
            }
        }
    }

    fp.close();

    cout<<"\nTotal Lines: "<<lineCount<<endl;
    cout<<"Total Words: "<<wordCount<<endl;
    cout<<"Total Characters: "<<charCount<<endl;

    return 0;
}
