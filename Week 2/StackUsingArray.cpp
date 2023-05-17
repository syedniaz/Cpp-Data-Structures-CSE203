#include <iostream>

using namespace std;

int StackArr [4];
int n = 4; //stacksize
int index = -1;

bool isEmpty()
{
    if (index == -1) return true;
    else return false;
}

bool isFull()
{
    if (index == n - 1) return true;
    else return false;
}

int peek ()
{
    if (isEmpty() == false) return StackArr[index];
    else cout << "Stack is empty" << endl;
}

void Push(int value)
{
    if (isFull() == false)
    {
        index++;
        StackArr [index] = value;
    }
    else cout << "Stack is full" << endl;
}

void Pop ()
{
    if (isEmpty() == false) index--;
    else cout << "Stack is empty" << endl;
}

int main()
{
    cout << boolalpha;

    return 0;
}
