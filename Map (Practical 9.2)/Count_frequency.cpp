#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    string sentence, word;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> wordCount;

    stringstream ss(sentence);

    while (ss >> word)
    {
        wordCount[word]++;
    }

    cout << "\nWord Frequencies:\n";

    for (auto x : wordCount)
    {
        cout << x.first << " : " << x.second << endl;
    }

    return 0;
}
