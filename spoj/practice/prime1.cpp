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
#define MAX 1000006
int low;
inline int mapit(int x)
{
	return x-low;
}
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
vector<ll> primeit;
int isprime[1000006]; 
void seive()
{
	int i,j;
	isprime[0] = 1;
	isprime[1] = 1; 
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
	FOR(i,2,MAX)
		if(isprime[i]==0)
			primeit.pb(i);
}
int arr[1000006];
int main()
{
	int t,i,a,b,sizeit,val,j;
	seive();
	sizeit=primeit.size();
	si(t);
	while(t--)
	{
		si(a);
		si(b);
		low=a;
		if(b<=MAX)
		{
			rep(i,sizeit)
			{
				if(primeit[i]>=a && primeit[i]<=b)
					printf("%lld\n",primeit[i]);
				else if(primeit[i]>b)
					break;
			}
		}
		else
		{
			if(a<=MAX)
			{
				rep(i,sizeit)
				{
					if(primeit[i]>=a)
						printf("%lld\n",primeit[i]);
				}
				a=MAX+1;
			}
			for(i=a;i<=b;i++)
			{
				arr[mapit(i)]=0;
			}
			rep(i,sizeit)
			{
				val=a/primeit[i];
				val*=primeit[i];
				for(j=val;j<=b;j+=primeit[i])
				{
					arr[mapit(j)]=1;
				}
			}
			for(i=a;i<=b;i++)
			{
				if(arr[mapit(i)]==0)
					printf("%d\n",i);
			}
		}
		printf("\n");
	}
	return 0;
}













