/*
                        ARTICULATION POINT
                    Time Complexity : O(n+m)
        Articulation Point : The vertex which when removed along with all its edges from the graph, increases the number of connected component of graph.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<bool> vis(MAXN), ap(MAXN);
vector<int> tin(MAXN), low(MAXN);
vector<vector<int>> adj(MAXN);
int tym = 0;

void dfs(int u, int p = -1)
{
    vis[u] = true;
    low[u] = tin[u] = tym++;
    int child = 0;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        if (vis[v])
        {
            low[u] = min(low[u], tin[v]);
            continue;
        }
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= tin[u] && p != -1)
            ap[u] = true;
        child++;
    }
    if (p == -1 && child > 1)
        ap[u] = true;
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (ap[i])
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}