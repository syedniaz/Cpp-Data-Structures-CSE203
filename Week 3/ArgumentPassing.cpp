#include <iostream>

using namespace std;

int cubebyvalue (int x)
{
    x = x*x*x;
    cout << "Cube by value(in function) = " << x << endl;
    return x;
}

int cubebyreference (int &x)
{
    x = x*x*x;
    return x;
}

int cubebypointer (int *x)
{
    *x = (*x)*(*x)*(*x);
    return *x;
}



using namespace std;

int main ()
{
    int x1,x2,x3;
    cout << "Enter a positive value to cube: ";
    cin >> x1;
    
    x3 = x2 = x1;

    cubebyvalue(x1);
    cout << "Cube by value(in main) = " << x1 << endl;
    
    cubebyreference(x2);
    cout << "Cube by reference = " << x2 << endl;

    cubebypointer(&x3);
    cout << "Cube by pointer = " << x3 << endl;


    return 0;
}
