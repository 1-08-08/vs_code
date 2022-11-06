/*
                                  FLOYD WARSHALL
                            Time Complexity : O(n^3)
                It is used to find the shortest distance between every pair
                    of vertex.
                It can also be used to detect negative cycles in graphs.
                If negative cycle is present in a graph, then distance of
                    some vertex from itself must be negative.
                After x iteration, the shortest distance of every pair of vertex
                    whose shortest path consists of 0 to x-1 vertices has been
                    found correctly.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 105;
vector<vector<int>> dp(MAXN, vector<int>(MAXN, INT_MAX));

void floyd(int n)
{

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    // check negative cycle
    for (int i = 0; i < n; i++)
    {
        if (dp[i][i] < 0)
        {
            cout << "Negative cycle is present\n";
            break;
        }
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = w;
    }

    floyd(n);

    return 0;
}