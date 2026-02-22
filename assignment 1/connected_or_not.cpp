#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void connected(int q)
{
   while (q--)
   {
      int u, v;
      cin >> u >> v;

      bool found = false;

      if (u == v)
      {
         cout << "YES\n";
         continue;
      }

      for (int child : adj_list[u])
      {
         if (child == v)
         {
            found = true;
            break;
         }
      }

      if (found)
         cout << "YES\n";
      else
         cout << "NO\n";
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
   }

   int q;
   cin >> q;

   connected(q);

   return 0;
}