#include <iostream>

using namespace std;

char StackArr [20];
int n = 4; //stacksize
int pointer = -1;

string str;

bool isEmpty()
{
    if (pointer == -1) return true;
    else return false;
}

bool isFull()
{
    if (pointer == n - 1) return true;
    else return false;
}

int peek ()
{
    if (isEmpty() == false) return StackArr[pointer];
    else cout << "Stack is empty" << endl;
}

void Push(char brac)
{
    if (isFull() == false)
    {
        pointer++;
        StackArr [pointer] = brac;
    }
    else cout << "Stack is full" << endl;
}

void Pop ()
{
    if (isEmpty() == false) pointer--;
    else cout << "Stack is empty" << endl;
}

bool CheckBalancedBracket()
{
    for (int i = 0; i < str.length()-1; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[' )
        {
            Push (str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
           if (isEmpty () == true)
           {
               return false;
           }
           else if (StackArr[pointer] == '(')
           {
               if (str[i] == ')')
               {
                   Pop();
               }
               else return false;
           }
           else if (StackArr[pointer] == '{')
           {
               if (str[i] == '}')
               {
                   Pop();
               }
               else return false;
           }
           else if (StackArr[pointer] == '[')
           {
               if (str[i] == ']')
               {
                   Pop();
               }
               else return false;
           }
        }
    }

    if (isEmpty() == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    cout << boolalpha;

    cout << "Enter expression: " << endl;
    cin >> str;

    cout << "Balanced: " << CheckBalancedBracket() << endl;

    return 0;
}
