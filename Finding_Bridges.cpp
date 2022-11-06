/*
                                    Finding Bridges in a Graph
                                     Time Complexity : O(n+m)
                   Bridge : The edges in a graph removal of which increases the number
                                   of connected components of the graph.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<bool> vis(MAXN);
vector<pair<int, int>> vec;
vector<int> tin(MAXN), low(MAXN);
vector<vector<int>> adj(MAXN);
int tym = 0;

void dfs_bridge(int ch, int p = -1)
{
    vis[ch] = true;
    low[ch] = tin[ch] = tym++;
    for (auto i : adj[ch])
    {
        if (i == p)
            continue;
        if (vis[i])
        {
            low[ch] = min(low[ch], tin[i]);
            continue;
        }
        dfs_bridge(i, ch);
        low[ch] = min(low[ch], low[i]);
        if (low[i] > tin[ch])
            vec.push_back({i, ch});
    }
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

    dfs_bridge(1);

    return 0;
}