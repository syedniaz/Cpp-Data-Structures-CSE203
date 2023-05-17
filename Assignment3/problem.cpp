#include<iostream>

using namespace std;

struct Customer
{
    string name;
    double income;
    Customer *next;
    Customer *prev;
};
// creating the struct class for the doubly linked list. 
//it has two data types(to store name and income) and two pointers(next to store next Customer and prev to store previous Customer)

Customer *head = NULL;
Customer *tail = NULL;
//creating head and tail of the list and initializing them to NULL

bool isempty ()
{
    if (head == NULL) return true;
    else return false;
}
/*writing this function to check if list is empty,
not required in question but this will be helpful for us to write other functions.
If the head is empty(ie NULL) then list must be empty so the function returns true.
if head is not empty, there must be at least one element in the list, so then the function will return false.
*/

void insert_customer(string new_name, double new_income)
{
    Customer *new_Customer = new Customer;
    new_Customer->name = new_name;
    new_Customer->income = new_income;
    new_Customer->next = NULL;
    new_Customer->prev = NULL;

    if (isempty() == true)
    {
        head = new_Customer;
        tail = new_Customer;
    }
    else
    {
        tail->next = new_Customer;
        new_Customer->prev = tail;
        tail = new_Customer;
    }
}
/*writing this function to insert a new customer (new node) to the list.
at first I create the new node (customer) dynamically with new function.
then I insert the name and income to the new_Customer.
then I initialise the next and prev pointers of this new_Customer to NULL.
then I check if the list is empty with the isempty() function written earlier.
if it is then I declare both head and tail as the new_Customer as it is both first and last customer(node) right now.
if the list is not empty, then I use tail to insert.
so I will store new_Customer in the tail of next as I will insert this new_Customer after this current tail as I want to insert it at end of list.
then I will store tail in prev of new_Customer as this current tail will be behind this new_Customer now.
then I assign the tail to new_Customer as this is our new last customer(node) entered, so it will be our new tail.
*/

void print_list()
{
    Customer* current_Customer = head;
    while (current_Customer != NULL)
    {
        cout << current_Customer->name << ", " << current_Customer->income <<endl;
        current_Customer = current_Customer->next;
    }
}
/*
writing this function to print the doubly linked list
not required but helped for checking if insert function is working correctly and link is okay.
at first I declare a temporary current Customer(node) and store the contents from head in it
then I go into a while loop where I first print the required info.
then the current Customer is updated with the contents of next of current Customer, current_Customer = current_Customer->next;
so basically I increment the Customer in order to traverse the list of Customers(nodes).
this run loops till the current_Customer becomes NULL,
which is basically at the end of the list because next of last Customer(node) contains NULL.
*/

double count_customers()
{
    double count = 0.0;
    Customer *current_Customer = head;
    while (current_Customer != NULL)
    {
        count++;
        current_Customer = current_Customer->next;
    }
    return count;
}
/*
writing this function to count the number of customers(nodes) in the list.
not required but will help for sort_customer function and calculating avg_income.

we declare this function as double not as void or int as I want to return the number 
and using double(not int) because since we'll use it for calculating average, which can be a value that has decimal points.
so this prevents any chance of data loss.

then I declare a temporary current Customer(node) and store the contents from head in it
then I go into a while loop where I first increment the counter if current Customer is not NULL.
then the current Customer is updated with the contents of next of current Customer, current_Customer = current_Customer->next;
so basically I increment the Customer in order to traverse the list of Customers.
Also incrementing count each time the loop is run.
this run loops till the current Customer becomes NULL,
which is basically at the end of the list because next of last Customer(node) contains NULL.
then finally I return count which has the value of number of customers(nodes).
*/

void sort_customer()
{
    int l = count_customers();
    string str [l];
    int i = 0;
    Customer *current_Customer = head;

    while (current_Customer != NULL)
    {
        str[i] = current_Customer->name;
        current_Customer = current_Customer->next;
        i++;
    }

    for (int j = 0; j < l; j++)
    {
        for (int k = j+1; k < l; k++)
        {
            if (str[j] > str[k])
            {
                string temp = str[j];
                str[j] = str[k];
                str[k] = temp;
            }
        }
    }

    for (int j = 0; j < l; j++) cout << str[j] << endl;
}
/*
so the purpose of this function is to alphabetically sort just the names of the customers in the list 
without actually making changes to the list.

at first I declare a int variable l to store the number of customers(nodes) in the list using
the count_customer function I wrote earlier. No need for double variable as we will not be dividing anything, so no chance of data loss.
Then I declare an array of string type of size l, l being number of customers(nodes) in the list.
then I declare a temporary current Customer and store the contents from head in it. 
Also declare an index variable, int i and set it to zero.
then I go into a while loop where I first add the name from head customer(nodes) to the array,
also incrementing i and current Customer. I increment current Customer by using current_Customer = current_Customer->next;.
so basically I increment the Customer in order to traverse the list of Customers and increment i to traverse the array of strings(str[i])
this loops run till it reaches the end of the list, which is basically at the end of the list because next of last Customer contains NULL.
so all the names in list are added to this array of string, str.

then we do the alphabetical sort in a nested loop. we compare the two entries in array of string, 
if the first index in array is greater than the next index of the array ( str[j] > str[k], which basically compares the characters for so Z<A and A>B ),
then we switch the elements of the arrays by using a temporary variable.
We run this loop till all the elements of arrays of strings sorted, which is till the end of its size or length of array, which was stored in l.

once the sort is done, then we just print the array of strings using a single for loop. 
we declare a int variable and use it as an index to print using cout.
for (int j = 0; j < l; j++) cout << str[j] << endl;
the above line will print the array of strings. we use this after sorting so it prints the sorted(alphabetically) array.
*/

void show_last_customer()
{
    cout << tail->name << ", " << tail->income <<endl;
}
/*
this functions is written to print the last customer's name and income.
since it is doubly linked list, I can just use the tail to print the last customer's info
because tail stores the information of the last Customer in the linked list.
so I use tail->name and tail->income in cout to print the info.
*/

void calculate_avg_income()
{
    double avg_income = 0.0;
    Customer *current_Customer = head;
    while (current_Customer != NULL)
    {
        avg_income += current_Customer->income;
        current_Customer = current_Customer->next;
    }
    avg_income /= count_customers();
    cout << avg_income << endl;
}
/*
this function calculates the average income of the customers.
at first I declare a variable name avg_income and declare its value to zero.
Then I declare a temporary customer (node) current_Customer and store the contents from head in it
then I go into a while loop where I first add the income of first customer to avg_income.
then the current Customer is updated with the contents of next of current Customer, current_Customer = current_Customer->next;
so basically I increment the Customer in order to traverse the list of Customers.
Also incrementing count each time the loop is run
this run loops till the current Customer becomes NULL,
which is basically at the end of the list because next of last Customer contains NULL.
then I'll have the sum of income in avg_income.
to find average, I divide avg_income by count_customers(), the function which I wrote which counts the number of customers(nodes).
then I finally have average in avg_income, which I print using cout.
*/


int main()
{
    cout << boolalpha; // this prints true/false instead of 1/0

    insert_customer ("Rafi", 1200);
    insert_customer ("Kohon", 1500);
    insert_customer ("Jawad", 1000);
    insert_customer ("Noel", 1300);

    //print_list();

    sort_customer();

    show_last_customer();

    calculate_avg_income();

    //print_list();

    return 0;
}
