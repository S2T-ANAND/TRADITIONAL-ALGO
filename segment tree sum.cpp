#include "bits/stdc++.h"
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define endl "\n"
using namespace std;
typedef long long int ll;
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]--->",debug_out(__VA_ARGS__)
#endif
void debug_out(){cerr << endl;} 
template <typename Head,typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr<<"  "<<to_string(H);
  debug_out(T...);
}
class segment{
public:
    vector<ll>v;
    int n=1;
    void init(int x){
        while(n<x){
            n*=2;
        }
        v.assign(2*n,0);
    }
    void build(int index,int val,int x,int l,int r){
        if(r-l==1){
            v[x]=val;return ;
        }
        int mid=(l+r)/2;
        if(index<mid){
            build(index,val,2*x+1,l,mid);
        }
        else
            build(index,val,2*x+2,mid,r);
        v[x]=v[2*x+1]+v[2*x+2];
    }
    void build(int index,int val){
        build(index,val,0,0,n);
    }
    ll answer(int l,int r,int x,int lx,int rx){
        if(lx>=r||l>=rx){
            return 0;
        }
        if(lx>=l&&rx<=r){
            return v[x];
        }
        int mid=(lx+rx)/2;
        ll sum1=answer(l,r,2*x+1,lx,mid);
        ll sum2=answer(l,r,2*x+2,mid,rx);
        return sum1+sum2;
    }
    ll answer(int l,int r){
        return answer(l,r,0,0,n);
    }

}ST;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(13);
    int n,q;cin>>n>>q;
    ST.init(n);
    for(int i=0,x;i<n;++i){
        cin>>x;
        ST.build(i,x);
    }
    while(q--){
        int which;cin>>which;
        if(which==1){
            int index,val;cin>>index>>val;
            ST.build(index,val);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<ST.answer(l,r)<<endl;
        }
    }
   
}