#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    //input
    //2d kadane 
    //time complexity O(n^3)
    auto kadane=[&](vector<int>&temp)->int{
        int maxm=INT_MIN,curr=0;
        for(int i=0;i<int(temp.size());++i){
            curr+=temp[i];
            if(curr>maxm)maxm=curr;
            if(curr<0)curr=0;
        }
        return maxm;
    };
    int maxv=INT_MIN;
    for(int i=0;i<col;++i){
        vector<int>temp(row);//declaration here imp
        for(int j=i;j<col;++j){//column setter
            for(int k=0;k<row;++k)
                temp[k]+=arr[k][j];
            int sum=kadane(temp);
            if(sum>maxv){
                maxv=sum;
            }
        }
    }

    cout<<maxv;
    
 
}