/*
                                    Diameter Of Tree
                                Time Complexity : O(n+m)
                      Start bfs from any vertex and find the farthest vertex(X) from it. X
                      is one of the endpoint of diameter of tree. Again start the bfs from
                      X and find the farthest vertex(Y) from it. The distance between X and
                      Y is the diameter of tree.

*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<bool> vis;
vector<vector<int>> adj(MAXN);

pair<int, int> bfs_diameter(int x)
{
    vis.assign(MAXN, false);
    vis[x] = true;
    queue<pair<int, int>> q;
    q.push({0, x});
    pair<int, int> ret = {-1, -1};
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        ret = max(ret, temp);
        for (auto i : adj[temp.second])
        {
            if (!vis[i])
                vis[i] = true, q.push({temp.first + 1, i});
        }
    }
    return ret;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto res = bfs_diameter(1);
    res = bfs_diameter(res.second);
    cout << res.first << "\n";

    return 0;
}