  int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;++i)cin>>arr[i];
        int cnt[n] {1};
        for(int i=0;i<n;++i){
            int element=arr[i];
			cnt[i]=1;
            for(int j=0;j<i;++j){
                if(arr[j]<element&&cnt[j]>=cnt[i]){
                    cnt[i]=1+cnt[j];
                }
            }
        }
        cout<<*max_element(cnt,cnt+n)<<endl;	