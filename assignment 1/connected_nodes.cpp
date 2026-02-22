#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void connected_nodes(int q)
{
    while (q--)
    {
        int x;
        cin >> x;

        if (adj_list[x].empty())
        {
            cout << -1 << "\n";
            continue;
        }

        sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
        for (int node : adj_list[x])
        {
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    connected_nodes(q);

    return 0;
}