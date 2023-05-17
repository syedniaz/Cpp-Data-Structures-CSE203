#include <iostream>

using namespace std;

int main ()
{
    string useremail = "niaz@gmail.com", userpass = "1234";
    string email, pass;

    cout << "Enter email and password" << endl;

    cin >> email >> pass;

    if (useremail == email)
    {
        if (userpass == pass)
        {
            cout << "Access granted" << endl;
        }
        else
        {
            cout << "Incorrect password" << endl;
        }
    }
    else
    {
        cout << "Email not in database" << endl;
    }

    return 0;
}
