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
pair<ll,ll> sg[1000006];
ll arr[1000006],n;
int flagit[1000006];
void initialize(int node,int b, int e)
{
	if(b==e)
	{
		sg[node].F=arr[b];
		sg[node].S=b;
		flagit[node]=1;
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,(b+e)/2+1,e);
		//sg[node].F=sg[2*node].F+sg[2*node+1].F;
		if(sg[2*node].F>sg[2*node+1].F)
		{
			sg[node].F=sg[2*node].F;
			sg[node].S=sg[2*node].S;
		}
		else
		{
			sg[node].F=sg[2*node+1].F;
			sg[node].S=sg[2*node+1].S;
			if(sg[2*node+1].F==sg[2*node].F)
				flagit[node]=1;
			else
				flagit[node]=0;
		}
	}
}
inline int mxit(int node, int b, int e, int x, int y)
{
	if(b>y || e<x)
		return 0;
	else if(b>=x && e<=y)
		return node;
	else
	{
		int p1,p2;
		p1=mxit(2*node, b, (b+e)/2, x, y);
		p2=mxit(2*node+1, (b+e)/2+1, e, x, y);
		if(sg[p1].F>sg[p2].F)
			return p1;
		else
			return p2;
	}
}
ll findit(ll low,ll high,ll val)
{
	if(low==high)
	{
		//printf("low=%lld val=%lld\n",low,val);
		return val-arr[low];
	}
	else if(low<high)
	{
		ll i,flag,maxit=-1,pos=-1,ans1,ans2,ans,nde;
		nde=mxit(1,0,n-1,low,high);
		pos=sg[nde].S;
		maxit=sg[nde].F;
		//printf("UP ABOVE low=%lld high=%lld pos=%lld maxit=%lld flagit=%d\n",low,high,pos,maxit,flagit[nde]);
		if(flagit[nde]==1)
		{
			//printf("low=%lld high=%lld pos=%lld maxit=%lld flagit=%d\n",low,high,pos,maxit,flagit[nde]);
			return val-arr[low];
		}
		else
		{
			ans1=findit(low,pos-1,sg[nde].F);
			ans2=findit(pos+1,high,sg[nde].F);
			ans=ans1+ans2+val-maxit;
			//printf("low=%lld high=%lld pos=%lld maxit=%lld ans1=%lld ans2=%lld ans=%lld val=%lld\n",low,high,pos,maxit,ans1,ans2,ans,val);
			return ans;
		}
	}
	return 0;
}
int main()
{
	ll k,i,maxit=-1,pos=-1,fin,ans1,ans2,ans,ask;
	sl(n);
	sl(k);
	rep(i,n)
	{
		sl(arr[i]);
		if(arr[i]>maxit)
		{
			maxit=arr[i];
			pos=i;
		}
	}
	initialize(1,0,n-1);
	ask=mxit(1,0,n-1,0,n-1);
	maxit=sg[ask].F;
	pos=sg[ask].S;
	//printf("maxit=%lld pos=%lld\n",maxit,pos);
	ans1=findit(0,pos-1,maxit);
	ans2=findit(pos+1,n-1,maxit);
//	printf("ans1=%lld ans2=%lld\n",ans1,ans2);
	ans=ans1+ans2;
	//printf("ans1=%lld ans2=%lld ans=%lld pos=%lld maxit=%lld\n",ans1,ans2,ans,pos,maxit);
	fin=0;
	if(ans<=k)
		fin=k-ans+1;
	pln(fin);
	return 0;
}











