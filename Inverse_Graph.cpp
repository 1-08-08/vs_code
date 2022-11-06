#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<set<int>> adj(N);
vector<int> todo(N);
set<int> toremove;

void dfs_Inverse_Graph(int x)
{
    toremove.erase(x);
    auto it = toremove.begin();
    while (it != toremove.end())
    {
        int y = *it;
        if (!adj[x].count(y))
            dfs_Inverse_Graph(y);
        it = toremove.upper_bound(y);
    }
}

void bfs_Inverse_Graph(int x)
{
    queue<int> bfs;
    bfs.push(x);
    toremove.erase(x);
    while (!bfs.empty())
    {
        int x = bfs.front();
        bfs.pop();
        int k = 0;
        for (auto j : toremove)
        {
            if (!adj[x].count(j))
                todo[k++] = j;
        }
        for (int j = 0; j < k; j++)
            toremove.erase(todo[j]), bfs.push(todo[j]);
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
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= n; i++)
        toremove.insert(i);
    while (!toremove.empty())
        dfs_Inverse_Graph(*toremove.begin());
    while (!toremove.empty())
        bfs_Inverse_Graph(*toremove.begin());

    return 0;
}