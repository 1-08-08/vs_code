/*
                                   TARJAN'S ALGORITHM
                                Time Complexity : O(n+m);
                It is used to find strongly connected component in a directed graph.
                It makes SCC in the reverse topological order.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

stack<int> st;
vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN), in_stack(MAXN);
vector<int> id(MAXN), tin(MAXN), low(MAXN);
int tym = 0, ids = 0;

void dfs_tarjan(int x)
{
    vis[x] = true;
    st.push(x);
    in_stack[x] = true;
    tin[x] = low[x] = tym++;
    for (auto i : adj[x])
    {
        if (!vis[i])
        {
            dfs_tarjan(i);
            low[x] = min(low[x], low[i]);
            continue;
        }
        if (in_stack[i])
            low[x] = min(low[x], tin[i]);
    }
    if (low[x] == tin[x])
    {
        ids++;
        while (1)
        {
            int y = st.top();
            st.pop();
            in_stack[y] = false;
            id[y] = ids;
            if (y == x)
                break;
        }
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
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs_tarjan(i);
    }

    // cout << ids << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << id[i] << " ";
    // cout << "\n";

    return 0;
}