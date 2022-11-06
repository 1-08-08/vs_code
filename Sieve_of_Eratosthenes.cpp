/*
                        SIEVE OF ERATOSTHENES
                      Time Complexity : O(nlogn)
            It is commonly used to generate prime numbers.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> prime, pfac;
vector<vector<int>> factor;

void Prime_upto_N(int N)
{
    vector<bool> temp(N + 1, true);
    temp[0] = temp[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        for (int j = i * i; j <= N; j += i)
            prime[j] = false;
    }
    for (int i = 0; i <= N; i++)
    {
        if (temp[i])
            prime.push_back(i);
    }
}

void Prime_Factor_upto_N(int N)
{
    pfac = vector<int>(N + 1);
    iota(pfac.begin(), pfac.end(), 0);
    for (int i = 2; i <= N; i++)
    {
        if (pfac[i] == i)
        {
            for (int j = i; j <= N; j += i)
                pfac[j] = i;
        }
    }
}

void Factor_upto_N(int N)
{
    factor = vector<vector<int>>(N + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
            factor[j].push_back(i);
    }
}

int main()
{
    return 0;
}