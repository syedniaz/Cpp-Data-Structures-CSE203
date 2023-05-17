#include<iostream>
#include <list>

using namespace std;

int main()
{
    cout << boolalpha; // this prints true/false instead of 1/0
    
    list <int> my_list {12, 5, 10, 9};

    my_list.push_front(4);
    //cout << my_list.size() << endl;
    //cout << my_list.front() << endl;
    //cout << my_list.back() << endl;
    

    for (int i : my_list)
    {
        //cout << i << endl;
    }

    cout << *my_list.begin() << endl;
    cout << *my_list.end() << endl;

    return 0;
}