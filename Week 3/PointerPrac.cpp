#include<iostream>

using namespace std;

float *ReturnAddMax (float *ptr1, int m)
{
    float *temp = ptr1;
    for (int i = 0; i+1 < m; i++) 
    {   
        if ( (*(ptr1+i)) < ptr1[i+1] )  //ptr[i] = *(ptr+i)
        {
            temp = (ptr1+(i+1));
        }
    }
    return temp;
}

float ReturnMax (float *ptr1, int m)
{
    float temp = ptr1[0];
    for (int i = 0; i+1 < m; i++) 
    {   
        if ( (*(ptr1+i)) < ptr1[i+1] )  //ptr[i] = *(ptr+i)
        {
            temp = *(ptr1+(i+1));
        }
    }
    return temp;
}

int main()
{
    const int n = 5; 
    float x [n] = {1,2,5,4,3};
    float *ptr = x; // or *ptr = &x[0];
    
    //cout << ptr << endl;

    /*cout << "In main: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr+i) << " at "<< (ptr+i) << endl;
    }*/

    cout << "max value = " << ReturnMax(ptr,n) << endl;
    cout << "Address of max value = " << ReturnAddMax(ptr,n) << endl;
 
    return 0;
}