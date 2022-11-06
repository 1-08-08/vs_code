/*
                            Strongly Connected Component / Condensed graph
                                    Time Complexity : O(n+m)
            In a strongly Connected Component, every node is reachable from every other node.
                In a Condensed graph, any single node from each SCC represent whole SCC.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<bool> vis;
vector<int> order, root(MAXN);
vector<vector<int>> adj1(MAXN), adj2(MAXN), adj(MAXN);

void dfs1(int x)
{
    vis[x] = true;
    for (auto i : adj1[x])
    {
        if (!vis[i])
            dfs1(i);
    }
    order.push_back(x);
}

void dfs2(int x, int y)
{
    root[x] = y;
    vis[x] = true;
    for (auto i : adj2[x])
    {
        if (!vis[i])
            dfs2(i, y);
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }

    vis.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for (auto i : order)
    {
        if (!vis[i])
            dfs2(i, i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj1[i])
        {
            if (root[i] != root[j])
                adj[root[i]].push_back(root[j]);
        }
    }

    return 0;
}