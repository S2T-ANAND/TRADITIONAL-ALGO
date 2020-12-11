#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
const int MOD=int(1e9)+7;
const ll  INF=int(1e15);
const int nax=100000;
const int len=350;//sqrt of nax
int ML=0,MR=-1,cnt=0;
int arr[nax];
int freq[int(1e6+1)];
int ans[int(1e6+1)];//for queries
vector<tuple<int,int,int>>queries;
bool comp(const tuple<int,int,int> &x,const tuple<int,int,int> &y){
    auto [l1,r1,i1]=x;
    auto [l2,r2,i2]=y;
    if((l1/len)!=(l2/len))return (l1/len) < (l2/len);//imp
    else return r1<r2;//imp
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    int q;cin>>q;
    for(int i=0,x,y;i<q;++i){
        cin>>x>>y;
        queries.emplace_back(x,y,i);
    }
    sort(all(queries),comp);
    for(int i=0;i<q;++i){
        auto [L,R,idx]=queries[i];
        while(ML>L){
            ML--;
            freq[arr[ML]]++;
            if(freq[arr[ML]]==1)
                ++cnt;
        }
        while(MR<R){
            MR++;
            freq[arr[MR]]++;
            if(freq[arr[MR]]==1)
                ++cnt;
        }
        while(ML<L){
            freq[arr[ML]]--;
            if(freq[arr[ML]]==0)
                cnt--;
            ML++;
        }
        while(MR>R){
            freq[arr[MR]]--;
            if(freq[arr[MR]]==0)
                cnt--;
            MR--;
        }
        ans[idx]=cnt;
    }
    for(int i=0;i<q;++i)
        cout<<ans[i]<<"\n";


}