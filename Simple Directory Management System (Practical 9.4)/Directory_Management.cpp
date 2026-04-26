#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do
    {
        cout << "\n1. Add Folder";
        cout << "\n2. Add File to Folder";
        cout << "\n3. Display Directory";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter folder name: ";
            cin >> folder;
            directory[folder];
            cout << "Folder added successfully.\n";
        }

        else if (choice == 2)
        {
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) != directory.end())
            {
                cout << "Enter file name: ";
                cin >> file;
                directory[folder].push_back(file);
                cout << "File added successfully.\n";
            }
            else
            {
                cout << "Folder not found.\n";
            }
        }

        else if (choice == 3)
        {
            cout << "\nDirectory Contents:\n";

            for (map<string, vector<string>>::iterator it = directory.begin(); it != directory.end(); it++)
            {
                cout << it->first << " : ";

                for (int i = 0; i < it->second.size(); i++)
                {
                    cout << it->second[i] << " ";
                }

                cout << endl;
            }
        }

    } while (choice != 4);

    return 0;
}
