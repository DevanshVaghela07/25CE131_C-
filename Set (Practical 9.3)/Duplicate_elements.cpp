#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v;
    set<int> s;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
        s.insert(num);
    }

    cout << "\nList after removing duplicates:\n";

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
