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
int main()
{
	int t;
	ll n,k,ans=0;
	double calc1,calc2,calc3;
	si(t);
	while(t--)
	{
		ans=0;
		sl(n);sl(k);
		calc3=n*n-4*n*k;
		if(calc3<0)
		{
			n--;
			pln(n);
			continue;
		}
		calc1=(n-sqrt(n*n-4*n*k))/2;
		calc2=(n+sqrt(n*n-4*n*k))/2;
		if((ll)calc1==(ll)calc2)
		{
			pln((ll)(calc1-1+n-calc2));
			continue;
		}
		calc1=(ll)calc1;
		if(calc2==(double)((ll)calc2))
		{
			calc2=(ll)calc2;
			calc2--;
		}
		calc2=(ll)calc2;
		if(calc2<=n && calc1>=1)
			ans+=calc1+n-calc2-1;
		else if(calc2>n && calc1>=1)
			ans+=calc1;
		else if(calc2<=n && calc1<1)
			ans+=n-calc2-1;
		else
			ans=0;
		pln(ans);
	}
	return 0;
}




