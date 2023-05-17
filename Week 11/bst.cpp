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

node *search_node(node* current_node, int value)
{
    if (current_node==NULL)
    {
        return current_node;
    }
    if (current_node->data == value)
    {
        return current_node;
    }
    else if(current_node->data > value)
    {
        return search_node(current_node->left_child, value);
    }
    else
    {
        return search_node(current_node->right_child, value);
    }
}

void replace_node(node *old_node, node *new_node)
{
    if (old_node->parent == NULL)
    {
        root = new_node;
    }
    else
    {
        if (old_node->data > old_node->parent->data)
        {
            old_node->parent->right_child = new_node;
            //new_node->parent = old_node->parent;
        }
        else
        {
            old_node->parent->left_child = new_node;
            //new_node->parent = old_node->parent;
        }
    }
    if (new_node!=NULL)
    {
        new_node->parent = old_node->parent;
    }
}

void delete_value(int value)
{
    node *node_to_delete = search_node(root, value);
    if (node_to_delete==NULL)
    {
        return;
    }
    else
    {
        if (node_to_delete->left_child == NULL)
        {
            replace_node(node_to_delete, node_to_delete->right_child);
        }
        else if (node_to_delete->left_child == NULL)
        {
            replace_node(node_to_delete, node_to_delete->left_child);
        }
        else
        {
            node *min_node = find_min(node_to_delete->right_child);
            if (min_node==node_to_delete->right_child)
            {
                replace_node(node_to_delete, node_to_delete->right_child);
                min_node ->left_child =node_to_delete->left_child;
                min_node->left_child->parent = min_node;
            }
            else
            {
                replace_node(node_to_delete, min_node);
                min_node->left_child = node_to_delete->left_child;
                min_node->left_child->parent = min_node;
                min_node->right_child = node_to_delete->right_child;
                min_node->right_child->parent =min_node;
            }
        }
        delete node_to_delete;
    }
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

    delete_value (15);

    in_order(root);
        
    return 0;
}