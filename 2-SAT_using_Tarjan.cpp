/*
                                    2-SAT
                          (x∨y)⟺((¬x⇒y)∧(¬y⇒x))
            when there are n variables and each variable can be assign only one
                value out of two values, given m clauses.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100001;
const int MAXN = 200005;

vector<int> id(MAXN), res(MAXN), tin(MAXN), low(MAXN);
vector<bool> vis(MAXN), in_stack(MAXN);
vector<vector<int>> adj(MAXN);
int tym = 0, ids = 0;
stack<int> st;

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

void SCC()
{
    for (int i = 1; i < N; i++)
    {
        if (!vis[i])
            dfs_tarjan(i);
    }
}

void Xtrue(int x)
{
    // (x∨x)
    adj[x + N].push_back(x);
}

void XorY(int x, int y)
{
    // (x∨y)
    adj[x + N].push_back(y);
    adj[y + N].push_back(x);
}

void XYdifferent(int x, int y)
{
    // (x∨y)∧(¬x∨¬y)
    adj[x + N].push_back(y);
    adj[y + N].push_back(x);
    adj[x].push_back(y + N);
    adj[y].push_back(x + N);
}

void XYsame(int x, int y)
{
    // (¬x∨y)∧(x∨¬y)
    adj[x].push_back(y);
    adj[y + N].push_back(x + N);
    adj[x + N].push_back(y + N);
    adj[y].push_back(x);
}

int32_t main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;

    // x must be true.
    Xtrue(x);

    // Atleast one variable must be true.
    XorY(x, y);

    // Both variable have different value.
    XYdifferent(x, y);

    // Both variable have same value.
    XYsame(x, y);

    SCC();

    bool flag = true;
    for (int i = 1; i < N; i++)
    {
        if (id[i] == id[i + N])
        {
            flag = false;
            break;
        }
        res[i] = (id[i] < id[i + N]);
    }

    if (!flag)
        cout << "IMPOSSIBLE\n";
    else
        cout << "POSSIBLE\n";

    return 0;
}