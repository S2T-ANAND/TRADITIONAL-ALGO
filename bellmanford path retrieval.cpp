#include<bits/stdc++.h>
using namespace std;
int main()
{
    //BELLMAN FORD PATH RETRIEVAL
    //works only when no negative cycle is present
    vector<tuple<int,int,int>>v;
    //input
    vector<int>parent(n,-1);
    vector<int>dis(n,INT_MAX);
    int destination;
    cin>>destination;
    dis[0]=0;
    for(int i=0;i<n;++i)
    {
        for(auto x:v)
        {
            int a,b,c;
            tie(a,b,c)=x;
            if(dis[b]>dis[a]+c)
            {
                dis[b]=dis[a]+c;
                parent[b]=a;
            }
        }
    } 
    if(dis[destination]==INT_MAX)
        cout<<"THERE IS NO PATH"<<endl;
    else
    {
        vector<int>trace;
        while(destination!=source)
        {
            trace.push_back(destination);
            destination=parent[destination];
        }
        reverse(trace.begin(),trace.end());
        for(auto x:trace)cout<<x<<" ";
        }

}