#include <iostream>
using namespace std;

void merge(int A[], int lb, int mid, int ub)
{
    int B[100];

    int i = lb;
    int j = mid + 1;
    int k = lb;

   
    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }

        k++;
    }

  
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }


    while (j <= ub)
    {
        B[k] = A[j];
        j++;
        k++;
    }


    for (k = lb; k <= ub; k++)
    {
        A[k] = B[k];
    }
}


void mergeSort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

    
        mergeSort(A, lb, mid);

        
        mergeSort(A, mid + 1, ub);

      
        merge(A, lb, mid, ub);
    }
}

int main()
{
    int A[100];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}