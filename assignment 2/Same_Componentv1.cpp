#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {

        cin >> grid[i]; 

        if ((int)grid[i].size() != m) {
            cout << "NO" << endl;
            return 0;
        }

    }

    int n1, n2, y1, y2;
    cin >> n1 >> y1;
    cin >> n2 >> y2;

    if (n1 < 0 || n1 >= n || y1 < 0 || y1 >= m ||
        n2 < 0 || n2 >= n || y2 < 0 || y2 >= m ||
        grid[n1][y1] == '-' || grid[n2][y2] == '-') {
        cout << "NO" << endl;
        return 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int,int>> q;
    
    q.push({n1, y1});
    visited[n1][y1] = true;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << (visited[n2][y2] ? "YES" : "NO") << endl;

    return 0;
}