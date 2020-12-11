#include<bits/stdc++.h>
using namespace std;
vector<int>cap,parent;
int head(int n)
{
    while(parent[n]!=n)
        n=parent[n];
    return n;
}
bool check(int a,int b)
{
    if(head(a)==head(b))return false;
    return true;
}
void unite(int a,int b)
{
    int h1=head(a);
    int h2=head(b);
    if(cap[h1]>cap[h2])
    {
        cap[h1]+=cap[h2];
        parent[h2]=h1;
    }
    else
    {
        cap[h2]+=cap[h1];
        parent[h1]=h2;
    }
}
int main()
{
  int n,m;cin>>n>>m;
  cap.resize(n+1,1);
  vector<tuple<int,int,int>>v(m);
  for(int i=0,x,y,z;i<m;++i)
  {
    cin>>x>>y>>z;
    v[i]=make_tuple(z,x,y);
  }
  parent.resize(n+1);
  iota(parent.begin(),parent.end(),0);
  sort(v.begin(),v.end());
  int sum=0;
  for(auto [x,y,z]:v)
  {
    if(check(y,z))
    {
        sum+=x;
        unite(y,z);
    }
  }
  cout<<sum<<endl;

}