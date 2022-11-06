/*
                                          BELLMAN FORD
                                     Time Complexity : O(nm)
            It is used to find the shortest distance to every vertex from a given vertex ,if negative weights are also present in the graph.
            It is also used to detect negative cycles in a graph.
            If negative cycle is present in a graph, then distance to every vertex is -infinity.
            After x iteration, the distance of every vertex whose shortest path consists of less than or equal to x edges, has been found correctly.
            As shortest distance between any two vertex in a graph consists of atmost n-1 edges. so, if in the nth iteration any relaxation happens, imply negative cycle is present in the graph.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1005;
vector<int> dst(MAXN, LLONG_MAX), par(MAXN);
vector<vector<int>> edges;

void ford(int x, int n)
{

    dst[x] = 0;
    int y;
    for (int i = 0; i < n; i++)
    {
        y = -1;
        for (auto edge : edges)
        {
            if (dst[edge[0]] != LLONG_MAX && dst[edge[1]] > dst[edge[0]] + edge[2])
            {
                y = edge[1];
                dst[edge[1]] = dst[edge[0]] + edge[2];
                par[edge[1]] = edge[0];
            }
        }
    }

    if (y >= 0)
    {
        cout << "Negative Cycle is present in the graph\n";
        for (int i = 0; i < n; i++)
            y = par[y];
        stack<int> st;
        int z = y;
        do
        {
            st.push(z);
            z = par[z];
        } while (z != y);
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
        cout << dst[i] << " ";
    cout << "\n";
}

int32_t main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    ford(1, n);

    return 0;
}