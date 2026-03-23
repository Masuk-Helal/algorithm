#include<bits/stdc++.h>
using namespace std;

bool vis[105][105];
int level[105][105];

vector<pair<int,int>> d = {
    {-1,2},{1,2},{1,-2},{-1,-2},
    {2,1},{2,-1},{-2,1},{-2,-1}
};

int n,m;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        auto par = q.front();
        q.pop();

        int pi = par.first;
        int pj = par.second;

        for(int i = 0; i < 8; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
                q.push({ci,cj});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        int si, sj, di, dj;
        cin >> si >> sj;
        cin >> di >> dj;

        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));

        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}