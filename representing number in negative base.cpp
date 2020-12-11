int n;cin>>n;
    const int base=-2;
    vector<int>v;
    while(n!=0){
        int rem=n%base;
        n/=base;
        D(n,rem);
        if(rem<0){
            rem+=(-base);
            ++n;
        }
        v.emplace_back(rem);
    }
    reverse(all(v));
    if(int(v.size())>0)
    for(auto &x:v)cout<<x;
    else cout<<0;