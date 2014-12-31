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
ll arr[10000009],n,brr[10000009],maxit;
ll findsum(ll x)
{
	ll sum=0;
	while(x>0)
	{
		sum+=arr[x];
		x-=(x&(-x));
	}
	return sum;
}
void update(ll x,ll v)
{
	while(x<=maxit)
	{
		arr[x]+=v;
		x+=(x&(-x));
	}
}
int flag[1000006];
int main()
{
	ll val,ans,i,val1,val2,k,caseit,flagit=0;
	int t;
	si(t);
	rep(caseit,t)
	{
		ans=0;
		maxit=-1;
		sl(n);
		sl(k);
		rep(i,n+1)
			flag[i]=0;
		flagit=0;
		rep(i,n)
		{
			sl(val);
			if(flag[val]!=0)
			{
				flagit=1;
			}
			flag[val]++;
			brr[i]=val;
			maxit=max(maxit,val);
		}
		rep(i,maxit+3)
			arr[i]=0;
		rep(i,n)
		{
			val=brr[i];
			val1=findsum(maxit);
			val2=findsum(val);
			ans+=val1-val2;
			update(val,1);
			//printf("i=%lld ans=%lld maxit=%lld val1=%lld val=%lld val2=%lld\n",i,ans,maxit,val1,val,val2);
		}
		if(ans>=k)
		{
			ans-=k;
		}
		else
		{
			if(flagit==1)
				ans=0;
			else
			{
				ans=k-ans;
				ans%=2;
			}
		}
		printf("Case %lld: %lld\n",caseit+1,ans);
	}
	return 0;
}














