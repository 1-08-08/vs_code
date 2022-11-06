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

stack<int> st;
vector<bool> vis(MAXN);
vector<int> id(MAXN), res(MAXN);
vector<vector<int>> adj1(MAXN), adj2(MAXN);

void dfs1(int x)
{
    vis[x] = true;
    for (auto i : adj1[x])
    {
        if (!vis[i])
            dfs1(i);
    }
    st.push(x);
}

void dfs2(int x, int y)
{
    id[x] = y;
    vis[x] = true;
    for (auto i : adj2[x])
    {
        if (!vis[i])
            dfs2(i, y);
    }
}

void SCC()
{

    for (int i = 1; i < N; i++)
    {
        if (!vis[i])
            dfs1(i);
    }

    int ids = 0;
    vis.assign(MAXN, false);
    while (!st.empty())
    {
        if (vis[st.top()])
            st.pop();
        else
            dfs2(st.top(), ids++);
    }
}

void Xtrue(int x)
{
    // (x∨x)
    adj1[x + N].push_back(x);
    adj2[x].push_back(x + N);
}

void XorY(int x, int y)
{
    // (x∨y)
    adj1[x + N].push_back(y);
    adj1[y + N].push_back(x);
    adj2[y].push_back(x + N);
    adj2[x].push_back(y + N);
}

void XYdifferent(int x, int y)
{
    // (x∨y)∧(¬x∨¬y)
    adj1[x + N].push_back(y);
    adj1[y + N].push_back(x);
    adj1[x].push_back(y + N);
    adj1[y].push_back(x + N);
    adj2[y].push_back(x + N);
    adj2[x].push_back(y + N);
    adj2[y + N].push_back(x);
    adj2[x + N].push_back(y);
}

void XYsame(int x, int y)
{
    // (¬x∨y)∧(x∨¬y)
    adj1[x].push_back(y);
    adj1[y + N].push_back(x + N);
    adj1[x + N].push_back(y + N);
    adj1[y].push_back(x);
    adj2[y].push_back(x);
    adj2[x + N].push_back(y + N);
    adj2[y + N].push_back(x + N);
    adj2[x].push_back(y);
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
        res[i] = (id[i] > id[i + N]);
    }

    if (!flag)
        cout << "IMPOSSIBLE\n";
    else
        cout << "POSSIBLE\n";

    return 0;
}