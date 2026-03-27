#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
   int a, b;
   long long c;

   Edge(int a, int b, long long c)
   {
      this->a = a;
      this->b = b;
      this->c = c;
   }
};

long long dis[1005];
vector<Edge> edge_list;
int n, e;

int main()
{
   cin >> n >> e;

   while (e--)
   {
      int a, b;
      long long c; 
      cin >> a >> b >> c;
      edge_list.push_back(Edge(a, b, c));
   }

   int s;
   cin >> s;

   for (int i = 1; i <= n; i++)
   {
      dis[i] = LLONG_MAX; 
   }
   dis[s] = 0;

   for (int i = 1; i <= n - 1; i++)
   {
      for (auto ed : edge_list)
      {
         if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
         {
            dis[ed.b] = dis[ed.a] + ed.c;
         }
      }
   }

   for (auto ed : edge_list)
   {
      if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
      {
         cout << "Negative Cycle Detected\n";
         return 0;
      }
   }

   int t;
   cin >> t;

   while (t--)
   {
      int d;
      cin >> d;

      if (dis[d] == LLONG_MAX)
         cout << "Not Possible\n";
      else
         cout << dis[d] << "\n";
   }

   return 0;
}