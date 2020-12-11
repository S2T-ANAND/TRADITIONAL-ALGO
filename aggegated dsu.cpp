struct dsu
{
    static const int n=101;
    int parent[n];
    int cap[n];
    void init()
    {
        iota(parent,parent+n,0);
        fill(cap,cap+n,1);
    }
    int head(int a)
    {
        if(a==parent[a])
            return a;
        return parent[a]=head(parent[a]);
    }
    void unite(int a,int b)
    {
        int x=head(a);
        int y=head(b);
        if(x!=y)
        {
            if(cap[y]>cap[x])
            swap(a,b);
            cap[x]+=cap[y];
            parent[y]=x;
        }
    }
};
dsu ds[101];//always do initialization in main