#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100], reverseEdge[100], component[100];
vector<bool>visited;
vector<bool>check;
stack<int>stk;

int n,e;

void dfs(int v)
{
    visited[v]=true;
    for(auto i: adj[v])
        if(!visited[i])
            dfs(i);
    stk.push(v);
}

void dfs2(int v, int c)
{
    check[v]=true;
    component[c].push_back(v);
    for(auto i: reverseEdge[v])
        if(!check[i])
            dfs2(i,c);
}

int main()
{
    int k,a,b,c=0;
    cin>>n>>e;
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        reverseEdge[b].push_back(a);
    }
    visited.assign(n+1, false);
    check.assign(n+1, false);

    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);

    while(!stk.empty())
    {
        k=stk.top();
        stk.pop();
        if(!check[k])
        {
            c++;
            dfs2(k,c);
        }
    }
    for(int i=1;i<=c;i++)
    {
        for(auto j: component[i])
            cout<<j<<" ";
    cout<<endl;
    }


    return 0;
}

