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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
int isprime[1000006];
vector<int> primeit;
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
	ll i,j,MAX=1000006,sqrtit;
	isprime[0]=1;
	isprime[1]=1;
	for(i=4;i<MAX;i+=2)
		isprime[i]=0;
	for(i=3;i<MAX;i+=2)
	{
		if(isprime[i]==0)
		{
			for(j=i*i;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	for(i=2;i<MAX;i++)
		if(isprime[i]==0)
			primeit.pb(i);
}
int main()
{
	int t;
	ll calc1,calc2,sqrtit,calc,c4,c,cnt,calcit;
	seive();
	si(t);
	while(t--)
	{
		sl(calc1);
		c=calc1;
		sqrtit=sqrt(calc1);
		sqrtit++;
		cnt=0;
		calc1=c;
		calc2=1;
		//Finding all prime factors which is less than sqrt(n) and using the formula above
		while(primeit[cnt]<=sqrtit)
		{
			calcit=primeit[cnt];
			if(c%calcit==0)
			{
				calc1*=(calcit-1);
				calc2*=calcit;
				c4=gcd(calc1,calc2);
				calc1/=c4;
				calc2/=c4;
				while(c%calcit==0 && c!=0)
				{
					//printf("hie\n");
					c/=calcit;
				}
			}
			cnt++;
		}
		if(c!=1 && isprime[c]==0)
		{
			calc1*=(c-1);
			calc2*=c;
		}
		calc1/=calc2;
		pln(calc1);
	}
	return 0;
}
