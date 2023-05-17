#include <iostream>

using namespace std;

void printArr(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
}

void Search (int arr[], int n)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr [i] == n) 
        {
            cout << n << " is at index " << i << " or position " << i+1 << endl;
            return;
        }
    }
    cout << n << " is not in array" << endl;
}

void SortAscend (int arr[])
{
    int i,j;

    printArr(arr);
    cout << endl;

    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j]; //swapping without taking an extra variable
            }
        }
    }
    printArr(arr);
}

void SortDescend(int arr[])
{
    int i,j;

    printArr(arr);
    cout << endl;

    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (arr[i] < arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j]; //swapping without taking an extra variable
            }
        }
    }
    printArr(arr);
}

int main()
{
    int arr [5] {1,2,3,4,5};

    //printArr(arr);
    //Search(arr, 5);
    //SortAscend (arr);
    SortDescend (arr);

    return 0;
}