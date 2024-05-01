#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void si(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
    if (c == '-')
    {
        neg = 1; c = getchar_unlocked();
    }
    for (; c > 47 && c < 58; c = getchar_unlocked())
        { x = (x << 1) + (x << 3) + c - 48; }
    if (neg) x = -x;
}

const int MAXN = 1e3 + 5;
vector<ii> topo;
bool vis[MAXN];
int in_degree[MAXN];
int n;
vector<int> adj[MAXN];

void topoSort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            in_degree[adj[i][j]]++;
        }
    }
    set<ii> S;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            S.insert({i, 1});
            vis[i] = true;
        }
    }
    while (!S.empty()) {
        ii curr = *(S.begin());
        S.erase(S.begin());
        topo.push_back(curr);
        int currValue = curr.first;
        int currLevel = curr.second;
        for (int j = 0; j < adj[currValue].size(); j++)
        {
            if (!vis[adj[currValue][j]])
            {
                in_degree[adj[currValue][j]]--;
                if (in_degree[adj[currValue][j]] == 0)
                {
                    S.insert({adj[currValue][j], currLevel + 1});
                    vis[adj[currValue][j]] = 1;
                }
            }
        }
    }
}

int main()
{
    int kase = 1;
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> n >> m;
        topo.clear();
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            in_degree[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[b].push_back(a);
        }
        topoSort();
        cout << "Scenario #" << kase << ":" << endl;
        vector<ii> final;
        for (int i = 0; i < n; i++) {
            final.push_back({topo[i].second, topo[i].first});
        }
        sort(final.begin(), final.end());
        for (int i = 0; i < topo.size(); i++) cout << final[i].first << " " << final[i].second << endl;
        kase++;
    }
    return 0;
}
