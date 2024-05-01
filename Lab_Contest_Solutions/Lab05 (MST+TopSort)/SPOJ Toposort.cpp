#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void in(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for (; (c < 48 || c > 57); c = getchar_unlocked());
    for (; c > 47 && c < 58; c = getchar_unlocked()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}

vector<int> adj[10001];
int in_degree[10001];
int n, m;
vector<int> path;
set<int> ss;
int cnt = 0;

void bfs_topo()
{
    while (!ss.empty())
    {
        cnt++;
        int u = *ss.begin();
        ss.erase(ss.begin());
        path.push_back(u);
        vector<int> temp;
        for (int i = 0; i < adj[u].size(); i++)
        {
            in_degree[adj[u][i]]--;
            if (!in_degree[adj[u][i]])
                ss.insert(adj[u][i]);
        }
    }
}

int main()
{
    in(n);
    in(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        in(u);
        in(v);
        adj[u].push_back(v);
        in_degree[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!in_degree[i])
            ss.insert(i);
    }
    bfs_topo();
    if (cnt != n) {
        printf("Sandro fails.");
        return 0;
    }
    for (int i = 0; i < path.size(); i++)
        printf("%d ", path[i]);
    return 0;
}

