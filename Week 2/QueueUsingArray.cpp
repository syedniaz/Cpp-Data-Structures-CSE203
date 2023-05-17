#include <iostream>

using namespace std;

int QueueArr [5];
int QueueSize = 5;
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

void peek ()
{
    if (isEmpty() == false) cout << QueueArr[FrontIndex] << endl;
    else cout << "Queue is empty" << endl;
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

void Dequeue ()
{
    if (isEmpty()==false) FrontIndex++;
    else cout << "Queue is empty" << endl;
}

void Print()
{
    if (isEmpty() == false)
    {
        for (int i = FrontIndex; i < Rearindex+1; i++) cout << QueueArr[i] << endl;
    }
}

int main()
{
    cout << boolalpha; // for printing true/false instead of 1/0

    cout << isEmpty() << endl;

    cout << isFull() << endl;

    Enqueue (10);

    cout << isEmpty() << endl;

    Enqueue (20);
    Enqueue (30);
    Enqueue (40);
    Enqueue (50);

    Print();

    cout << isFull() << endl;

    cout << endl;
    peek();

    Dequeue();

    cout << endl;
    Print();

    cout << endl;
    peek();

    return 0;
}
