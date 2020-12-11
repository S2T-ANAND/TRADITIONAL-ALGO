#include "bits/stdc++.h"
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define endl "\n"
#define amaze ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(12);
using namespace std;
typedef long long int ll;
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr<<__LINE__ <<"::"<< "[" << #__VA_ARGS__ << "]--",debug_out(__VA_ARGS__)
#endif
void debug_out(){cerr << endl;} 
template <typename Head,typename... Tail>void debug_out(Head H, Tail... T) { cerr << ' ' << H;debug_out(T...);}
int main()
{
    amaze
    int n;cin>>n;
    vector<int>BIT(n+1);//1 index
    auto update=[&](int val,int index)->void{
        ++index;
        for(index;index<=n;index+=(index&(-index))){
            BIT[index]+=val;
        }
    };
    auto query=[&](int index)->int{
        ++index;
        int sum=0;
        for(index;index>0;index-=(index&(-index))){
            sum+=BIT[index];
        }
        return sum;
    };
    vector<int>arr(n);//0 index
    for(int i=0,x;i<n;++i){
        cin>>x;
        update(x,i);
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;//0 index input
        cout<<query(b)-query(a-1)<<endl;
    }
    return 0;
}
