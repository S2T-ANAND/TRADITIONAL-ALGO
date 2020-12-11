#include<bits/stdc++.h>
using namespace std;
int main()
{
    //SPFA shortest path faster algo
    //improvement over bellman ford
    //O(|v||E|) worst time complexity SSSP,but generally is faster and approx to dijkstra
    int n,m;cin>>n>>m;
    vector<pair<int,int>>v[n];
    for(int i=0,x,y,z;i<m;++i)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});
    }
    vector<int>dis(n,INT_MAX);
    vector<int>check(n);
    queue<int>q;
    dis[source]=0;
    q.push(source);
    check[source]=1;
    vector<int>total(n);
    total[source]++;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        check[u]=0;
        for(auto x:v[u])
        {
            if(dis[x.first]>dis[u]+x.second)
            {
                dis[x.first]=dis[u]+x.second;
                if(total[x.first]>n-1)//check if node is processed greater than n-1 times
                    goto label;
                if(!check[x.first])
                {
                    q.push(x.first);
                    total[x.first]++;
                    check[x.first]=1;
                }
            }
        }
    }
    cout<<"it has no negative cycle"<<endl;continue;
    label:cout<<"yes it has negative cycle"<<endl;
}
