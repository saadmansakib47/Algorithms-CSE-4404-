#include <iostream>
#include <vector>
using namespace std;

vector<int> LookWhoseIndegree0(vector<vector<int>>& graph, vector<int>& indegree)
{
    vector<int> nodes;
    int V = graph.size();
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)
            nodes.push_back(i);
    }
    return nodes;
}


void TopologicalSort(vector<vector<int>>& graph)
{
    int V = graph.size();

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    for (int i = 0; i < V; ++i)
    {
        vector<int> nodes = LookWhoseIndegree0(graph, indegree);
        if (nodes.empty())
        {
            cout << "Graph has a cycle. Topological sort is not possible.\n";
            return;
        }
        for (int node : nodes)
        {
            cout << node << " ";
            for (int j = 0; j < V; ++j)
            {
                if (graph[node][j] == 1)
                    indegree[j]--;
            }
            indegree[node] = -1;
        }
    }
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Topological Sort: ";
    TopologicalSort(graph);

    return 0;
}

