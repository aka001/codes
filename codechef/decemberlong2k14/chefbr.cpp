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
ll arr[1000006],brr[1000006],flag[1000006],pos[1000006],mark[1000006];
pair<ll,ll> dp[1000006];
inline ll check(ll n)
{
	if(n>=mod)
		n%=mod;
	return n;
}
inline ll checkneg(ll n)
{
	if(n<0)
	{
		while(n>0)
		{
			n+=mod;
			n%=mod;
		}
	}
	return n;
}
int main()
{
	ll n,i,len=0,j,flg,calc;
	sl(n);
	rep(i,n)
		sl(arr[i]);
	rep(i,n)
	{
		flg=0;
		if(arr[i]<0)
		{
			FOR(j,i+1,n)
			{
				if(arr[j]==-arr[i] && flag[j]==0)
				{
					flag[j]=1;
					flg=1;
					break;
				}
			}
		}
		if(flg==1 || flag[i]==1)
		{
			brr[len++]=arr[i];
		}
	}
	n=len;
	rep(i,n)
	{
		if(brr[i]>0)
		{
			for(j=i-1;j>=0;j--)
			{
				if(brr[j]==-brr[i] && pos[j]!=-2)
				{
					pos[i]=j;
					pos[j]=-2;
					break;
				}
			}
		}
		else
			pos[i]=-1;
	}

	rep(i,n)
		printf("%lld ",brr[i]);
	printf("\n");
	
	rep(i,n)
	{
		printf("%lld %lld\n",brr[i],pos[i]);
	}
	printf("\n");
	dp[0].F=1;
	dp[0].S=0;
	FOR(i,1,n)
	{
		calc=-1;
		if(brr[i]>0)
		{
			calc=dp[i-1].F;
			calc=check(calc);
			for(j=i-1;j>=0;j--)
			{
				if(brr[j]==-brr[i] && mark[j]!=-1)
				{
					mark[j]=-1;
					break;
				}
				if((brr[j]>0 && pos[j]<pos[i]) || brr[j]==brr[i])
				{
					calc-=dp[j].S;
				}
			}
			calc=checkneg(calc);
			dp[i].S=calc;
			dp[i].F=dp[i-1].F+calc;
		}
		else
		{
			dp[i]=dp[i-1];
		}
		dp[i].F=check(dp[i].F);
		dp[i].S=check(dp[i].S);
		printf("brr=%lld calc=%lld dp.F=%lld dp.S=%lld\n",brr[i],calc,dp[i].F,dp[i].S);
	}
	/*if(dp[n-1].F<0)
	{
		printf("%d\n",1/0);
		return 0;
	}*/
	pln(dp[n-1].F);
	return 0;
}








