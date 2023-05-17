#include<iostream>

using namespace std;

struct Node
{
    int value;
    Node *Next;
};

void print (Node *n)
{
    while(n!=NULL)
    {
        cout << n->value << endl;
        n = n->Next;
    }
}

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;

    head->value = 10;
    second->value = 20;
    third->value = 30;

    head->Next = second;
    second->Next = third;
    third->Next = NULL;

    print(head);

    return 0;
}