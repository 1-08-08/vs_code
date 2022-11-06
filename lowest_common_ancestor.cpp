/*
								Lowest Common Ancestor
							Time Complexity : O(nlogn) for preprocessing
											:  O(1) for LCA
							Eulerian tour and sparse table is used.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005, LOGN = 20;
vector<int> lev(MAXN), fst(MAXN), tour(4 * MAXN);
vector<vector<int>> adj(MAXN), table(LOGN, vector<int>(4 * MAXN)), iter(LOGN, vector<int>(4 * MAXN));
int idx_tour = 0;

void dfs_tour(int ch, int p)
{
	lev[ch] = lev[p] + 1;
	fst[ch] = idx_tour;
	tour[idx_tour++] = ch;
	for (auto i : adj[ch])
	{
		if (i != p)
			dfs_tour(i, ch);
		tour[idx_tour++] = ch;
	}
}

void buildTable()
{
	for (int i = 0; i < idx_tour; i++)
		table[0][i] = lev[tour[i]], iter[0][i] = tour[i];
	for (int i = 1; i < LOGN; i++)
	{
		for (int j = 0; j + (1 << i) <= idx_tour; j++)
		{
			table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			if (table[i - 1][j] <= table[i - 1][j + (1 << (i - 1))])
				iter[i][j] = iter[i - 1][j];
			else
				iter[i][j] = iter[i - 1][j + (1 << (i - 1))];
		}
	}
}

int LCA(int u, int v)
{
	int l = min(fst[u], fst[v]), r = max(fst[u], fst[v]), x;
	x = log2(r - l + 1);
	if (table[x][l] <= table[x][r - (1 << x) + 1])
		return iter[x][l];
	return iter[x][r - (1 << x) + 1];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	return 0;
}