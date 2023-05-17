#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int V=5;
    vector<int> edges[V];

    edges[0].push_back(1);
    edges[1].push_back(0);

    edges[0].push_back(2);
    edges[2].push_back(0);

    edges[0].push_back(3);
    edges[3].push_back(0);

    edges[1].push_back(2);
    edges[2].push_back(1);

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
        cout<<"Degree of "<<i<<": "<<edges[i].size()<<endl;
    }
}