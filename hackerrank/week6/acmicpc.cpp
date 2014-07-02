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
vector<int> arr[10000],zero[3000];
char ch[3001][3001];
int visited[3001],megavisited[3001],maxit[3001],oneit[3000];
int main()
{
	int n,m,i,j,k,flag=0,lenit,val,cnt,l,cnt1,val1,size,sizeit,flagit=0;
	si(n);
	si(m);
	rep(i,n)
	{
		ss(ch[i]);
		cnt=0;
		rep(j,m)
		{
			if(ch[i][j]=='1')
			{
				arr[j].pb(i);
				cnt++;
			}
			else
			{
				zero[i].pb(j);
			}
		}
		oneit[i]=cnt;
	}
	rep(i,n)
	{
		flag=0;
		FOR(j,1,n+1)
			visited[j]=0;
		sizeit=zero[i].size();
		flagit=0;
		rep(j,sizeit)
		{
			val=zero[i][j];
			cnt=oneit[i];
			size=arr[val].size();
			if(size!=0)
			{
				flagit=1;
			}
			rep(k,size)
			{
				val1=arr[val][k];
				if(visited[val1]==0 && megavisited[val1]==0)
				{
					cnt1=cnt;
					rep(l,sizeit)
					{
						if(ch[val1][zero[i][l]]=='1')
						{
							if(i==2)
							{
								//printf("i=%d val1=%d l=%d\n",i,val1,l);
							}
							cnt1++;
						}
					}
					maxit[cnt1]++;
					//printf("cnt1=%d maxit[cnt1]=%d i=%d val1=%d\n",cnt1,maxit[cnt1],i,val1); 
					visited[val1]=1;
				}
			}
		}
		if(flagit==0)
		{
			maxit[cnt]+=n-i-1;
		}
		megavisited[i]=1;
	}
	for(i=3001;i>=0;i--)
	{
		if(maxit[i]!=0)
		{
			printf("%d\n%d\n",i,maxit[i]);
			break;
		}
	}
	return 0;
}















