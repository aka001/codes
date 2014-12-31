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
inline ll cnt_digits(ll n)
{
	ll cnt=0;
	while(n!=0)
	{
		cnt++;
		n/=2;
	}
	return cnt;
}
vector<ll> sit[100];
ll nit[100],arr[1000006];
vector<ll> pow2;
void pre()
{
	ll calc=1,i;
	rep(i,65)
	{
		pow2.pb(calc);
		calc*=2;
	}
}
inline int no_of_bits(ll n)
{
	ll l=0,h=62,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		//printf("val=%lld arr=%lld mid=%lld\n",n,pow2[mid],mid);
		if(n>=pow2[mid] && (mid==61 || n<pow2[mid+1]))
		{
			return mid;
		}
		else if(n>=pow2[mid])
			l=mid+1;
		else
			h=mid-1;
	}
	return -1;
}
int main()
{
	ll n,val,ans=0,i,j,calc,sz,x,y;
	pre();
	sl(n);
	rep(i,n)
	{
		sl(arr[i]);
		/*if(arr[i]==1)
			calc=1;
		else*/
		calc=no_of_bits(arr[i])+1;
		//printf("-=============== %lld\n",arr[i]);
		//pln(calc);
		sit[calc].pb(arr[i]);
	}
	for(i=64;i>0;i--)
	{
		sz=sit[i].size();
		if(sz==0)
			continue;
		x=sit[i][0];
		FOR(j,1,sz)
		{
			y=sit[i][j];
			val=x^y;
			calc=no_of_bits(val)+1;
			if(calc==i)
				assert(-1>0);
			sit[calc].pb(val);
		}
		nit[i]=x;
	}
	for(i=64;i>0;i--)
	{
		x=nit[i];
		if((ans^x)>ans)
			ans^=x;
	}
	pln(ans);
	return 0;
}









