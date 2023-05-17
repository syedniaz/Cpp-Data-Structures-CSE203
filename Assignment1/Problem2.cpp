#include <iostream>

using namespace std;

int Matarr [5][5];
int Diag1 [5];
int Diag2 [5];

void Input ()
{
    cout << "Enter elements of 5x5 matrix (25 elements): ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> Matarr[i][j];
        }
    }
}

void printArr(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

int SumArr(int arr[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

void PrintDiag1 ()
{
    for (int i = 0, j = 0; i < 5, j < 5; i++, j++)
    {
        Diag1 [i] = Matarr [i][j];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (Diag1[i] < Diag1[j])
            {
                Diag1[i] = Diag1[i] + Diag1[j];
                Diag1[j] = Diag1[i] - Diag1[j];
                Diag1[i] = Diag1[i] - Diag1[j]; //swap
            }
        }
    }

    cout << "Principal Diagonal: ";
    printArr(Diag1);
    cout << endl;
    cout << "Sum = " << SumArr(Diag1) << endl;
}

void PrintDiag2 ()
{
    for (int i = 0, j = 4; i < 5, j >= 0; i++, j--)
    {
        Diag2 [i] = Matarr [i][j];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (Diag2[i] < Diag2[j])
            {
                Diag2[i] = Diag2[i] + Diag2[j];
                Diag2[j] = Diag2[i] - Diag2[j];
                Diag2[i] = Diag2[i] - Diag2[j]; //swap
            }
        }
    }
    
    cout << "Secondary Diagonal: ";
    printArr(Diag2);
    cout << endl;
    cout << "Sum = " << SumArr(Diag2) << endl;
}


int main()
{
    Input();
    cout << endl;
    PrintDiag1();
    PrintDiag2();

    return 0;
}
