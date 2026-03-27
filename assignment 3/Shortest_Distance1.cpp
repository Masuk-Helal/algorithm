#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<long long>> adj(n+1, vector<long long>(n+1, LLONG_MAX));

    for(int i = 1; i <= n; i++)
        adj[i][i] = 0;

    while(e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;

        adj[a][b] = min(adj[a][b], w);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(adj[i][k] == LLONG_MAX || adj[k][j] == LLONG_MAX)
                    continue;

                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;

    while(q--)
    {
        int x, y;
        cin >> x >> y;

        if(adj[x][y] == LLONG_MAX)
            cout << -1 << '\n';
        else
            cout << adj[x][y] << '\n';
    }

    return 0;
}