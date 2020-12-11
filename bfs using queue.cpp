#include<bits/stdc++.h>
using namespace std;
int main()
{

    vector<int>dis(n,-1);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(!q.empty())
    {
    	int u=q.front();q.pop();
    	cout<<u<<endl;//print bfs path
    	for(auto x:v[u])
    	{
    		if(dis[x]==-1)
    		{
    			q.push(x);
    			dis[x]=dis[u]+1;
    		}
    	}
    }
}
