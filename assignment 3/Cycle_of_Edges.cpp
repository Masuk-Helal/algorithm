#include <bits/stdc++.h>
using namespace std;


int par[10005];
int group_size[10005];


int find(int node)
{
   if (par[node] == -1)
   {
      return node;
   }
   int leader = find(par[node]);
   par[node] = leader;
   return leader;
}


void dsu_union(int node1, int node2)
{
   int leaderA = find(node1);
   int leaderB = find(node2);

   if (leaderA == leaderB) 
      return;

   if (group_size[leaderA] >= group_size[leaderB])
   {
      par[leaderB] = leaderA;
      group_size[leaderA] += group_size[leaderB];
   }
   else
   {
      par[leaderA] = leaderB;
      group_size[leaderB] += group_size[leaderA];
   }
}



int main()
{
   int n, e;
   cin >> n >> e;
   for (int i = 1; i <= n; i++)
   {
      par[i] = -1;
      group_size[i] = 1;
   }

   int cycle_count = 0;

   while (e--)
   {
      int a, b;
      cin >> a >> b;

      int leaderA = find(a);
      int leaderB = find(b);

      if (leaderA == leaderB)
         cycle_count++;  
      else
         dsu_union(a, b);
   }

   cout << cycle_count << endl;

   return 0;
}