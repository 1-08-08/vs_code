#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int res[N][N], opt[N][N], arr[N];

void Knuth_Optimisation(int l, int r)
{
    if (res[l][r] != -1)
        return;
    if (r - l < 2)
    {
        res[l][r] = 0;
        opt[l][r] = l;
        return;
    }
    Knuth_Optimisation(l, r - 1);
    Knuth_Optimisation(l + 1, r);
    res[l][r] = 1e9;
    for (int i = opt[l][r - 1]; i <= opt[l + 1][r]; i++)
    {
        if (res[l][r] > res[l][i] + res[i][r] + arr[r] - arr[l])
        {
            res[l][r] = res[l][i] + res[i][r] + arr[r] - arr[l];
            opt[l][r] = i;
        }
    }
}

int main()
{

    return 0;
}