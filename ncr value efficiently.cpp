/* TO CALCULATE THE VALUE OF NCR */
ll ans(ll n,ll r)
{
  ll ans=1;
  ll den=1;
  for(int i=1;i<=r;++i)	
   {
	ans*=(i+n-r));
        den*=(i);
        ll k=gcd(ans,den);
        ans/=k;
        den/=k;
   }
  return ans;
}