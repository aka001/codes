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
	return x;
}
int level[1001],levmax=-1,visited[1001],p[1001],t[1001],nr;
int findlevel(int node,int lev,vector<int> arr[])
{
	if(visited[node]==0)
	{
		level[node]=lev;
		levmax=max(levmax,level[node]);
		int sizeit,i;
		sizeit=arr[node].size();
		rep(i,sizeit)
		{
			t[arr[node][i]]=node;
			findlevel(arr[node][i],lev+1,arr);
		}
		visited[node]=1;
	}
}
int pandt(int node,vector<int> arr[])
{
	if(level[node]<nr)
	{
		p[node]=1;
	}
	else
	{
		if(!level[node]%nr)
			p[node]=t[node];
		else
			p[node]=p[t[node]];
	}
	int sizeit,i;
	sizeit=arr[node].size();
	rep(i,sizeit)
	{
		pandt(arr[node][i],arr);
	}
}
int findlca(int x,int y)
{
	while(p[x]!=p[y])
	{
		if(level[x]>level[y])
		{
			x=p[x];
		}
		else
		{
			y=p[y];
		}
	}
	while(x!=y)
	{
		if(level[x]>level[y])
			x=t[x];
		else
			y=t[y];
	}
	return x;
}
int main()
{
	int temp,n,val,i,j,m,q,x,y,k;
	si(temp);
	rep(k,temp)
	{
		printf("Case %d:\n",k+1);
		vector<int> arr[1001];
		si(n);
		rep(i,n)
		{
			visited[i]=0;
			si(m);
			rep(j,m)
			{
				int val;
				si(val);
				arr[i+1].pb(val);
			}
		}
		t[1]=1;
		findlevel(1,0,arr);
		nr=sqrt(levmax);
		pandt(1,arr);
		si(q);
		while(q--)
		{
			si(x);
			si(y);
			printf("%d\n",findlca(x,y));
		}

	}
	return 0;
}









