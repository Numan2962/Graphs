#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
    bool operator<(const edge& p)
    {
        return w<p.w;
    }
};

int n,m;
vector<edge>vv;
vector<int> parent, rnk;

int find_set(int v)
{
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
int mst(int n)
{
    sort(vv.begin(),vv.end());
    parent.assign(n+1, -1);
    for(int i=1;i<=n;i++)parent[i]=i;

    int cnt=0, s=0;
    for(int i=0;i<(int)vv.size();i++)
    {
        int u=find_set(vv[i].u);
        int v=find_set(vv[i].v);
        if(u!=v)
        {
            parent[u]=v;
            cnt++;
            s+=vv[i].w;
            if(cnt==n-1)
                break;
        }
    }
    return s;
}

int main()
{
    int u,v,w;
    edge get;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        get.u=u;
        get.v=v;
        get.w=w;
        vv.push_back(get);
    }

    cout<<mst(n)<<endl;

    return 0;
}
