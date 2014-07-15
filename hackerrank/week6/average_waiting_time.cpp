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
#define F first
#define S second

long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
				{
					isprime[j] = 1; 
				}
		}
	}
}
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
vector<pair<ll,ll> > arr;
int main()
{
	int n,i;
	ll s,f;
	ll ans=0,cur=0;
	pair<int,int> topit;
	si(n);
	rep(i,n)
	{
		sl(s);
		sl(f);
		arr.pb(mp(s,f));
	}
	sort(arr.begin(),arr.end());
	priority_queue< pair< ll,ll > , vector< pair<ll,ll> >, greater< pair<ll,ll> > > mheap;
	mheap.push(mp(arr[0].S,arr[0].F));
	cur=arr[0].F;
	i=1;
	while(i<n || !mheap.empty())
	{
		while(i<n && arr[i].F<=cur)
		{
			mheap.push(mp(arr[i].S,arr[i].F));
			i++;
		}
		if(mheap.empty() && i<n)
		{
			cur=arr[i].F;
			mheap.push(mp(arr[i].S,arr[i].F));
			i++;
		}
		topit=mheap.top();
		mheap.pop();
		cur+=topit.F;
		ans+=cur-topit.S;
		//printf("cur=%lld ans=%lld start=%d tot=%d\n",cur,ans,topit.S, topit.F);
	}
	ans/=n;
	pln(ans);
	return 0;
}




