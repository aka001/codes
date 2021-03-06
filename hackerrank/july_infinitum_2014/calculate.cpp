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
	if(x>=mod)
		x%=mod;
	return x;
}
ll factit[100009];
int arr[100009];
ll comb(ll n2, ll k1)
{
	ll calc1=factit[n2];
	ll calc2=factit[k1];
	ll calc3=factit[n2-k1];
	ll calc4;
	//printf("n2=%lld calc1=%lld calc2=%lld calc3=%lld\n",n2,calc1,calc2,calc3);
	calc1%=mod;
	calc2=powerit(calc2,mod-2);
	calc3=powerit(calc3,mod-2);
	if(calc2>=mod)
		calc2%=mod;
	if(calc3>=mod)
		calc3%=mod;
	calc4=calc1*calc2;
	if(calc4>=mod)
		calc4%=mod;
	calc4*=calc3;
	if(calc4>=mod)
		calc4%=mod;
	return calc4;
}
int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	ll calc,ans=0,k1,n2,n1,calc1,calc2,n,k,i,calc3,calc4,x;
	factit[0]=1;
	FOR(i,1,100009)
	{
		factit[i]=i*factit[i-1];
		if(factit[i]>=mod)
			factit[i]%=mod;
	}
	sl(n);
	sl(k);
	rep(i,n)
	{
		si(arr[i]);
	}
	qsort(arr,n,sizeof(arr[0]),compare);
	k1=k-1;
	n2=n-1;
	n1=n-k;
	n1++;
	rep(i,n1)
	{
		calc1=comb(n2-i,k1);
		calc1%=mod;
		calc3=arr[n-i-1];
		calc4=arr[i];
		calc3-=calc4;
		calc2=calc1*calc3;
		if(calc2>=mod)
			calc2%=mod;
		//printf("combiantion=%lld factorial=%d calculationfinal=%lld n2i=%lld k1=%lld calc3=%d calc4=%d i=%lld\n",calc1,arr[n-i-1]-arr[i],calc2,n2-i,k1,arr[n-i-1],arr[i],i);
		ans+=calc2;
		if(ans>=mod)
			ans%=mod;
	}
	if(ans<=0)
	{
		x=1;
		while(ans<=0)
		{
			ans+=x*mod;
			x*=2;
		}
		ans%=mod;
	}
	pln(ans);
	return 0;
}














