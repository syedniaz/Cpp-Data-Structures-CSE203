#include <iostream>

int Factorial(int n)
{
    if (n > 1)
    {
        return n * Factorial (n - 1);
    }
    else return 1;
}

using namespace std;

int main()
{
    int n;
    cout << "Enter number for factorial: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << Factorial(n) << endl;

    return 0;
}