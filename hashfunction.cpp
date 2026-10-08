#include <iostream>
#include <string>
using namespace std;

int hashInteger(int key, int M)
{
    return key % M;
}

int hashString(string key, int M)
{
    int hash = 0;
    int R = 31;

    for (char ch : key)
    {
        hash = (hash * R + (int)ch) % M;
    }

    return hash;
}

int main()
{
    int choice;
    int M;

    cout << "Enter table size M: ";
    cin >> M;

    cout << "\n1. Integer Key";
    cout << "\n2. String Key";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int key;

        cout << "Enter integer key: ";
        cin >> key;

        cout << "Hash value = " << hashInteger(key, M);
    }
    else if (choice == 2)
    {
        string key;

        cout << "Enter string key: ";
        cin >> key;

        cout << "Hash value = " << hashString(key, M);
    }
    else
    {
        cout << "Invalid choice";
    }

    return 0;
}