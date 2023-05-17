#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int V=5;
    vector<int> edges[V];

    edges[0].push_back(1);

    edges[0].push_back(2);

    edges[0].push_back(3);

    edges[1].push_back(2);

    for (int i=0; i<V; i++)
    {
        cout<<"Node "<<i<<": ";
        for (int j=0;j<edges[i].size();j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<V; i++)
    {
        cout<<"Out degree of "<<i<<": "<<edges[i].size()<<endl;
    }

    for (int k=0; k<V; k++)
    {
        int counter = 0;
        for (int i=0; i<V; i++)
        {
            for (int j=0;j<edges[i].size();j++)
            {
                if (k == edges[i][j])
                {
                    counter++;
                } 
            }
        }
        cout << "In degree of " << k << ": " << counter << endl;
    }

    return 0;
}