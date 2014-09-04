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

ll powit(ll a, ll b)
{
	ll res=1,flagit=0,val;
	while(b!=0)
	{
		val=b%2;
		if(val==1)
		{
			res=res*a;
			if(res>=64 || res<0)
			{
				flagit=1;
				break;
			}
		}
		a=a*a;
		b>>=1;
	}
	if(flagit==1)
		return 65;
	else
		return res;
}
ll mult(ll a, ll b, ll c)
{
	ll ret=0;
	while(b!=0)
	{
		if(b%2==1)
		{
			ret+=a;
			if(ret>=c)
				ret-=c;
		}
		a+=a;
		if(a>=c)
			a-=c;
		b>>=1;
	}
	return ret;
}
ll checkit(ll a, ll b, ll c)
{
	ll i,val=1,flagit=0;
	rep(i,b)
	{
		val=mult(val,a,c);
		if(val%c==0)
		{
			flagit=1;
			break;
		}
		else if(val<0 || val>c)
		{
			break;
		}
		//printf("i=%lld val=%lld\n",i,val);
	}
	return flagit;
}
vector<ll> arr;
int main()
{
	ll n,q,a,b,x,lim,val,val1,i;
	sl(n);
	rep(i,n)
	{
		sl(val);
		arr.pb(val);
	}
	sl(q);
	while(q--)
	{
		sl(a);
		sl(b);
		sl(x);
		//printf("a=%lld b=%lld x=%lld\n",a,b,x);
		a--;
		b--;
		if(a==b)
		{
			val=arr[a]%x;
			if(val==0)
				printf("Yes\n");
			else
				printf("No\n");
			continue;
		}
		lim=b;
		for(i=b;i>a;i--)
		{
			if(arr[i]==1 || arr[i]==0)
			{
				lim=i;
				break;
			}
		}
		val=arr[lim];
		for(i=lim-1;i>a;i--)
		{
			val=powit(arr[i],val);
			if(val>=64)
				break;
		}
		val=min(val,64);
		printf("a=%lld\n",a);
		val1=arr[a];
		//printf("val1=%lld val=%lld x=%lld\n",val1,val,x);
		val1=checkit(val1,val,x);
		if(val1==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}









