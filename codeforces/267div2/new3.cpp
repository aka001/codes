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
#define ll long long int
ll arr[5006]={0},cum[5006]={0},str[5006]={0},dp[5002][5002],m,n,maxit=-1;
ll solve(ll l,ll k)
{
	if(l>=n || k<=0)
		return 0;
	if(dp[l][k]!=-1)
	{
		return dp[l][k];
	}
	else
	{
		if(l+m<=n)
		{
			ll val,val1;
			val=str[l]+solve(l+m,k-1);
			val1=solve(l+1,k);
			//printf("l=%lld k=%lld val=%lld val1=%lld\n",l,k,val,val1);
			dp[l][k]=max(val,val1);
			return dp[l][k];
		}
		else
			return 0;
	}
}
int main()
{
	ll k,i,sum=0,val,val1,j;
	sum=0;
	sl(n);
	sl(m);
	sl(k);
	rep(i,n)
	{
		sl(arr[i]);
		sum+=arr[i];
		cum[i]=sum;
	}
	rep(i,n)
	{
		val=0;
		if(i+m-1>=n)
		{
			str[i]=0;
			continue;
		}
		if(i!=0)
			val=cum[i-1];
		val1=cum[i+m-1];
		str[i]=val1-val;
		//printf("i=%d str[i]=%lld\n",i,str[i]);
	}
	rep(i,n+2)
	{
		rep(j,k+2)
		{
			dp[i][j]=-1;
		}
	}
	solve(0,k);
	printf("%lld\n",dp[0][k]);
	return 0;
}













