#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
using namespace std;
const int MOD = int(1e9)+7;
const int MAX = 2e5+5;
#define int int long long
int ST[MAX][30];
signed main ()
{
    #ifndef LOCAL
    #define endl '\n'
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #endif
    //preprocessing
    for (int i = 0; i < n; ++i) ST[i][0] = arr[i];
    // ST[i][j] stores [i, i + 2 ^ j - 1]
    //ST[i][j] = f(ST[i][j - 1] , ST[i + 1 << (j - 1)][j]);
    int K = log2(n);
    for (int j = 1; j <= K; ++j) {
    	for (int i = 0; i < n; ++i) {
    		ST[i][j] = fun(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    	}
    }
    //query 
    // [l, r)
    for (int i = K; i >= 0; --K) {
    	if ((1 << k) <= r - l) {
    		ans = f(ans, ST[l][i]);
    		l += (1 << i);
    	}
    } 
 
    

}
/* check for
	* TLE due to ll, array bounds
	* special cases (n=0,1)
	* DON'T GET STUCK ON ONE APPROACH
*/