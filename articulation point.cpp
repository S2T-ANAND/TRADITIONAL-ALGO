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
vector<int>in,low,vis;
set<int>articulation;//due to duplicates
int cnt;
void dfs(int u,int p=-1)
{
    vis[u]=1;
    in[u]=low[u]=cnt++;
    int children=0;
    for(auto x:v[u]){
        if(x==p)continue;
        if(vis[x]){
            low[u]=min(low[u],in[x]);
        }
        else{
            dfs(x,u);
            low[u]=min(low[u],low[x]);
            if(low[x]>=in[u]&&p!=-1){
                articulation.emplace(u);
            }
            children++;
        }
    }
    if(p==-1&&children>1){
        articulation.emplace(u);
    }

}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n,m;cin>>n>>m;
   for(int i=0,x,y;i<m;++i){
    cin>>x>>y;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
   }
   in.assign(n+1,0);
   low.assign(n+1,0);
   vis.assign(n+1,0);
   for(int i=0;i<n;++i){
    if(vis[i]==0){
        cnt=1;
        dfs(i);
    }
   };
   for(auto x:articulation)cout<<x<<endl;
    return 0;

}