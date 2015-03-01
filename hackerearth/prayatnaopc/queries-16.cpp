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
#include<cassert>
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
ll sg[33554434];
//Initializing the segment tree
void initialize(ll node,ll b, ll e)
{
	if(b==e)
	{
		sg[node]=0;
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,(b+e)/2+1,e);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Updating the segment tree for the values which are to be deleted/inserted
void update(ll node, ll b, ll e, ll ch,ll val)
{
	if(b>ch || e<ch || b>e)
		return;
	if(b==e && b==ch)
	{
		if(sg[node]+val>=0)
			sg[node]+=val;
	}
	else if(b!=e)
	{
		update(2*node, b, (b+e)/2, ch,val);
		update(2*node+1, (b+e)/2+1, e, ch,val);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Finding the count of the numbers lesser than a given number
ll sumit(ll node, ll b, ll e, ll x, ll y)
{
	if(b>y || e<x || b>e)
		return 0;
	else if(b>=x && e<=y)
		return sg[node];
	else
	{
		ll p1,p2;
		p1=sumit(2*node, b, (b+e)/2, x, y);
		p2=sumit(2*node+1, (b+e)/2+1, e, x, y);
		return p1+p2;
	}
}
ll sz=10000001;
int main()
{
	ll v1,v2,n,c1,c2,ans,i,calc,didit=-mod;
	//initialize(1,0,sz);
	sl(n);
	//assert(n>=1 && n<=sz-1);
	rep(i,n)
	{
		sl(v1);
		sl(v2);
		//assert(v1==0 || v1==1 || v1==2);
		//assert(v2>=1 && v2<=sz-1);
		if(v1==0 || v1==1)
		{
			if(v1==0)
				c1=1;
			else
				c1=-1;
			update(1,0,sz-1,v2,c1);
			if(v1==0)
				didit=max(didit,v2);
		}
		else
		{
			calc=1;
			ans=0;
			while(1)
			{
				c1=(calc*v2);
				c2=(calc*(v2+1))-1;
				c2=min(c2,didit);
				if(c1>didit)
					break;
				ans+=sumit(1,0,sz,c1,c2);
				calc*=2;
			}
			pln(ans);
		}
	}
	return 0;
}








