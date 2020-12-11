#include<bits/stdc++.h>
using namespace std;
int main()
{
    //bellman ford algo
    //like dynaminc programming try all approach
    //works also on negative weight and used to detect negative cycle
    //O(|v||E|) time complexity SSSP
    int n,m;cin>>n>>m;
    vector<tuple<int,int,int>>v(m);//there are m edges hence m tuple
    for(int i=0,x,y,z;i<m;++i)
    {
        cin>>x>>y>>z;
        v[i]=make_tuple(x,y,z);     
    }
    int flag=0;
    vector<int>dis(n,INT_MAX);
    dis[source]=0;
    for(int i=0;i<n;++i)
    {
        flag=0;
        for(auto x:v)
        {
            int a,b,c;
            tie(a,b,c)=x;
            if(dis[b]>dis[a]+c)
            {
                dis[b]=dis[a]+c;
                flag=1;
            }
        }
        if(!flag)//improved
            break;
    }
}
