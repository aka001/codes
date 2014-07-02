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

int isprime[100006];
vector<int> primeit;
void seive()
{
	int i,j;
	int max=100006;
	isprime[0] = isprime[1] = 1; 
	primeit.pb(1);
	primeit.pb(2);
	for (i = 4; i < max; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < max; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < max; j += 2 * i)
				{
					isprime[j] = 1; 
				}
			primeit.pb(i);
		}
	}
}
ll a[100001],b[100001],c[100001],flagit[100001],ans[100001],valit[100001];
int visited[100001];
vector<ll> storeit[100001];
int main()
{
	int n,m,sizeit,i,j,k,j1;
	seive();
	sizeit=primeit.size();
	si(n);
	si(m);
	rep(i,100001)
		valit[i]=1;
	rep(i,n)
	{
		sl(a[i+1]);
	}
	rep(i,m)
	{
		sl(b[i+1]);
		flagit[b[i+1]]=1;
		storeit[b[i+1]].pb(i+1);
	}
	rep(i,m)
	{
		sl(c[i+1]);
	}
	FOR(i,1,m+1)
	{
		if(visited[b[i]]==0 && flagit[b[i]]==1)
		{
			sizeit=storeit[b[i]].size();
			//printf("visited=%lld sizeit=%d %lld\n",b[i],sizeit, storeit[b[i]][0]);
			rep(j,sizeit)
			{
				valit[b[i]]*=c[storeit[b[i]][j]];
				if(valit[b[i]]>mod)
					valit[b[i]]%=mod;
			}
			//printf("hie\n");
			visited[b[i]]=1;
		}
	}
	rep(i,100001)
		visited[i]=0;
	FOR(i,1,100001)
	{
		if(visited[i]==0 && flagit[i]==1)
		{
			j=i;
			j1=i;
			while(j<=n)
			{
				a[j]*=valit[i];
				if(a[j]>mod)
					a[j]%=mod;
				j+=j1;
			}
			visited[i]=1;
		}
	}
	/*for(i=1;i<=n;i++)
	{
		j=0;
		while(primeit[j]<=i)
		{
			//printf("not if i=%d primeit=%d i primeit[j]=%d flagit[j]=%lld\n",i,primeit[j],i%primeit[j],flagit[j]);
			if(i%primeit[j]==0 && flagit[primeit[j]]==1)
			{
			//	printf("i=%d primeit=%d\n",i,primeit[j]);
				sizeit=storeit[primeit[j]].size();
				rep(k,sizeit)
				{
					if(storeit[primeit[j]][k]<=i)
					{
						a[i]=a[i]*c[storeit[primeit[j]][k]];
						if(a[i]>mod)
							a[i]%=mod;
					}
					else
						break;
				}
			}
			j++;
		}
	}*/
	FOR(i,1,n+1)
	{
		if(a[i]>mod)
			a[i]%=mod;
		printf("%lld ",a[i]);
	}
	printf("\n");
	return 0;
}











