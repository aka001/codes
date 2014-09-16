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
#define mod (long long int)(1e9 + 7)
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n%2==1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
ll comb[1000006],fact[1000020],ans[1000006];
int main()
{
	ll i,n,temp;
	ll calc,calc1,useit,sum=0;
	comb[0]=1;
	fact[0]=1;
	FOR(i,1,1000015)
	{
		fact[i]=fact[i-1]*i;
		if(fact[i]>mod)
			fact[i]%=mod;
	}
	useit=modpow(fact[5],mod-2,mod);
	useit%=mod;
	//printf("useit=%lld\n",useit);
	FOR(i,1,1000005)
	{
		calc=i+5;
		calc1=5;
		calc=(ll)((fact[i+5]*modpow(fact[i],mod-2,mod))%mod)*(ll)useit;
		calc=(ll)(calc%mod);
		//temp=calc>mod;
		comb[i]=calc;
	}
	rep(i,13)
		ans[i]=0;
	sl(n);
	FOR(i,13,n+1)
	{
		calc=i-13;
		if(calc%2==1)
		{
			calc/=2;
		}
		else
		{
			calc/=2;
			sum+=comb[calc];
		}
		if(sum>mod)
			sum%=mod;
		ans[i]=sum;
	}
	ans[n]%=mod;
	printf("%lld\n",ans[n]);
	return 0;
}











