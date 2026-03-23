#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_list[105];
int parent[105];

int main()
{

   int n, e;
   cin >> n >> e;
   vector<pair<int, int>> adj_list[n];
   int parent[105];
   while (e--)
   {
      int a, b, c;
      cin >> a >> b >> c;
      adj_list[a].push_back({b, c});
      adj_list[b].push_back({a, c});
   }
   for (int i = 0; i < n; i++)
   {
      cout << i << " -> ";
      for (pair<int, int> p : adj_list[i])
      {
         cout << p.first << "  " << p.second << ", ";
      }
      cout << endl;
   }

   return 0;
}