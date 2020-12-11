#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
#ifdef ONLINE_JUDGE
#define D(...)
#else
#define D(...)cerr<<__LINE__<<":"<<"["<<#__VA_ARGS__<<"]->",P(__VA_ARGS__)
#endif
void P(){cerr<<endl;} 
template<typename H,typename...T>void P(H h,T...t){cerr<<h<<" ";P(t...);}
void heapify(int arr[],int n,int index){
    int largest=index;
    if(2*index+1<n&&arr[2*index+1]>arr[index])
        largest=2*index+1;
    if(2*index+2<n&&arr[2*index+2]>arr[largest])
        largest=2*index+2;
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int arr[8] {1,2,3,4,55,5,5,689};//max heap
    int index=3;
    for(int i=index;i>=0;--i)
        heapify(arr,8,i);
    for(auto x:arr)cout<<x<<" ";
    
    
}