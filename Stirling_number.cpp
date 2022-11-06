/*
                                Stirling Number
        1.  Stirling number of first kind.
                s(n,k) is the number of permutation of n elements with k disjoint cycles.
                s(n,k) = s(n-1,k-1) + (n-1)*s(n-1,k)
        2.  Stirling number of second kind.
                S(n,k) is the number of ways to partition a set of n elements into k non-empty subset.
                S(n,k) = S(n-1,k-1) + k*S(n-1,k)
        3.  Bell number
                Total number of partition of a set with n elements.
                B(n) is the summation of S(n,k) for all 0 <= k <= n.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1005;
const int mod = 1000000007;

vector<int> B(MAXN);
vector<vector<int>> S(MAXN, vector<int>(MAXN)), s(MAXN, vector<int>(MAXN));

void Stirling_number_first()
{
    s[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + (i - 1) * s[i - 1][j] % mod) % mod;
    }
}

void Stirling_number_second()
{
    S[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 1; j <= i; j++)
            S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j] % mod) % mod;
    }
}

void Bell_number()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j <= i; j++)
            B[i] = (B[i] + S[i][j]) % mod;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Stirling_number_first();
    // Stirling_number_second();
    // Bell_number();

    return 0;
}