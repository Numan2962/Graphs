#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
queue<int>q;
int main()
{
    int v,e,tm,a,b,s,dis;
    cin>>v>>e;
    tm=e;
    vector<int> d(v), p(v);
    vector<bool> used(v);

    while(tm--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>s>>dis;

    q.push(s);
    used[s]=true;
    p[s]=-1;
    while(!q.empty())
    {
        int u,v=q.front();
        q.pop();
        for(u=0;u<adj[v].size();u++)
        {
            int l=adj[v][u];
            if(!used[l])
            {
                used[l]=true;
                q.push(l);
                p[l]=v;
                d[l]=d[v]+1;
            }
        }
    }
    if(!used[dis])
        cout<<"No path found";
    else
    {
        vector<int>path;
        for(int v=dis;v!=-1;v=p[v])
            path.push_back(v);
        reverse(path.begin(),path.end());
        cout<<"Path: ";
        for(int v=0;v<path.size();v++)
            cout<<path[v]<<" ";
        cout<<endl;
        cout<<"Path length: "<<d[dis]-d[s]<<endl;
    }

    return 0;
}
