#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
vector<bool>visited, Is_cutpoint;
vector<int> tin, low;
int timer;

void dfs(int v, int p)
{
    visited[v]=true;
    tin[v]=low[v]= ++timer;
    int child=0;
    for(int u: adj[v])
    {
        if(u==p)continue;
        if(visited[u])
            low[v]=min(low[v],tin[u]);
        else
        {
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            if(low[u]>=tin[v] && p!=-1)
                Is_cutpoint[v]=true;
            child++;

        }
    }
    if(p==-1 && child>1)
        Is_cutpoint[v]=true;
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
    Is_cutpoint.assign(v,false);
    tin.assign(v, -1);
    low.assign(v, -1);
    dfs(1, -1);
    cout<<"Articulation point: ";
    for(int i=1;i<=v;i++)
        if(Is_cutpoint[i])
            cout<<i<<" ";
    cout<<endl;

    return 0;
}
