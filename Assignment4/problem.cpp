#include<iostream>

using namespace std;

int main()
{
    cout << boolalpha;

    const int nodes = 8;
    int edges [nodes][nodes] {0};

    edges [0][1] = 1;
    edges [0][5] = 1;

    edges [1][2] = 1;

    edges [2][3] = 1;

    edges [4][2] = 1;
    edges [4][3] = 1;
    edges [4][5] = 1;

    edges [5][1] = 1;

    edges [6][5] = 1;
    edges [6][1] = 1;
    edges [6][0] = 1;
    edges [6][7] = 1;

    edges [7][0] = 1;

    cout << "Graph represented as Adjacency Matrix: " << endl;

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int outdegree[nodes] {0};

    for (int i = 0; i < nodes; i++)
    {
        int counter = 0;
        for (int j = 0; j < nodes; j++)
        {
            if (edges[i][j] == 1)
            {
                counter++;
            }
        }
        outdegree[i] = counter;
    }

    /*for (int i = 0; i < nodes; i++)
    {
        cout << "Out degree of "<< i <<": "<< outdegree[i] << endl;
    }*/

    for (int i = 0; i < nodes; i++)
    {
        if (outdegree[i] == 0)
        {
            cout << "Node " << i << " is a sink node" << endl;
        }
    }

    int max = outdegree[0];
    int nodemax = 0;

    for (int i = 0; i < nodes; i++)
    {
        if (outdegree[i] > max)
        {
            max = outdegree[i];
            nodemax = i;
        }
    }

    cout << "Node " << nodemax << " has the highest outdegree which is " << max << endl;

    return 0;
}