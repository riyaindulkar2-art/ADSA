
#include <iostream>
using namespace std;

int main()
{
    int n;
    int length[100];

    cout << "Enter number of files: ";
    cin >> n;

    cout << "Enter length of each file:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> length[i];
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (length[i] > length[j])
            {
                int temp = length[i];
                length[i] = length[j];
                length[j] = temp;
            }
        }
    }

    int total = 0;
    int retrieval = 0;

   
    
    for (int i = 0; i < n; i++)
    {
        retrieval = retrieval + length[i];
        total = total + retrieval;
    }

    double average = (double)total / n;

    cout << "\nOptimal order: ";

    for (int i = 0; i < n; i++)
    {
        cout << length[i] << " ";
    }

    cout << "\nTotal Retrieval Time: " << total;

    cout << "\nAverage Retrieval Time: " << average;

    return 0;
}