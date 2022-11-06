#include <bits/stdc++.h>
using namespace std;
#define int long long

void KMP(string pat, string s)
{
    int n = (int)pat.size(), m = (int)s.size();
    vector<int> pre(n);
    for (int i = 1, j; i < n; i++)
    {
        j = pre[i - 1];
        while (j > 0 && pat[j] != pat[i])
            j = pre[j - 1];
        if (pat[i] == pat[j])
            pre[i] = j + 1;
    }

    int cnt = 0, i = 0, j = 0;
    while (i < (int)s.length())
    {
        if (s[i] == pat[j])
        {
            i++, j++;
            if (j == n)
            {
                j = pre[j - 1];
                cnt++;
            }
            continue;
        }
        if (j == 0)
            i++;
        else
            j = pre[j - 1];
    }
    // cout << cnt << "\n";
}

int32_t main()
{
    string pat, s;
    cin >> pat >> s;

    KMP(pat, s);

    return 0;
}