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
//finding Lca by binary lifting or sparse table
const int Maxn=1e5+1;
vector<int>v[Maxn];
int arr[Maxn][20];
vector<int>level;
void dfs(int u,int p=-1){
    arr[u][0]=p;
    if(p!=-1)level[u]=level[p]+1;
    for(auto x:v[u]){
        if(x^p)dfs(x,u);
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(13);
   int n;cin>>n;
   for(int i=0,x,y;i<n;++i){
        cin>>x>>y;
        v[i].emplace_back(u);
        v[u].emplace_back(i);
   }
   memset(arr,-1,sizeof(arr));
   level.assign(n+1,0);
   dfs(0);
   for(int i=1;i<=__lg(n);++i){
    for(int j=0;j<n;++j){
        if(arr[j][i-1]==-1)continue;
        int to=arr[j][i-1];
        arr[j][i]=arr[to][i-1];
    }
   }
   int q;cin>>q;
   while(q--){
    int a,b;cin>>a>>b;
    if(level[b]>level[a])swap(a,b);
    int d=level[a]-level[b];
    while(d>0){
        int jump=log2(d);
        a=arr[a][jump];
        d-=(1<<jump);
    }
    if(a==b){cout<<a<<endl;continue;}
    while(arr[a][0]!=arr[b][0]){
        a=arr[a][0];
        b=arr[b][0];
    }
    cout<<arr[a][0]<<endl;
   }

}