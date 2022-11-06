/*
                            SPARSE TABLE
                    Time Complexity :
                        O(nlogn) for preprocessing
                        O(logn) / O(1) for query
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int LOG = 21;
vector<vector<int>> table(LOG, vector<int>(N)), min_ind(LOG, vector<int>(N)), max_ind(LOG, vector<int>(N));
vector<int> V(N), pow2(LOG + 1);

void Build_Table_Min(int n)
{
    pow2[0] = 1;
    for (int i = 1; i <= LOG; i++)
        pow2[i] = (pow2[i - 1] << 1);

    int p = upper_bound(pow2.begin(), pow2.end(), n) - pow2.begin(), l, r;
    for (int i = 0; i < n; i++)
        table[0][i] = V[i], min_ind[0][i] = i;

    for (int i = 1; i < p; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            l = table[i - 1][j], r = table[i - 1][j + (1 << (i - 1))];
            table[i][j] = min(l, r);
            if (l <= r)
                min_ind[i][j] = min_ind[i - 1][j];
            else
                min_ind[i][j] = min_ind[i - 1][j + (1 << (i - 1))];
        }
    }
}

int query_min(int l, int r)
{
    int k = (r - l + 1);
    k = upper_bound(pow2.begin(), pow2.end(), k) - pow2.begin() - 1;
    return min(table[k][l], table[k][r - (1 << k) + 1]);
}

void Build_Table_Max(int n)
{
    pow2[0] = 1;
    for (int i = 1; i <= LOG; i++)
        pow2[i] = (pow2[i - 1] << 1);

    int p = upper_bound(pow2.begin(), pow2.end(), n) - pow2.begin(), l, r;
    for (int i = 0; i < n; i++)
        table[0][i] = V[i], max_ind[0][i] = i;

    for (int i = 1; i < p; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            l = table[i - 1][j], r = table[i - 1][j + (1 << (i - 1))];
            table[i][j] = max(l, r);
            if (l >= r)
                max_ind[i][j] = max_ind[i - 1][j];
            else
                max_ind[i][j] = max_ind[i - 1][j + (1 << (i - 1))];
        }
    }
}

int query_max(int l, int r)
{
    int k = (r - l + 1);
    k = upper_bound(pow2.begin(), pow2.end(), k) - pow2.begin() - 1;
    return max(table[k][l], table[k][r - (1 << k) + 1]);
}

void Build_Table_gcd(int n)
{
    pow2[0] = 1;
    for (int i = 1; i <= LOG; i++)
        pow2[i] = (pow2[i - 1] << 1);

    int p = upper_bound(pow2.begin(), pow2.end(), n) - pow2.begin(), l, r;
    for (int i = 0; i < n; i++)
        table[0][i] = V[i];

    for (int i = 1; i < p; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            l = table[i - 1][j], r = table[i - 1][j + (1 << (i - 1))];
            table[i][j] = __gcd(l, r);
        }
    }
}

int query_gcd(int l, int r)
{
    int k = (r - l + 1);
    k = upper_bound(pow2.begin(), pow2.end(), k) - pow2.begin() - 1;
    return __gcd(table[k][l], table[k][r - (1 << k) + 1]);
}

int main()
{

    return 0;
}