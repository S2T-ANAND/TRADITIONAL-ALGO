#include<bits/stdc++.h>
using namespace std;
int main()
{
    //dijkstra path retrieval
    //input
    vector<int>dis(n,INF),vis(n);
    vector<int>parent(n,-1);
    int source,dest;
    cin>>source>>dest;
    priority_queue<pair<int,int>>pq;
    pq.push({0,source});
    while(!pq.empty())
    {
        int u=pq.top().second;
        if(vis[u])continue;
        vis[u]=1;
        for(auto x:v[u])
        {
            if(dis[x.first]>dis[u]+x.second)//necessary step
            {
                dis[x.first]=dis[u]+x.second;
                pq.push({-dis[x.first],x.first});
                parent[x.first]=u;
            }
        }
    }
    if(vis[dest])
    {
        vector<trace>;
        while(dest!=source)
        {
            trace.push_back(dest);
            dest=parent[dest];
        }
    }



}