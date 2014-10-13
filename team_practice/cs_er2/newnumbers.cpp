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
ll arr[1000006];
ll findit(ll low,ll high,ll val)
{
	if(low==high)
	{
		//printf("low=%lld val=%lld\n",low,val);
		return val-arr[low];
	}
	else if(low<high)
	{
		ll i,flagit=0,maxit=-1,pos=-1,ans1,ans2,ans;
		for(i=low;i<=high;i++)
		{
			if(arr[i]>maxit)
			{
				maxit=arr[i];
				pos=i;
			}
		}
		for(i=low;i<high;i++)
		{
			if(arr[i]!=arr[i+1])
			{
				flagit=1;
				break;
			}
		}
		if(flagit==0)
		{
			//printf("low=%lld high=%lld pos=%lld maxit=%lld flagit=%lld\n",low,high,pos,maxit,flagit);
			return val-arr[low];
		}
		else
		{
			ans1=findit(low,pos-1,maxit);
			ans2=findit(pos+1,high,maxit);
			ans=ans1+ans2+val-maxit;
			//printf("low=%lld high=%lld pos=%lld maxit=%lld ans1=%lld ans2=%lld ans=%lld val=%lld\n",low,high,pos,maxit,ans1,ans2,ans,val);
			return ans;
		}
	}
	return 0;
}
int main()
{
	ll n,k,i,maxit=-1,pos=-1,fin,ans1,ans2,ans;
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
//	printf("maxit=%lld pos=%lld\n",maxit,pos);
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

