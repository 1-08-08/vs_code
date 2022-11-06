/*
                                 Prim's Algorithm
                             Time Complexity : O(mlogn)
        Spanning Tree : Tree formed from a graph after removing some of the edges.
        Minimum Spanning Tree : Spanning tree whose sum/product of edge weights is minimum.
        Maximum Spanning Tree : Spanning tree whose sum/product of edge weights is maximum.
    To obtain maximum spanning tree, multiply all the edge weights with -1 and apply any mst algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<bool> Inmst(MAXN);
vector<int> dst(MAXN, INT_MAX), parent(MAXN);
vector<vector<pair<int, int>>> adj(MAXN);

void prims()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dst[1] = 0, parent[1] = 0;
    int ret = 0;
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if (Inmst[temp.second])
            continue;
        Inmst[temp.second] = true;
        ret += temp.first;
        for (auto i : adj[temp.second])
        {
            if (!Inmst[i.first] && dst[i.first] > i.second)
            {
                dst[i.first] = i.second;
                parent[i.first] = temp.second;
                pq.push({i.second, i.first});
            }
        }
    }
    // cout<<ret<<"\n";
}

int main()
{
    int n, m;
    cin >> m >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims();

    return 0;
}