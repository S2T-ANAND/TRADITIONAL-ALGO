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
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(13);
   int t;cin>>t;
   while(t--){
    string s,t;cin>>s>>t;
    //as all are lower case hence p=31;
    //mod =1e9+7;
    const ll mod=1e9+7;
    const ll prime=31;
    vector<ll>hash(max(sz(s),sz(t)));
    hash[0]=1;
    for(int i=1;i<sz(hash);++i){
        hash[i]=(hash[i-1]*prime)%mod;
    }
    vector<ll>hash_s(sz(s)+1,0);
    for(int i=0;i<sz(s);++i){
        hash_s[i+1]=hash_s[i]+hash[i]*(s[i]-'a'+1);
        hash_s[i+1]%=mod;
    }
    ll to_search=0;
    for(int i=0;i<sz(t);++i){
        to_search+=(hash[i]*(t[i]-'a'+1));
        to_search%=mod;
    }
    vector<int>found;
    for(int i=0;i+sz(t)-1<sz(s);++i){
        ll cal=(hash_s[i+sz(t)]-hash_s[i]+mod)%mod;
        ll cal1=(to_search*hash[i])%mod;
        if(cal==cal1){
            found.emplace_back(i+1);
        }
    }
    if(sz(found)==0){
        cout<<"Not Found"<<endl;
    }
    else
    {
        cout<<sz(found)<<endl;
        for(auto &x:found)cout<<x<<" ";
            cout<<endl;
    }
    cout<<endl;
   }
    return 0;
}