#include<iostream>

using namespace std;

int main()
{
    int R, C;
    cout << "Enter Row then column: ";
    cin >> R >> C;

    int **table = new int*[R];

    for (int i = 0; i<R; i++)
    {
        table[i] = new int[C];
    }

    cout << "Enter elements: ";

    for (int i = 0; i<R; i++)
    {
        for (int j = 0; j<C; j++)
        {
            cin >>table[i][j];
        }
    }

    int k=0;
    for (int i = 0; i<R; i++)
    {
        for (int l = 0; l < i; l++)
        {
            cout << "  ";
        }

        int j = k;
        for (j ; j < C; j++)
        {
            cout << table[i][j] << " ";
        }

        cout << endl;
        
        k++;
    }

    for (int i = 0; i < R; i++)
    {
        delete [] table[i];
    }

    delete [] table;

    return 0;
}