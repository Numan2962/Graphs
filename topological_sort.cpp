#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
vector<int>d, f;
vector<bool>visited;
int v,e,timer;
vector< pair<int,int> > val;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first>b.first;
}
void dfs(int v)
{
    ++timer;
    if(d[v]==0)
        d[v]=timer;
    visited[v]=true;
    for(auto i: adj[v])
        if(!visited[i])
            dfs(i);
    ++timer;
    if(f[v]==0)
        f[v]=timer;
}
int main()
{
    int a,b;
    cin>>v>>e;
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    d.assign(v+1, 0);
    f.assign(v+1, 0);
    visited.assign(v+1, false);

    for(int i=1;i<=v;i++)
        dfs(i);

    for(int i=1;i<=v;i++)
        val.push_back(make_pair(f[i],i));

    //sort(val.begin(),val.end(),greater< pair<int,int> >());
    sort(val.begin(),val.end(), compare);

    for(auto i: val)
        cout<<i.second<<" ";
    cout<<endl;

    return 0;
}
