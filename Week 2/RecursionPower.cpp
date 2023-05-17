#include <iostream>

using namespace std;

int Power_by_loop(int b, int p)
{
    int power = 1;
    for (int i = 0; i < p; i++)
    {
        power = power * b;
    }
    return power;
}

int Power_by_recursion(int b, int p)
{
    if (p > 0) return b * Power_by_recursion (b, p-1);
    else return 1;
}


int main()
{
    int b, p;
    cout << "Enter base number: ";
    cin >> b;

    cout << "Enter power number: ";
    cin >> p;

    cout << "Power by loop: " << b << "^" << p << " = " << Power_by_loop(b, p) << endl;

    cout << "Power by recursion: " << b << "^" << p << " = " << Power_by_recursion(b, p) << endl;

    return 0;
}