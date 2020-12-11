#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define endl "\n"
#define ld long double
using namespace std;
typedef long long int ll;
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr<<__LINE__ <<"::"<< "[" << #__VA_ARGS__ << "]->",debug_out(__VA_ARGS__)
#endif
void debug_out(){cerr << endl;} 
template <typename Head,typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr<<" "<<to_string(H);
  debug_out(T...);
}
const int nax=1e7;
vector<ll>v(nax);
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(2);
    int t;cin>>t;
    while(t--){
        //using two pointer technique
        int n;cin>>n;
        for(int i=0;i<n;++i)cin>>v[i];
        ll ans=0;
        vector<ll>maxl(n),maxr(n);
        maxl[0]=v[0];
        for(int i=1;i<n;++i){
            maxl[i]=max(maxl[i-1],v[i]);
        }
        maxr[n-1]=v[n-1];
        for(int i=n-2;i>=0;--i){
            maxr[i]=max(maxr[i+1],v[i]);
        }
        for(int i=1;i<n-1;++i){
            ans+=max(min(maxr[i+1],maxl[i-1])-v[i],0ll);
        }
        cout<<ans<<endl;
    }

}
