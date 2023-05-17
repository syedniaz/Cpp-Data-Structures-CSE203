#include<iostream>

using namespace std;

struct Patients
{
    string name;
    int id;
    string contact;

    void print_details()
    {
        cout << "Patient Record:" << endl;
        cout << "Patient ID: " << id << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Patient Contact Number: " << contact << endl;
    }
};

void print_patient_details (Patients today[], int size, int n)
{
    int temp = -1;
    for (int i = 0; i < size; i++)
    {
        if ( today[i].id == n)
        {
            temp = i;
            break;
        }
    }
    if (temp == -1)
    {
        cout << "Patient not in database" << endl;
        return;
    }
    else today[temp].print_details();
}


int main()
{
    const int size = 5;
    Patients today [size];

    today[0].id = 2900;
    today[0].name = "Rafi";
    today[0].contact = "01100000000";

    today[1].id = 2901;
    today[1].name = "Sifat";
    today[1].contact = "01200000000";

    today[2].id = 2902;
    today[2].name = "Fardeen";
    today[2].contact = "01300000000";

    today[3].id = 2903;
    today[3].name = "Tanvir";
    today[3].contact = "01400000000";

    today[4].id = 2904;
    today[4].name = "Sameer";
    today[4].contact = "01500000000";

    int n;
    cout << "Enter Patient ID:" << endl;
    cin >> n;

    print_patient_details (today, size, n);
    

    return 0;
}