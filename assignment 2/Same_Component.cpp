#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[105][105];
bool vis[105][105];

int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (!vis[nx][ny] && grid[nx][ny] == '.')
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = row[j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m ||
        x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
    {
        cout << "NO" << endl;
        return 0;
    }

    if (grid[x1][y1] == '-' || grid[x2][y2] == '-')
    {
        cout << "NO" << endl;
        return 0;
    }

    memset(vis, false, sizeof(vis));

    dfs(x1, y1);

    if (vis[x2][y2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}