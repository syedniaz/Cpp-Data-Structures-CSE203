#include <iostream>

using namespace std;

float aRR[13];
int size = 13;

void input_taker()
{
    cout << "Enter 13 elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> aRR[i];
    }
}

void SortDescend ()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (aRR[i] < aRR[j])
            {
                aRR[i] = aRR[i] + aRR[j];
                aRR[j] = aRR[i] - aRR[j];
                aRR[i] = aRR[i] - aRR[j]; //swap
            }
        }
    }
}




int main()
{

    input_taker();
    SortDescend();

    cout << "1st Max: " << aRR[0] << endl;
    cout << "2nd Max: " << aRR[1] << endl;
    cout << "1st Min: " << aRR[size-1] << endl;
    cout << "2nd Min: " << aRR[size-2] << endl;
    cout << "Median: " << aRR[size-7] << endl;

    return 0;
}
