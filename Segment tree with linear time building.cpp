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
    int n=1;vector<pair<int,int>>v;
    void init(int x){
        while(n<x)n<<=1;
        v.assign(2*n,{1,INT_MAX});
    }
    void sets(vector<int>&arr,int x,int l,int r){
        if(r-l==1){
            if(l<int(arr.size())){
                v[x]={1,arr[l]};
            }
            return ;
        }
        int mid=(l+r)/2;
        sets(arr,2*x+1,l,mid);
        sets(arr,2*x+2,mid,r);
        v[x].second=min(v[2*x+1].second,v[2*x+2].second);
        v[x].first=0;
        if(v[x].second==v[2*x+1].second)v[x].first+=v[2*x+1].first;
        if(v[x].second==v[2*x+2].second)v[x].first+=v[2*x+2].first;
    }
    void sets(vector<int>&arr){
        sets(arr,0,0,n);
    }
    void build(int index,int val,int x,int l,int r){
        if(r-l==1){
            v[x]={1,val};return ;
        }
        int  mid=(l+r)/2;
        if(index<mid){
            build(index,val,2*x+1,l,mid);
        }
        else{
            build(index,val,2*x+2,mid,r);
        }
        v[x].second=min(v[2*x+1].second,v[2*x+2].second);
        v[x].first=0;
        if(v[x].second==v[2*x+1].second)v[x].first+=v[2*x+1].first;
        if(v[x].second==v[2*x+2].second)v[x].first+=v[2*x+2].first;
    }
    void build(int index,int val){
        build(index,val,0,0,n);
    }
    pair<int,int>answer(int l,int r,int x,int lx,int rx){
        if(lx>=r||rx<=l)return {0,INT_MAX};
        if(lx>=l&&rx<=r)return {v[x].first,v[x].second};
        int mid=(lx+rx)/2;
        auto q1=answer(l,r,2*x+1,lx,mid);
        auto q2=answer(l,r,2*x+2,mid,rx);
        int minm=min(q1.second,q2.second);
        int cnt=0;
        if(minm==q1.second)cnt+=q1.first;
        if(minm==q2.second)cnt+=q2.first;
        return {cnt,minm};
    }
    pair<int,int>answer(int l,int r){
        return answer(l,r,0,0,n);
    }
}ST;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(13);
    int n,q;cin>>n>>q;
    ST.init(n);
    vector<int>arr(n);
    for(int i=0,x;i<n;++i){
        cin>>arr[i];
    }
    ST.sets(arr);
    while(q--){
        int which;cin>>which;
        if(which==1){
            int index,val;cin>>index>>val;
            ST.build(index,val);
        }
        else{
            int l,r;cin>>l>>r;
            auto ans=ST.answer(l,r);
            cout<<ans.second<<" "<<ans.first<<endl;
        }
    }
}