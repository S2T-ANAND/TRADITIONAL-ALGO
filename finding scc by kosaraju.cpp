#include<bits/stdc++.h>
#define debug(x) std::cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long int ll;
//scc finding by kosaraju algo
//it works in O(v+e) time
//here we will maintain an array of ans where componenet of scc of size >1 will get makrked
vector<int>G1[int(1e5+1)],G2[int(1e5+1)];
vector<bool>vis;//reassign it
vector<int>tops;
void dfs(int u)
{
    vis[u]=1;
    for(auto x:G1[u])
        if(!vis[x])
            dfs(x);
        tops.emplace_back(u);
}
void dfsagain(int u)
{
    vis[u]=1;
    comp.emplace_back(u);
    for(auto x:G2[u])
        if(!vis[x])
            dfsagain(x);
}
int main()
 {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0,x,y;i<m;++i)
    {
        cin>>x>>y;
        G1[x].emplace_back(y);
        G2[y].emplace_back(x);
    }
    vis.assign(n+1,false);
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
            dfs(i);
    }

    vis.assign(n+1,false);
    reverse(tops.begin(),tops.end());
    for(int i=0;i<n;++i)
    {
        if(!vis[tops[i]])
        {
            dfsagain(tops[i]);
            //print the scc
        }
        comp.clear();
    }


    
}