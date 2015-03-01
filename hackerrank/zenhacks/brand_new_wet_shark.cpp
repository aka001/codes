/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
#include<cassert>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<ll> arr;
ll m,r,s,c1,c2;
ll a[3000][103],b[3000][103];
int main()
{
	ll i,val,j,k;
	ll ans=0;
	sl(m);
	sl(r);
	sl(s);
	assert(m>=1 && m<=100);
	assert(r>=0 && r<=2000);
	assert(s>=0 && s<=2000);
	rep(i,m)
	{
		sl(val);
		assert(val>=1 && val<=2000);
		arr.pb(val);
	}
	if(((r+s)%2!=0) || ((r-s)%2!=0) || (r<=s))
	{
		printf("0\n");
		return 0;
	}
	c1=(r+s)/2;
	c2=(r-s)/2;
	//a[0][0]=1;
	rep(k,m)
	{
		rep(i,2001)
			rep(j,m+1)
				b[i][j]=0;
		rep(i,2001)
			rep(j,m+1)
			if(a[i][j]!=0)
			{
				if(i+arr[k]>2000 || j+1>m)
					continue;
				b[i+arr[k]][j+1]+=a[i][j];
				b[i+arr[k]][j+1]%=mod;
			}
		rep(i,2001)
			rep(j,m+1)
			{
				a[i][j]+=b[i][j];
				a[i][j]%=mod;
			}
		a[arr[k]][1]++;
	}
	//printf("c1=%lld c2=%lld\n",c1,c2);
	/*if(c1==c2)
	  {
	  rep(i,m+1)
	  {
	  ans+=(a[c1][i]*(a[c1][i]-1))/2;
	  ans%=mod;
	  }
	  }
	  else
	  {*/
	a[0][0]=0;
	rep(i,m+1)
	{
		//printf("i=%lld a=%lld %lld\n",i,a[c1][i],a[c2][i]);
		ans+=(a[c1][i]*a[c2][i])%mod;
		ans%=mod;
	}
	//	}
	pln(ans);
	return 0;
}











