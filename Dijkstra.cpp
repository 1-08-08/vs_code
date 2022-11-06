/*
                                        DJIKSTRA ALGORITHM
                                    Time Complexity : O(mlogn)
                  Used to find the shortest path of every vertex from a given vertex.
                            weight of every edge should be non-negative.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> par(MAXN), dst(MAXN, INT_MAX);
vector<vector<pair<int, int>>> adj(MAXN);

void dijkstra(int ch)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dst[ch] = 0, par[ch] = 0;
    pq.push({0, ch});
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if (temp.first > dst[temp.second])
            continue;
        for (auto i : adj[temp.second])
        {
            if (temp.first + i.second < dst[i.first])
            {
                dst[i.first] = i.second + temp.first;
                par[i.first] = temp.second;
                pq.push({dst[i.first], i.first});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
        cout << dst[i] << " ";
    cout << "\n";

    return 0;
}