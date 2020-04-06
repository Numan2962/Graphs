#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
vector<bool>visited;
vector<int>tin, low;
vector< pair<int,int> > bridges;
int timer;

void dfs(int v, int p)
{
    visited[v]=true;
    tin[v]=low[v]= ++timer;
    for(int u: adj[v])
    {
        if(u==p)continue;
        if(visited[u])
            low[v]=min(low[v],tin[u]);
        else
        {
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            if(low[u]>tin[v])
                bridges.push_back(make_pair(v,u));
        }
    }
}

int main()
{
    int v,e,a,b;
    cin>>v>>e;
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer=0;
    visited.assign(v,false);
    tin.assign(v, -1);
    low.assign(v, -1);

    dfs(1, -1);
    cout<<"Bridges:"<<endl;
    for(int i=0;i<bridges.size();i++)
        cout<<bridges[i].first<<" "<<bridges[i].second<<endl;

    return 0;
}
