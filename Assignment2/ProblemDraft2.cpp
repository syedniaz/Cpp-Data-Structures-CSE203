#include <iostream>

using namespace std;

int tempArr [10];
int QueueSize = 10;

void Input ()
{
    cout << "Enter ";
    for(int i = 0; i < QueueSize; i++)
    {
        cout << "Semester of student " << i+1 << ": ";
        cin >> tempArr[i];
    }
}

void Sort ()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (tempArr[i] < tempArr[j])
            {
                tempArr[i] = tempArr[i] + tempArr[j];
                tempArr[j] = tempArr[i] - tempArr[j];
                tempArr[i] = tempArr[i] - tempArr[j]; //swap 1 to 5
            }
        }
    }

    for (int i = 5; i < QueueSize; i++)
    {
        for (int j = i + 1; j < QueueSize; j++)
        {
            if (tempArr[i] < tempArr[j])
            {
                tempArr[i] = tempArr[i] + tempArr[j];
                tempArr[j] = tempArr[i] - tempArr[j];
                tempArr[i] = tempArr[i] - tempArr[j]; //swap 5 to 10
            }
        }
    }
}

void printArr()
{
    for (int i = 0; i < QueueSize; i++)
    {
        cout << tempArr[i] << endl;
    }
}



int main()
{
    Input();
    Sort();
    printArr();

    return 0;
}
