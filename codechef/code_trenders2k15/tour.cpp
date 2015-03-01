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
ll arr[3000000],brr[3000000];
int main()
{
	ll n,s,v1,v2,x,i,ans,j;
	ans=-mod;
	sl(x);
	sl(n);
	assert(x>=1 && x<=200000);
	rep(j,n)
	{
		sl(v1);
		sl(v2);
		rep(i,x+1)
			brr[i]=0;
		rep(i,x+1)
		{
			if(arr[i]!=0)
			{
				if(i+v1>x)
					continue;
				brr[i+v1]+=arr[i]+v2;
			}
		}
		arr[v1]=max(arr[v1],v2);
		rep(i,x+1)
		{
			arr[i]=max(arr[i],brr[i]);
			/*if(arr[i]!=0)
				printf("j=%lld i=%lld arr=%lld\n",j,i,arr[i]);*/
		}
	}
	rep(i,x+1)
	{
		ans=max(ans,arr[i]);
	}
	pln(ans);
	return 0;
}










