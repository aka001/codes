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
ll sizeit,maxit=-1;
void initialize(ll arr[],int node,int b, int e)
{
	if(b==e)
	{
		arr[node]=0;
	}
	else
	{
		initialize(arr,2*node,b,(b+e)/2);
		initialize(arr,2*node+1,(b+e)/2+1,e);
	}
}
void update(ll arr[],int node,int b,int e,int i,int j,int val)
{
	if(b>=i && e<=j)
		arr[node]+=val;
	if(i>e || j<b)
	{
		return;
	}
	if(b==e)
		return;
	update(arr,2*node,b,(b+e)/2,i,j,val);
	update(arr,2*node+1,(b+e)/2+1,e,i,j,val);
}
void query(ll arr[],int node,int b,int e,int i,int j)
{
	if(i>e || j<b)
	{
		return;
	}
	if(b==e)
	{
		if(arr[node]>maxit)
			maxit=arr[node];
		return;
	}
	query(arr,2*node,b,(b+e)/2,i,j);
	query(arr,2*node+1,(b+e)/2+1,e,i,j);
}
ll arr[1000000];
int main()
{
	int n,m,i,a,b,k;
	double calc;
	si(n);si(m);
	calc=log(n)/log(2);
	calc=(int)calc;
	sizeit=calc;
	sizeit=1<<sizeit;
	sizeit<<=1;
	initialize(arr,1,0,n-1);
	rep(i,m)
	{
		si(a);si(b);si(k);
		a--;
		b--;
		update(arr,1,0,n-1,a,b,k);
	}
	query(arr,1,0,n-1,0,n-1);
	printf("%lld\n",maxit);
	return 0;
}








