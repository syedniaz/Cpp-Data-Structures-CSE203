#include <iostream>

using namespace std;

int stuArr [2][10];
int noOfStu = 10;

void Input ()
{
    cout << "Enter ";
    for(int i = 0; i < noOfStu; i++)
    {
        cout << "Semester of student " << i+1 << ": ";
        cin >> stuArr[1][i];
        stuArr[0][i] = i+1;
    }
}

void Sort1to5 ()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (stuArr[1][i] == stuArr[1][j])
                {
                    if (stuArr[0][i] > stuArr[0][j])
                    {
                        stuArr[k][i] = stuArr[k][i] + stuArr[k][j];
                        stuArr[k][j] = stuArr[k][i] - stuArr[k][j];
                        stuArr[k][i] = stuArr[k][i] - stuArr[k][j]; //swapback for equal sem
                    }
                }
                else if (stuArr[1][i] < stuArr[1][j])
                {
                    stuArr[k][i] = stuArr[k][i] + stuArr[k][j];
                    stuArr[k][j] = stuArr[k][i] - stuArr[k][j];
                    stuArr[k][i] = stuArr[k][i] - stuArr[k][j]; //swap 1 to 5
                }
            }
        }
    }
}

void Sort5to10 ()
{
    for (int i = 5; i < noOfStu; i++)
    {
        for (int j = i + 1; j < noOfStu; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (stuArr[1][i] == stuArr[1][j])
                {
                    if (stuArr[0][i] > stuArr[0][j])
                    {
                        stuArr[k][i] = stuArr[k][i] + stuArr[k][j];
                        stuArr[k][j] = stuArr[k][i] - stuArr[k][j];
                        stuArr[k][i] = stuArr[k][i] - stuArr[k][j]; //swapback for equal sem
                    }
                }
                else if (stuArr[1][i] < stuArr[1][j])
                {
                    stuArr[k][i] = stuArr[k][i] + stuArr[k][j];
                    stuArr[k][j] = stuArr[k][i] - stuArr[k][j];
                    stuArr[k][i] = stuArr[k][i] - stuArr[k][j]; //swap 5 to 10
                }
            }
        }
    }
}

void printArr()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << stuArr[0][i] << endl;
    }
    cout << "---Cafeteria on break---" << endl;

    for (int i = 5; i < noOfStu; i++)
    {
        cout << "Student " << stuArr[0][i] << endl;
    }
    cout << "---Cafeteria closed---" << endl;
}

int main()
{
    cout << "Welcome to IUB Cafeteria" << endl;
    cout << "-----------------------------------" << endl;
    Input();
    Sort1to5();
    Sort5to10();
    printArr();

    return 0;
}

