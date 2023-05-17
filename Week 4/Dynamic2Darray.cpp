#include<iostream>

using namespace std;

int main()
{
    int R = 3, C= 4;
    int **table = new int*[R];

    for (int i = 0; i<R; i++)
    {
        table[i] = new int[C];
    }

    int counter = 0;
    for (int i = 0; i<R; i++)
    {
        for (int j = 0; j<C; j++)
        {
            table[i][j] = counter;
            counter++;
        }
    }

    for (int i = 0; i<R; i++)
    {
        for (int j = 0; j<C; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i<R; i++)
    {
        delete[] table[i];
    }

    delete[] table;

    return 0;
}
