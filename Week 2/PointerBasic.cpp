#include <iostream>

using namespace std;

int main()
{
    /*int x = 5;
    int *p = &x; // same as p = &x;
    

    /*cout << &p << endl;
    cout << p << endl;
    cout << *p << endl;

    p++;

    cout << &p << endl;
    cout << p << endl;
    cout << *p << endl;*/

    int z[5] = {1,2,3,4,5} ;
    int *pt = z; // int *pt = &z[0];
    //or int *pt;
    //   pt = z or pt = &z[0];

    cout << &pt << endl;
    cout << pt << endl;
    cout << *pt << endl;

    pt++;

    cout << &pt << endl;
    cout << pt << endl;
    cout << *pt << endl;


    return 0;
}