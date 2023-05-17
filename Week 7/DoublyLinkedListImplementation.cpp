#include<iostream>

using namespace std;

struct node
{
    int value;
    node* next;
    node* prev;
};

node* head = NULL;
node* tail = NULL;

bool isempty()
{
    if(head==NULL) return true;
    else return false;
}

void insert_last(int new_value)
{
    node* new_node = new node;
    new_node->value = new_value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(isempty()==true)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void print_list()
{
    node* current_node = head;
    while(current_node!=NULL)
    {
        cout<<current_node->value<<endl;
        current_node = current_node->next;
    }
}

void print_reverse()
{
    node* current_node = tail;
    while(current_node!=NULL)
    {
        cout<<current_node->value<<endl;
        current_node = current_node->prev;
    }
}

void search_value(int search_value)
{
    node* current_node = tail;
    while(current_node!=NULL)
    {
        if(current_node->value == search_value)
        {
            cout<<"Found"<<endl;
            return;
        }
        current_node = current_node->prev;
    }
    cout<<"Not found"<<endl;
}

void delete_value(int value_to_be_deleted)
{
    if (isempty()==true)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        if(head==tail && head->value == value_to_be_deleted)
        {
            head = NULL;
            tail = NULL;
        }
        else if(head->value == value_to_be_deleted)
        {
            node* node_to_be_deleted = head;
            head = head->next;
            head->prev = NULL;
            delete node_to_be_deleted;
        }
        else 
        {
            node* current_node = head;
            while(current_node!=NULL)
            {
                if(current_node->value==value_to_be_deleted)
                {
                    node* node_to_be_deleted = current_node;
                    current_node->prev->next = current_node->next;
                    if (current_node==tail)
                    {
                        tail = tail->prev;
                    }
                    else 
                    {
                        current_node->next->prev = current_node->prev;
                    }
                    delete node_to_be_deleted;
                    //return;
                }
                current_node = current_node->next;
            }
        }
    }
}

int main()
{
    insert_last(10);
    insert_last(20);
    insert_last(30);

    print_list();

    print_reverse();

    search_value(20);
    search_value(50);
}