/* 
                 BINARY LIFTING
            Time Complexity : Preprocessing - O(NlogN)
                               Query - O(logN)
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 100005, LOGN = 20;
vector<vector<int>> adj;
int up[N][LOGN], lev[N];

void dfs_preprocessing(int ch, int p)
{
    up[ch][0] = p, lev[ch] = 1 + lev[p];
    for (int i = 1; i < LOGN; i++)
        up[ch][i] = up[up[ch][i - 1]][i - 1];
    for (auto i : adj[ch])
    {
        if (i != p)
            dfs_preprocessing(i, ch);
    }
}

int getKthancestor(int x, int k)
{
    for (int i = LOGN - 1; i >= 0; i--)
    {
        if (k & (1 << i))
            x = up[x][i];
    }
    return x;
}

int LCA(int u, int v)
{
    if (lev[u] < lev[v])
        swap(u, v);
    u = getKthancestor(u, lev[u] - lev[v]);
    if (u == v)
        return u;
    for (int i = LOGN - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

int main()
{
    int n;
    cin >> n;
    cout<<n<<"\n";
    // for (int i = 1; i < n; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // lev[0] = 0;
    // memset(up, 0, sizeof(up));
    // dfs_preprocessing(1, 0);
    return 0;
}