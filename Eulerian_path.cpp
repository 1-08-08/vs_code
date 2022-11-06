/*
                                 Eulerian Path
    An Eulerian path is a path in a graph that passes through all of its edges exactly once.
               An Eulerian cycle/Circuit is Eulerian path that is a cycle.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<bool> vis(MAXN);
vector<int> deg(MAXN), indeg(MAXN), outdeg(MAXN), res;
vector<vector<int>> adj(MAXN);

void dfs(int x, vector<vector<int>> &vec)
{
    vis[x] = true;
    for (auto i : adj[x])
    {
        if (!vis[i])
            dfs(i, vec);
    }
}

/*
                      Eulerian Cycle in an Undirected Graph
    Eulerian Cycle exists if
        1. All non-isolated vertex are connected.
        2. All the vertex have even degree.
*/

void Eulerian_Cycle_Undirected(int n)
{
    dfs(1, adj);
    for (int i = 1; i <= n; i++)
    {
        if ((!vis[i] && !adj[i].empty()) || (deg[i] % 2))
        {
            cout << "-1\n";
            return;
        }
    }
    int x = 1, y;
    stack<int> st;
    st.push(x);
    map<pair<int, int>, bool> p;
    while (!st.empty())
    {
        while (!adj[x].empty() && p[{x, adj[x].back()}])
            adj[x].pop_back();
        if (adj[x].empty())
        {
            res.push_back(x);
            x = st.top();
            st.pop();
        }
        else
        {
            st.push(x);
            y = adj[x].back();
            adj[x].pop_back();
            p[{y, x}] = true;
            x = y;
        }
    }
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
}

/*
                      Eulerian Path in an Undirected Graph
    Eulerian Path exists if
        1. All non-isolated vertex are connected.
        2. Number of vertex having odd degree is atmost two.
    if there is a vertex with odd degree, start the eulerian path from that vertex.
*/

void Eulerian_Path_Undirected(int n)
{
    dfs(1, adj);
    int x = 1, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] % 2)
            x = i, y++;
        if ((!vis[i] && !adj[i].empty()) || (y > 2))
        {
            cout << "-1\n";
            return;
        }
    }
    stack<int> st;
    st.push(x);
    map<pair<int, int>, bool> p;
    while (!st.empty())
    {
        while (!adj[x].empty() && p[{x, adj[x].back()}])
            adj[x].pop_back();
        if (adj[x].empty())
        {
            res.push_back(x);
            x = st.top();
            st.pop();
        }
        else
        {
            st.push(x);
            y = adj[x].back();
            adj[x].pop_back();
            p[{y, x}] = true;
            x = y;
        }
    }
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
}

/*
                      Eulerian Cycle in a Directed Graph
    Eulerian Cycle exists if
      1. All non-isolated vertex are strongly connected(there exist a path between any two vertex).
      2. Indegree is equal to Outdegree for every vertex.
*/

void Eulerian_Cycle_Directed(int n)
{
    dfs(1, adj);
    for (int i = 1; i <= n; i++)
    {
        if ((!vis[i] && !adj[i].empty()) || (indeg[i] != outdeg[i]))
        {
            cout << "-1\n";
            return;
        }
    }
    vector<vector<int>> adj1;
    vis = vector<bool>(MAXN, false);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
            adj1[j].push_back(i);
    }
    dfs(1, adj1);
    for (int i = 1; i <= n; i++)
    {
        if ((!vis[i] && !adj1[i].empty()) || (indeg[i] != outdeg[i]))
        {
            cout << "-1\n";
            return;
        }
    }
    int x = 1, y;
    stack<int> st;
    st.push(x);
    while (!st.empty())
    {
        if (adj[x].empty())
        {
            res.push_back(x);
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
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
}

/*
                      Eulerian Path in a Directed Graph
    Eulerian Path exists if
      1. All non-isolated vertex are connected(all the edges are assumed to be undirected).
      2. Indegree is equal to Outdegree for every vertex.
                       OR
         There exists one vertex with Outdegree = Indegree+1 and one vertex with Indegree = Outdegree+1 and rest of the vertex have indegree equal to Outdegree.
    if there is a vertex with Outdegree = indegree+1, the start eulerian path with that vertex.
*/

void Eulerian_Path_Directed(int n)
{
    int x = 1, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (outdeg[i] == indeg[i] + 1)
            y++, x = i;
    }
    if (y > 1)
    {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> adj1;
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
            adj1[i].push_back(j), adj1[j].push_back(i);
    }
    dfs(1, adj1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && !adj1[i].empty())
        {
            cout << "-1\n";
            return;
        }
    }
    stack<int> st;
    st.push(x);
    while (!st.empty())
    {
        if (adj[x].empty())
        {
            res.push_back(x);
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
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
}

int main()
{

    return 0;
}