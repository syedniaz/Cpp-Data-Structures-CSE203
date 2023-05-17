#include<iostream>

using namespace std;

struct node
{
    int data;
    node *left_child;
    node *right_child;
    node *parent;
};

node *root = NULL;

node *create_new_node (int value)
{
    node *newnode = new node;
    newnode->data = value;
    newnode->left_child = NULL;
    newnode->right_child = NULL;
    newnode->right_child = NULL;

    return newnode;
}

node *insert_value(node *current_node, int value)
{
    if (current_node == NULL)
    {
        return create_new_node(value);
    }
    if (current_node->data > value)
    {
        current_node->left_child = insert_value (current_node->left_child, value);
        current_node->left_child->parent = current_node;
    }
    else
    {
        current_node->right_child = insert_value (current_node->right_child, value);
        current_node->right_child->parent = current_node;
    }

    return current_node;
}

void pre_order (node *current_node)
{
    if (current_node != NULL)
    {
        cout << current_node->data << endl;
        pre_order (current_node->left_child);
        pre_order (current_node->right_child);
    }
}

void in_order (node *current_node)
{
    if (current_node != NULL)
    {
        in_order (current_node->left_child);
        cout << current_node->data << endl;
        in_order (current_node->right_child);
    }
}

void post_order (node *current_node)
{
    if (current_node != NULL)
    {
        post_order (current_node->left_child);
        post_order (current_node->right_child);
        cout << current_node->data << endl;
    }
}

node *find_min(node *current_node)
{
    if (current_node->left_child!=NULL)
    {
        return find_min(current_node->left_child);
    }
    return current_node;
}

node *find_max(node *current_node)
{
    if (current_node->right_child!=NULL)
    {
        return find_max(current_node->right_child);
    }
    return current_node;
}



int main()
{
    cout << boolalpha; // this prints true/false instead of 1/0
    
    root = insert_value (root, 10);
    insert_value (root, 18);
    insert_value (root, 6);
    insert_value (root, 4);
    insert_value (root, 21);
    insert_value (root, 8);
    insert_value (root, 15);
    insert_value (root, 22);
    insert_value (root, 3);
    insert_value (root, 1);
    insert_value (root, 5);

    //pre_order(root);

    in_order(root);

    //post_order(root);

    //cout << find_min(root)->data << endl;
    //cout << find_max(root)->data << endl;
        
    return 0;
}