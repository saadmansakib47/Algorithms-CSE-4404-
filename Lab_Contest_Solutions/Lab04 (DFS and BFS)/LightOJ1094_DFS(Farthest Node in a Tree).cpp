#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <string.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
bool vis[30005];
long long maxi;
int startNode;

long long explore(int j, long long dis)
{
    int x;
    int w;

    if (dis > maxi)
    {
        maxi = dis;
        startNode = j;
    }

    for (int i = 0; i < graph[j].size(); i++)
    {
        x = graph[j][i].first;
        w = graph[j][i].second;

        if (vis[x] == 0)
        {
            vis[x] = 1;
            explore(x, dis + w);
        }
    }

    return maxi; // Return the maximum distance from the current node
}

int main()
{

    int x;
    int y;
    int w;
    int t;
    int n;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++)
    {
        scanf("%d", &n);

        vector<vector<pair<int, int>>> temp(n + 2);
        swap(temp, graph);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            cin >> y;
            cin >> w;
            graph[x].push_back(make_pair(y, w));
            graph[y].push_back(make_pair(x, w));
        }

        maxi = INT_MIN;
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        explore(0, 0);

        maxi = INT_MIN;
        memset(vis, 0, sizeof(vis));
        vis[startNode] = 1;
        explore(startNode, 0);
        printf("Case %d: %lld\n", cs, maxi);
    }

    return 0;
}
