#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

node *head = NULL;

bool isempty()
{
    if (head == NULL) return true;
    else return false;
}

void insert_last(int new_value)
{

    node *new_node = new node;
    new_node -> value = new_value;
    new_node -> next = NULL;
    if (isempty() == true)
    {
        head = new_node;
    }
    else
    {
        node *current_node = new node;
        current_node = head;
        while (current_node -> next != NULL)
        {
            current_node = current_node -> next;
        }
        current_node -> next = new_node;
    }
}

void insert_first (int new_value)
{
    node *new_node = new node;
    new_node->value = new_value;
    
    if (isempty()==true)
    {
        head = new_node;
    }
    else
    {
        new_node ->next = head;
        head = new_node;
    }
}

void delete_first()
{
    if (isempty()==true)
    {
        cout << "List empty" << endl;
    }
    else
    {
        node *node_to_be_deleted = head;
        head = head->next;
        delete node_to_be_deleted;
    }
}

void delete_last()
{
    if (isempty()==true)
    {
        cout << "List empty" << endl;
    }
    else
    {
        if (head->next == NULL)
        {
            node *node_to_be_deleted = head;
            head = head->next;
            delete node_to_be_deleted;
            // or delete_front()
        }
        else
        {
            node *current_node = head;
            while (current_node->next != NULL)
            {
                if (current_node->next->next == NULL)
                {
                    node *node_to_be_deleted = current_node->next;
                    current_node->next = NULL;  //current_node->next = node_to_be_deleted->next
                    delete node_to_be_deleted;
                }
                else
                {
                    current_node = current_node->next;
                }
            }

        }

    }
}

void print_list()
{
    node *current_node = new node;
    current_node = head;
    while (current_node != NULL)
    {
        cout << current_node -> value << endl;
        current_node = current_node -> next;
    }
}

int main()
{
    cout << boolalpha;
    cout << isempty() << endl;

    insert_last(10);
    insert_last(20);
    insert_last(30);
    insert_first(5);

    print_list();
    cout << isempty() << endl;

    delete_first();
    delete_last();

    insert_last(15);
    insert_last(25);

    print_list();

    delete_last();

    print_list();

    return 0;
}