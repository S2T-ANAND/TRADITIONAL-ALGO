 //input
    //lis in nlogn
	//only for calculating the length
    vector<int>lis;
    for(int i=0;i<int(v.size());++i){
        if(int(lis.size())==0){
            lis.emplace_back(v[i]);
        }
        else{
            if(lis.back()<v[i]){
                lis.emplace_back(v[i]);
            }
            else{
                auto it=lower_bound(lis.begin(),lis.end(),v[i]);
                *it=v[i];
            }
        }
    }
    cout<<lis.size()<<endl;