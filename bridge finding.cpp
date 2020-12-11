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
vector<int>v[Maxn];//finding bridges ,use low and in array
vector<int>low,in,vis;
vector<pair<int,int>>vp;
int cnt;
void dfs(int u,int p=-1)
{
    vis[u]=1;
    in[u]=low[u]=cnt++;
    for(auto x:v[u]){
        if(x==p)continue;
        if(vis[x]==0){
            dfs(x,u);
            low[u]=min(low[x],low[u]);
            if(low[x]>in[u]){
                vp.emplace_back(min(x,u),max(x,u));
            }
        }
        else{
            low[u]=min(low[u],in[x]);
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n,m;cin>>n>>m;
   for(int i=0,x,y;i<m;++i){
    cin>>x>>y;v[x].emplace_back(y);v[y].emplace_back(x);
   }
   low.assign(n,0);in.assign(n,0);vis.assign(n,0);
   for(int i=0;i<n;++i){
    if(vis[i]==0){
        cnt=0;
        dfs(i);
    }
   }
   sort(all(vp));
   for(auto x:vp)cout<<x.first<<" "<<x.second<<endl;
   return 0;
}