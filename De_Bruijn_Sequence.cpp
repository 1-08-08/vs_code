#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
const int mod = 1000000007;

vector<vector<int>> adj(MAXN);

string De_Bruijn(int x, int n)
{
    // eulerian circuit
    stack<int> st;
    st.push(x);
    int y;
    vector<int> v;
    while (!st.empty())
    {
        if (adj[x].empty())
        {
            v.push_back(x);
            x = st.top();
            st.pop();
        }
        else
        {
            st.push(x);
            y = adj[x].back();
            adj[x].pop_back();
            x = y;
        }
    }
    reverse(v.begin(), v.end());
    // create string based on eulerian circuit.
    string res(n - 1, '0');
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] & 1)
            res.push_back('1');
        else
            res.push_back('0');
    }
    return res;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    // make the nodes for every possible different n-1 length substring.
    // edges corresponds to removing first character from nodes and adding all the posssible k characters at end.
    for (int i = 0; i < (1 << (n - 1)); i++)
    {
        if (i == 0)
        {
            adj[0].push_back(0);
            adj[0].push_back(1);
            continue;
        }
        int x = i;
        if (x & (1 << (n - 2)))
            x ^= (1 << (n - 2));
        adj[i].push_back((x << 1));
        adj[i].push_back((x << 1) + 1);
    }

    string res = De_Bruijn(0, n);
    cout << res << "\n";

    return 0;
}