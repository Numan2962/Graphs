#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ipair;

#define INF 1000000
vector< ipair >adj[1000];
vector<int>dist, p;
int source,v,e;

void dijkstra()
{
    priority_queue<ipair, vector<ipair> > pq;
    dist.assign(v+1, INF);
    p.assign(v+1, 0);

    pq.push(make_pair(source, 0));
    dist[source]=0;
    p[source]=-1;

    while(!pq.empty())
    {
        //cout<<"queue: : "<<pq.top().first<<" "<<pq.top().second<<endl;
        int u=pq.top().first;
        pq.pop();

        for(auto t=adj[u].begin();t!=adj[u].end(); t++)
        {
            int x=t->first;
            int weight=t->second;
            if(dist[x]>dist[u]+weight)
            {
                dist[x]=dist[u]+weight;
                pq.push(make_pair(x,dist[x]));
                p[x]=u;
            }
        }
    }
}

int main()
{
    int w,a,b,c,i,dis;
    cin>>v>>e;
    while(e--)
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    cin>>source>>dis;
    dijkstra();
    cout<<"distance form "<<source<<" to "<<dis<<" is: ";
    cout<<dist[dis]<<endl;

    vector<int>path;
    for(c=dis;c!=source;c=p[c])path.push_back(c);
    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(c=0;c<path.size();c++)
        cout<<path[c]<<" ";
    cout<<endl;

//    for(int u=1;u<=v;u++)
//    {
//        cout<<"Node: "<<u<<" makes an edges with:"<<endl;
//        for(auto j=adj[u].begin(); j!=adj[u].end(); j++)
//        {
//            cout<<"\tnode "<<j->first<<" with edge weight = "<<j->second<<endl;
//        }
//        cout<<endl<<endl;
//    }

    return 0;
}
