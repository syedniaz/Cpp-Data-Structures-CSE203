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

void insert_first(int new_value)
{
    node* new_node = new node;
    new_node->value = new_value;
    new_node->next = NULL;

    if(isempty()==true)
    {
        head=new_node;
    }
    else 
    {
        new_node->next = head;
        head = new_node;
    }
}

void insert_last (int new_value)
{
    node *new_node = new node;
    new_node->value = new_value;
    new_node->next = NULL;

    if (isempty()==true)
    {
        head = new_node;
    }
    else
    {
        node *current_node = head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void delete_last ()
{
    if (isempty()==true)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (head->next == NULL)
        {
            node *node_to_delete = head;
            head = head->next; // head = NULL;
            delete node_to_delete;
            //delete_first();
        }
        else
        {
            node *current_node = head;
            while (current_node->next->next == NULL)
            {
                current_node = current_node->next;
            }
            node *node_to_delete = current_node->next;
            current_node->next = node_to_delete->next;; // current_node->next = NULL;
            delete node_to_delete;
        }
    }
}

void delete_first ()
{
    if (isempty()==true)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        node *node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }
}

void delete_value (int value_to_delete)
{
    if (isempty()==true)
    {
        cout << "List empty" << endl;
    }
    else
    {
        if (head->value==value_to_delete)
        {
            delete_first();
        }
        else 
        {
            node *current_node = head;
            while (current_node->next!= NULL)
            {
                if (current_node->value == value_to_delete && current_node->next == NULL)
                {
                    delete_last();
                }
                else if (current_node->value == value_to_delete)
                {
                    node *node_to_delete = current_node->next;
                    current_node->next = node_to_delete->next;
                    delete node_to_delete;
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
    node *current_node = head;
    while (current_node != NULL)
    {
        cout << current_node->value << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

void print_list_by_recursion(node *current_node)
{
    if (current_node != NULL)
    {
        cout << current_node->value << " ";
        print_list_by_recursion(current_node->next);
    }
}

void print_list_reverse(node *current_node)
{
    if (current_node != NULL)
    {
        print_list_reverse(current_node->next);
        cout << current_node->value << " ";
    }
}

bool search_value (int search_value)
{
    node *current_node = head;
    while (current_node != NULL)
    {
        if (current_node->value == search_value)
        {
            cout << "value found in list" << endl;
            return true;
        }
    }
    cout << "value not found in list" << endl;
    return false;
}

void count_nodes()
{
    int counter = 0;
    node *current_node = head;
    while (current_node != NULL)
    {
        counter++;
        current_node = current_node->next;
    }
    cout << "nodes = " << counter << endl;
}




int main()
{
    cout << boolalpha;

    insert_last(10);
    insert_last(20);
    insert_last(30);

    print_list();
    //count_nodes();

    insert_first(5);

    print_list_by_recursion(head);

    cout << endl;

    print_list_reverse(head);
    

    return 0;
}
