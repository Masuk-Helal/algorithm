#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[105][105];
bool vis[105][105];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    int cnt = 1;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        int cx = par.first;
        int cy = par.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!vis[nx][ny] && grid[nx][ny] == '.')
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    memset(vis, false, sizeof(vis));

    int mn = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                int area = bfs(i, j);
                mn = min(mn, area);
                found = true;
            }
        }
    }

    if (!found)
        cout << -1 << endl;
    else
        cout << mn << endl;

    return 0;
}