#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

bool vis[105][105];
char grid[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
bool found = false;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    if (!valid(si, sj))
        return;
    if (vis[si][sj])
        return;
    if (grid[si][sj] == '#')
        return;

    if (grid[si][sj] == 'B')
    {
        found = true;
        return;
    }

    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;

    int si, sj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    dfs(si, sj);

    if (found)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}