#include <iostream>

using namespace std;

int main ()
{   
    //variable declared dynamically(heap memory)
    int *ptr = new int;
    //int *ptr
    //ptr = new int
    *ptr = 6;
    cout << ptr << endl;
    cout << *ptr << endl;
    delete ptr;
    ptr = NULL;

    //dynamic 1d array
    int *ptr1 = new int [5];
    for (int i = 0; i < 5; i++)
    {
        ptr1[i] = i+1;
    }
    for (int i = 0; i < 5; i++) 
    {
        cout << *(ptr1+i) << endl; //ptr[i] = *(ptr+i)
    }

    delete []ptr1;
    ptr1 = NULL;

    return 0;
}
