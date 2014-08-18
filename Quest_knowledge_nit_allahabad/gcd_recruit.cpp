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

ll saveit[3009][3009],present[3006];
int main()
{
	ll n,i,cnt=0,j,final=0,final1=0,val;
	ll thisisit=0;
	FOR(i,1,3009)
		FOR(j,1,3009)
			saveit[i][j]=0;
	FOR(i,2,3009)
	{
		FOR(j,i+1,3009)
		{
			if(j%i==0)
				saveit[i][j]=1;
			else
			{
				val=gcd(i,j);
				if(val!=1)
					saveit[i][j]=1;
				else
					saveit[i][j]=0;
			}
		}
	}
	sl(n);
	rep(i,n)
	{
		sl(val);
		present[val]++;
	}
	FOR(i,2,3001)
	{
		if(present[i]!=0)
		{
			cnt=0;
			FOR(j,i+1,3001)
			{
				if(saveit[i][j]==1 && present[j]!=0)
				{
					cnt+=present[j];
				}
			}
			final=present[i];
			final1=final*cnt;
			final=(present[i]*(present[i]-1))/2;
			thisisit+=final+final1;
		}
	}
	pln(thisisit);
	return 0;
}








