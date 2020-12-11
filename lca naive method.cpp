#include "bits/stdc++.h"
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define endl "\n"
using namespace std;
typedef long long int ll;
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
void debug_out() { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int Maxn=1e5+1;
vector<int>v[Maxn];
vector<int>vis,level,par;
int lca(int u,int to)
{
    if(level[u]<level[to])
        swap(u,to);
    int d=level[u]-level[to];
    while(d>0){//coming to same level
        u=par[u];--d;
    }
    if(u==to)return u;//if in same branch
    while(par[u]!=par[to]){//rising from the same level;
        u=par[u];
        to=par[to];
    }
    return par[u];
}
void dfs(int u,int val=0){
    vis[u]=1;
    for(auto x:v[u]){
        if(vis[x]==0){
            par[x]=u;
            level[x]=val+1;
            dfs(x,level[x]);
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n;cin>>n;
   for(int i=0,x,y;i<n;++i){
    cin>>x;
    while(x--){
        cin>>y;
        v[i].emplace_back(y);
        v[y].emplace_back(i);
    }
   }
   vis.assign(n+1,0);
   level.assign(n+1,0);
   par.assign(n+1,0);
   par[0]=-1;
   dfs(0);//assuming the tree is connected
   int q;cin>>q;
   while(q--){
    int u,v;cin>>u>>v;
    cout<<lca(u,v)<<endl;

   }
    return 0;

}