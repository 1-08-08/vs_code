
/*
                               Fenwick Tree
                          Time Complexity : O(logn)
                        Used for range sum and update
                    Used to find inversions in an array in O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> fw(MAXN);

void update(int idx, int val, int n)
{
    for (; idx <= n; idx += idx & -idx)
        fw[idx] += val;
}

int query(int idx)
{
    int ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret += fw[idx];
    return ret;
}

int count_inversion(vector<int> &v)
{
    int n = (int)v.size(), x = 0, prev = -1e9 - 5;
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    map<int, int> p;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > prev)
            x++;
        prev = temp[i], p[prev] = x;
    }
    int ret = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        update(p[v[i]], 1, n);
        ret += query(p[v[i]] - 1);
    }
    return ret;
}

int main()
{

    return 0;
}