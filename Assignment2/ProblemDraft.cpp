#include <iostream>

using namespace std;

int QueueArr [10];
int QueueSize = 10;
int tempArr [10];
int Rearindex = -1;
int FrontIndex = -1;

bool isEmpty ()
{
    if (Rearindex == -1) return true;
    else return false;
}

bool isFull()
{
    if (Rearindex == QueueSize - 1) return true;
    else return false;
}

void Enqueue (int n)
{
    if (isFull() == false)
    {
        if (FrontIndex == -1) FrontIndex++;
        Rearindex++;
        QueueArr [Rearindex] = n;
    }
    else cout << "Queue is full" << endl;
}

void Input ()
{
    cout << "Enter ";
    for(int i = 0; i < QueueSize; i++)
    {
        cout << "Semester of student " << i+1 << ": ";
        cin >> tempArr[i];
    }
}

void InputSortQueueFirst5 ()
{
    for(int i = 0; i < 5; i++)
    {
        Enqueue (tempArr[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        if (QueueArr[FrontIndex] < QueueArr[FrontIndex+i])
        {
            QueueArr[FrontIndex] = QueueArr[FrontIndex] + QueueArr[FrontIndex+i];
            QueueArr[FrontIndex+i] = QueueArr[FrontIndex] - QueueArr[FrontIndex+i];
            QueueArr[FrontIndex] = QueueArr[FrontIndex] - QueueArr[FrontIndex+i]; //swap
        }
    }
}


int main()
{
    cout << boolalpha; // for printing true/false instead of 1/0

    Input();


    return 0;
}
