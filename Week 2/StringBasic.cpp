#include<iostream>
#include<string>

using namespace std;

int main()
{
    string name1,name2;

    /*cout << "Enter full name: ";
    cin >> name1; // this prints till space
    cout << name1; */

    cout << endl;

    cout << "Enter full name: ";
    getline(cin, name2); // this prints everything including space and after that
    cout << name2;
    
        
    return 0;
}