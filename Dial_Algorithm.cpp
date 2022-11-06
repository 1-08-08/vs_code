/*
                             DIAL'S ALGORITHM (1-K bfs)
                             Time Complexity : O(n*k+m)
            This is shortest path algorithm using bfs.
            This algorithm is used when edge weights are very less.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<vector<pair<int, int>>> adj(N);
vector<int> d(N), used(N);

void Dial(int n, int k, int src)
{
    vector<queue<int>> vq(k + 1);
    vq[0].push(src);
    d[src] = 0;
    int pos = 0, num = 1, temp;
    while (num > 0)
    {
        while (vq[pos % (k + 1)].empty())
            pos++;
        temp = vq[pos % (k + 1)].front();
        vq[pos % (k + 1)].pop();
        num--;
        if (used[temp])
            continue;
        used[temp] = 1;
        for (auto i : adj[temp])
        {
            if (d[temp] + i.second < d[i.first])
            {
                d[i.first] = d[temp] + i.second;
                vq[d[i.first] % (k + 1)].push(i.first);
                num++;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << d[i] << " ";
    // cout << "\n";
}

int main()
{
    int n, m, k, src;
    cin >> n >> m >> k >> src;

    for (int i = 1; i <= n; i++)
        d[i] = 100000000, used[i] = 0, adj[i].clear();

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dial(n, k, src);

    return 0;
}