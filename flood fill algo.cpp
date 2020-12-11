//flood fill algo
int dr[8] {-1,-1,-1,0,0,1,1,1};
int dc[8] {-1,0,1,-1,1,-1,0,1};
int n,m;
int vis[n][m];
void dfs(int r,int c,vector<int>v[])
{ 
   if(r>=n||r<0||c<0||c>=m)
    return ;
   if(vis[r][c]&&v[r][c]!=1)return;
   vis[r][c]=1;
   for(int i=0;i<8;++i)
    {
	dfs(r+dr[i],c+dc[i],v);
    }
}
int main()
{
  for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
		if(vis[i][j]==0&&v[i][j])
			dfs(i,j,v);
}