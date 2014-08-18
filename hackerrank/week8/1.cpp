/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
#define maxpow 4611686018427387904
ll ispower(ll n)
{
	return !(n&(n-1));
}
ll findclosest(ll n)
{
	if(n>=maxpow)
	{
		return maxpow;
	}
	//printf("%lld\n",n);
	ll x=1,val=1,cnt=1,val1;
	val1=val;
	while(val<=n)
	{
		val1=val;
		val=val*2;
		cnt++;
		//printf("%lld %lld %d\n",val,n,val<=n);
	}
	cnt--;
	val=(ll)1<<(cnt-1);
	return val;
}
int main()
{
	ll t,flagit;
	ll n,val,cnt=0;
	sl(t);
	while(t--)
	{
		cnt=0;
		sl(n);
		while(n>1)
		{
			if(ispower(n)==1)
			{
				n/=2;
			}
			else
			{
				val=(ll)findclosest(n);
				//printf("val=%lld\n",val);
				n-=val;
			}
			cnt++;
			//printf("%lld\n",n);
		}
		if(cnt%2==0)
		{
			printf("Richard\n");
		}
		else
			printf("Louise\n");
	}
	return 0;
}









