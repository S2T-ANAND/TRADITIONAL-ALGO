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
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(2);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;++i)
            cin>>v[i];
        stack<pair<ll,int>>sp;
        vector<ll>ans(n);
        sp.push({v[0],0});
        for(int i=1;i<n;++i){
            while(!sp.empty()&&sp.top().first<v[i]){
                ans[sp.top().second]=v[i];
                sp.pop();
            }
            sp.push({v[i],i});
        }
        ll element=sp.top().first;
        ans[sp.top().second]=-1;sp.pop();
        while(!sp.empty()&&sp.top().first<element){
            ans[sp.top().second]=element;
            sp.pop();
        }
        while(!sp.empty()){
            ans[sp.top().second]=-1;sp.pop();
        }
        for(auto &x:ans)cout<<x<<" ";cout<<endl;

    }

}
