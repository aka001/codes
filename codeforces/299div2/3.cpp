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
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll a,b;
ll possible(ll l, ll m, ll t, ll mid,ll val)
{
	ll nit=(mid-l)+1;
	ll lit=l-1,hit=mid-1;
	ll s1=(nit*(2*lit+(nit-1)))/2;
	ll sum=nit*a+s1*b;
	if(sum<=val)
		return 1;
	return 0;
}
ll binary(ll low, ll high, ll m, ll t,ll val)
{
	ll mid,l=low;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(possible(l,m,t,mid,val) && !(possible(l,m,t,mid+1,val)))
			return mid;
		else if(possible(l,m,t,mid,val))
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
ll bin(ll val, ll t)
{
	ll low=0,high=1000000,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(mid*b<=t && (mid+1)*b>t)
			return mid;
		else if(mid*b>t)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}
int main()
{
	ll n,MAX,val,i,l,t,m,lit,cit;
	MAX=3000000;
	sl(a);
	sl(b);
	sl(n);
	//possible(1,3,5,4);
	rep(i,n)
	{
		sl(l);
		sl(t);
		sl(m);
		lit=a+(l-1)*b;
		//trace4(lit,t,l,m);
		val=lit+lit*m;
		if(t<lit)
		{
			pin(-1);
			continue;
		}
		t-=lit;
		cit=bin(val,t);
		trace1(cit);
		cit=(cit*(cit+1))/2;
		val+=cit*b;
		pln(val);
		val=binary(l,MAX,m,t,val);
		pln(val);
	}
	return 0;
}













