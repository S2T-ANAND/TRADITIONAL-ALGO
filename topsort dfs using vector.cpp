#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<int>&vis,vector<int>v[],vector<int>&ans)
{
	vis[u]=1;
	for(auto x:v[u])
	{
		if(vis[x]==0)
		{
			dfs(x,vis,v,ans);
		}
	}
   ans.push_back(u);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];
    vector<int>vis(n+1,0);
    vector<int>ans;
    for(int i=0,x,y;i<m;++i)
    {
        cin>>x>>y;v[x].push_back(y);v[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
    {
    	if(vis[i]==0)
    	{
    		vis[i]=1;
    		dfs(i,vis,v,ans);
    	}
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";


}
