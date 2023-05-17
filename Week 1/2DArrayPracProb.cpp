#include <iostream>

using namespace std;

void InsertElements (int arr[][2])
{
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void PrintMatrix (int arr[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void PrintSumMatrix (int arr1[][2], int arr2[][2])
{
    int arr3 [2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr3 [i][j] = arr1[i][j] + arr2 [i][j];
        }
    }
    PrintMatrix (arr3);
}

int main()
{
    int Array1[2][2], Array2[2][2];

    cout << "Enter elements of first matrix(x1,x2,x3,x4)" << endl;
    cout << "x1 x2"<< endl;
    cout << "x3 x4"<< endl;

    InsertElements (Array1);

    cout << "Enter elements of second matrix(x1,x2,x3,x4)" << endl;

    InsertElements (Array2);

    cout << "The First matrix is: " << endl;

    PrintMatrix (Array1);

    cout << "The Second matrix is: " << endl;

    PrintMatrix (Array2);

    cout << "The Addition of two matrix is : " << endl;

    PrintSumMatrix (Array1, Array2);

    return 0;
}