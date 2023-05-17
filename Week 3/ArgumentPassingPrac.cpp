#include <iostream>

using namespace std;

void SwapNumberValue (int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "Using pass by value:" << x << " " << y << endl;
}

void SwapNumberReference (int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "Using pass by reference:" << x << " " << y << endl;
}

void SwapNumberPointer (int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    cout << "Using pass by pointer:" << *x << " " << *y << endl;
}


int main ()
{
    int x1, x2, x3, y1, y2, y3;

    cout << "1st number: ";
    cin >> x1;

    cout << "2nd number: ";
    cin >> y1;

    x3 = x2 = x1;
    y3 = y2 = y1;

    SwapNumberValue (x1, y1);
    SwapNumberReference (x2, y2);
    SwapNumberPointer (&x3, &y3);

    return 0;
}
