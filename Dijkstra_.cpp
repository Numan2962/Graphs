#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ipair;
vector<ipair>adj[1000];
vector<int>dist, p;
priority_queue< ipair, vector<ipair> > pq;
int v,e,src;

void dijkstra()
{
    dist.assign(v+1, 100000);
    p.assign(v+1, 0);

    p[src]=-1;
    dist[src]=0;
    pq.push(make_pair(src, 0));
    while(!pq.empty())
    {
        //cout<<"queue: : "<<pq.top().first<<" "<<pq.top().second<<endl;
        int u=pq.top().first;
        pq.pop();
        for(auto k: adj[u])
        {
            int x=k.first;
            int weight=k.second;
            if(dist[x]>dist[u]+weight)
            {
                dist[x]=dist[u]+weight;
                pq.push(make_pair(x, dist[x]));
                p[x]=u;
            }
        }
    }

}

int main()
{
    int a,b,w;
    cin>>v>>e;
    while(e--)
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    cin>>src;
    dijkstra();
    cout<<"vertex distance from source:"<<endl;
    for(int i=1;i<=v;i++)cout<<i<<"\t"<<dist[i]<<endl;

    return 0;
}
