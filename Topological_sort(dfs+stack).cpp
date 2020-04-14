#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<bool>visited;
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

int main()
{
    int k,a,b,c=0;
    cin>>n>>e;
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    visited.assign(n+1, false);

    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);

    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}
