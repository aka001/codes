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
pair<int,int> chetu[32],nishu[32];
int chet[32],nish[32];
int main()
{
	int t,i,n;
	si(t);
	chet[32]=0;
	nish[32]=0;
	for(i=31;i>=1;i--)
	{
		if(chet[i+1]==1 || chet[i+2]==1)
		{
			if(chet[i+1]==1)
			{
				chetu[i].F=1;
				chetu[i].S=1;
			}
			else
			{
				chetu[i].F=1;
				chetu[i].S=2;
			}
			chet[i]=1;
		}
		if(nish[i+1]==0 || nish[i+2]==0)
		{
			if(nish[i+1]==0)
			{
				chetu[i].F=2;
				chetu[i].S=1;
			}
			else
			{
				chetu[i].F=2;
				chetu[i].S=2;
			}
			chet[i]=1;
		}
		if(chet[i+1]==0 || chet[i+2]==0)
		{
			if(chet[i+1]==0)
			{
				nishu[i].F=1;
				nishu[i].S=1;
			}
			else
			{
				nishu[i].F=1;
				nishu[i].S=2;
			}
			nish[i]=1;
		}
		if(nish[i+1]==1 || nish[i+2]==1)
		{
			if(nishu[i+1]==1)
			{
				nishu[i].F=2;
				nishu[i].S=1;
			}
			else
			{
				nishu[i].F=2;
				nishu[i].S=2;
			}
			nish[i]=1;
		}
	}
	while(t--)
	{
		si(n);
		printf("%d %d\n",chetu[n].F,chetu[n].S);
	}
	return 0;
}













