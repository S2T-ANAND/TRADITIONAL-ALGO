#include "bits/stdc++.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(13);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n][n];
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>arr[i][j];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i<j)
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n/2;++j){
                swap(arr[i][j],arr[i][n-1-j]);
            }
        }
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)cout<<arr[i][j]<<" ";
            cout<<endl;
    }

}