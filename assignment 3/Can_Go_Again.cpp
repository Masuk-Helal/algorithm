#include <bits/stdc++.h>
using namespace std;


int dis[1005];
vector<Edge> edge_list;
int n, e;

class Edge
{
public:
   int a, b, c;
   Edge(int a, int b, int c)
   {
      this->a = a;
      this->b = b;
      this->c = c;
   }
};

int main()
{
   cin >> n >> e;

   while (e--)
   {
      int a, b, c;
      cin >> a >> b >> c;
      edge_list.push_back(Edge(a, b, c));
   }

   int s;
   cin >> s;

   for (int i = 1; i <= n; i++)
   {
      dis[i] = INT_MAX;
   }
   dis[s] = 0;

   for (int i = 1; i <= n - 1; i++)
   {
      for (auto ed : edge_list)
      {
         if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
         {
            dis[ed.b] = dis[ed.a] + ed.c;
         }
      }
   }

   bool cycle = false;
   for (auto ed : edge_list)
   {
      if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
      {
         cycle = true;
         break;
      }
   }

   if (cycle)
   {
      cout << "Negative Cycle Detected\n";
      return 0;
   }

   int t;
   cin >> t;

   while (t--)
   {
      int d;
      cin >> d;

      if (dis[d] == INT_MAX)
         cout << "Not Possible\n";
      else
         cout << dis[d] << "\n";
   }

   return 0;
}