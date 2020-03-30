#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
bool used[50]={0};
int deg[100];
vector<int>connect;
void dfs(int v)
{
    used[v]=true;
    int u;
    connect.push_back(v);
    for(u=0;u<adj[v].size();u++)
    {
        int k=adj[v][u];
        if(!used[k])
            dfs(k);
    }
}

int main()
{
    int v,e,a,b,num=0;
    cin>>v>>e;
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i=1;i<=v;i++)
    {
        if(!used[i])
        {
            dfs(i);
            num++;
            cout<<"Component "<<num<<": ";
            for(int p=0;p<connect.size();p++)
            {
                cout<<connect[p]<<" ";
            }
            cout<<endl;
            connect.clear();
        }
    }
    cout<<"Number of Component :"<<num<<endl;
    cout<<"Degree: "<<endl;
    for(int i=1;i<=v;i++)
        cout<<i<<": "<<deg[i]<<endl;

    return 0;
}
