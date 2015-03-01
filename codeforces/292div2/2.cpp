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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll brr[105],grr[105];
int v1[100006],v2[100006];
int main()
{
	ll n,m,b,g,calc,cnt=1,val,i,j,flag;
	sl(n);
	sl(m);
	sl(b);
	rep(i,b)
	{
		sl(val);
		brr[val]=1;
	}
	sl(g);
	rep(i,g)
	{
		sl(val);
		grr[val]=1;
	}
	calc=n%m;
	while(1)
	{
		if(v1[calc]==1)
			break;
		printf("calc=%lld\n",calc);
		v1[calc]=1;
		cnt++;
		calc=(n*cnt)%m;
	}
	calc=m%n;
	while(1)
	{
		if(v2[calc]==1)
			break;
		v2[calc]=1;
		cnt++;
		calc=(m*cnt)%n;
	}
	rep(i,n)
	{
		rep(j,m)
		{
			calc=j-i;
			if(calc<0)
			{
				calc=-calc;
				calc*=(m-1);
				calc%=m;
			}
			if(v1[calc]==1)
			{
				if(brr[i] == 1 || grr[j]==1)
					brr[i]=grr[j]=1;
			}
		}
	}
	rep(i,n)
	{
		rep(j,m)
		{
			calc=j-i;
			if(calc<0)
			{
				calc=-calc;
				calc*=(n-1);
				calc%=n;
			}
			if(v2[calc]==1)
			{
				if(brr[i] == 1 || grr[j]==1)
					brr[i]=grr[j]=1;
			}
		}
	}
	flag=1;
	rep(i,n)
	{
		if(brr[i]==0)
		{
			printf("i=%lld\n",i);
			flag=0;
		}
	}
	rep(i,m)
	{
		if(grr[i]==0)
		{
			flag=0;
		}
	}
	if(flag==1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}









