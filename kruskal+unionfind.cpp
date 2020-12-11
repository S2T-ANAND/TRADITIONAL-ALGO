//kruskal algo
    //it is greedy algo where choice is made from sorted group of weight,vertex1,vertex2
    //selecting the minimum weight first
    //here for cycle checking union find data structure is used
    //where basically parent and size array are maintained
    //if head of(v1)==head of(v2) then this means they both belong to same union
    //otherwise add the edge by making the parent of one head equal to other head 
    //depending upon the size if large size is appended to smaller than it will take
    //more time(compare to small to large append) but still it will also give correct ans
#include<bits/stdc++.h>
using namespace std;
int n,m;
int parent[n+1],size[n+1];
int head(int x)
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return x;
}
bool check(int a,int b)
{
    if(head(a)==head(b))
        return false;
    return true;
}
void unite(int a,int b)
{
    if(size[a]>size[b])
    {
        parent[b]=a;
        size[a]+=size[b];
    }
    else
    {
        parent[a]=b;
        size[b]+=size[a];
    }
}
int main()
{
cin>>n>>m;
vector<pair<int,pair<int,int>>>v;
for(int i=0,x,y,z;i<m;++i)
{
    cin>>x>>y>>z;
    v.push_back({z,{x,y}});//weight,vertex1,vertex2
}
sort(v.begin(),v.end());
for(int i=1;i<=n;++i)parent[i]=i;
for(int i=1;i<=n;++i)size[i]=1;    
int sum=0;
for(auto [x,y,z]:v)
{
    if(check(y,z))
    {
        sum+=x;
        unite(head(y),head(z));
    }
}
 cout<<sum<<endl;
}