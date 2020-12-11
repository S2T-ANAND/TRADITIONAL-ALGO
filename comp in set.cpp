struct comp{//c++14 practice not applicable to c++17
bool operator()(const auto &a,const auto &b){
    return a.first==b.first?a.second>b.second:a.first>b.first;
}
};
//here if first element is equal we have to compare for 2nd element ,otherwise all the pair with first 
will not get printed
//c++17 practice 
 auto comp=[](const pair<int,int>&p1,const pair<int,int>&p2){
        return p1.second<p2.second;
    };
set<pair<int,int>,decltype(comp)>st(comp);
here it is sorted according to second element
