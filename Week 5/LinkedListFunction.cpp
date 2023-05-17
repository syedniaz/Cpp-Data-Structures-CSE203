#include<iostream>

using namespace std;

struct Node
{
    int value;
    Node *Next;
};

Node *head = NULL;

bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else return false;
}

void insert_last(int new_value)
{
    Node *new_node = new Node;
    new_node -> value = new_value;
    new_node -> Next = NULL;
    
    if (isEmpty() == true)
    {
        head = new_node;
    }
    else
    {
        Node *current_node = head;
        while (current_node->Next != NULL)
        {
            current_node = current_node -> Next;
        }
        current_node->Next = new_node;
    }
}

void print_list()
{
    if (isEmpty() == true) cout << "List Empty" << endl;
    else
    {
        Node *current_node = head;
        while (current_node != NULL)
        {
            cout << current_node->value << endl;
            current_node = current_node->Next;
        }
    }
}

bool search_value(int search_value)
{
    Node *current_node = head;
    while (current_node!=NULL)
    {
        if (current_node->value == search_value) 
        {
            cout << "Match found" << endl;
            return true;
        }

    current_node = current_node->Next;
    cout << "Match not found" << endl;
    return false;
    }
}

void delete_value (int value_tobe_delete)
{
    if (isEmpty() == true)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (head->value == value_tobe_delete)
        {
            Node *node_tobe_deleted = head;
            head = head->Next;
            delete node_tobe_deleted;
        }
        else
        {
            Node *current_node = head;
            while (current_node->Next != NULL)
            {
                if (current_node->Next->value == value_tobe_delete)
                {
                    Node *node_tobe_deleted = current_node->Next;
                    current_node->Next = node_tobe_deleted->Next;
                    delete node_tobe_deleted;
                }
                else
                {
                    current_node = current_node->Next;
                }
            }
        }
    }
}


int main()
{
    /*insert_last(10);
    insert_last(20);
    insert_last(30);

    print_list();
    search_value(50);
    delete_value(30);
    
    cout<<"after deletion"<<endl;
    print_list();*/
    
    return 0;
}