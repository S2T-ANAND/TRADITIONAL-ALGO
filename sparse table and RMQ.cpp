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
int ST[20][Maxn];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(13);
   int n;cin>>n;
   int rowl=__lg(n)+1;
   vector<int>v(n);for(int i=0;i<n;++i)cin>>v[i];
   for(int i=0;i<=rowl;++i){
    int lenth=1<<i;
    for(int j=0;j+lenth<=n;++j){
        if(lenth==1){
            ST[i][j]=v[j];
        }
        else{
            ST[i][j]=min(ST[i-1][j],ST[i-1][j+lenth/2]);
        }
    }
   }
   int q;cin>>q;
   while(q--){
    int l,r;cin>>l>>r;
    int lenth=__lg(r-l+1);
    int range=1<<lenth;
    cout<<min(ST[lenth][l],ST[lenth][r-range+1])<<endl;
   }

    return 0;
}