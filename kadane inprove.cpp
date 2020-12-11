#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    //input
    bool flag=false;
    int finalsum=0,finalstart=0,finalend=0,currsum=0;
    for(int i=0;i<n;++i){
        currsum+=v[i];
        if(currsum>=finalsum){
            flag=true;
            finalsum=currsum;
            finalend=i;
        }
        if(currsum<0){
            currsum=0;
            finalstart=i;
        }
    }
    if(flag){
        //kadane worked
        //finalstart and finalend are the index
    }
    else{
        //all are negative element,print the maximum one from them
    }


    
 
}