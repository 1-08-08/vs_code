/*
                                MILLER RABIN PRIMALITY TEST
                                 Time Complexity : O(KlogN)
                            Exploit the fact (a^(p-1))%p = 1.
                       for 32 bit integer ,base array = {2,3,5,7},  K = 4
              for 64 bit integer ,base array = {2,3,5,7,11,13,17,19,23,29,31,37},  K = 12
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int exp(int a, int b, int mod)
{
    a %= mod;
    int res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * a) % mod;
        a = (__uint128_t)a * a % mod;
        b >>= 1;
    }
    return res;
}

bool check_composite(int n, int b, int d, int s)
{
    int x = exp(b, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int i = 1; i < s; i++)
    {
        x = (__uint128_t)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool is_prime(int n)
{
    if (n == 1)
        return false;
    int s = 0, d = n - 1;
    while ((d % 2) == 0)
        s++, d >>= 1;
    for (auto base : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == base)
            return true;
        if (check_composite(n, base, d, s))
            return false;
    }
    return true;
}

int32_t main()
{
    int n;
    cin >> n;

    is_prime(n);

    return 0;
}