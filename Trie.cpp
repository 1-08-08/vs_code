#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    bool is_end;
    Trie *vec[26];
    long long number;
    Trie()
    {
        this->is_end = false;
        this->number = -1;
        for (int i = 0; i < 26; i++)
            this->vec[i] = NULL;
    }
};

void insert(Trie *root, string nam, long long num)
{
    Trie *temp = root;
    for (int i = 0; i < (int)nam.size(); i++)
    {
        if (temp->vec[nam[i] - 'a'] == NULL)
            temp->vec[nam[i] - 'a'] = new Trie();
        temp = temp->vec[nam[i] - 'a'];
    }
    temp->is_end = true;
    temp->number = num;
}

long long find(Trie *root, string nam)
{
    Trie *temp = root;
    for (int i = 0; i < (int)nam.size(); i++)
    {
        if (temp->vec[nam[i] - 'a'] == NULL)
            return -1;
        temp = temp->vec[nam[i] - 'a'];
    }
    if (temp->is_end)
        return temp->number;
    return -1;
}

int main()
{

    Trie *root = new Trie();
    long long num;
    string nam;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nam >> num;
        insert(root, nam, num);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> nam;
        cout << find(root, nam);
    }
    return 0;
}