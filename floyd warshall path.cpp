#include<bits/stdc++.h>
using namespace std;
int main()
{
    //floyd warshall path retrieval
    //input
    //check AGAIN
    int path[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                if(dis[j][k]>dis[j][i]+dis[i][k])
                {
                    dis[j][k]=dis[j][i]+dis[i][k];
                    path[j][k]=path[i][k];
                }
            }
        }
    }
    if(dis[source][des]!=INF)
    {
        vector<int>trace;
        while(path[source][des]!=source)
        {
            trace.push_back(path[source][des]);
            des=path[source][des];
        }
    }





}