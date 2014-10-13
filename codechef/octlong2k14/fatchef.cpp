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
#define mod 1000000009
#define ll long long int
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
char ch;
int main()
{
	ll t,n,m,val,calc,calc1,i,sz,ans,pnt,end,end1,pres;
	sl(t);
	while(t--)
	{
		ans=1;
		sl(n);
		sl(m);
		getchar();
		vector<pair<ll,ll> > pit;
		rep(i,m)
		{
			scanf("%c %lld\n",&ch,&calc1);
			calc=ch-'A';
			//printf("calc=%lld calc1=%lld\n",calc,calc1);
			pit.pb(mp(calc1,calc));
		}
		sort(pit.begin(), pit.end());
		sz=pit.size();
		//printf("sz=%lld\n",sz);
		if(sz>=1)
		{
			pres=pit[0].S;
			calc=pit[0].F;
		}
		//printf("pres=%lld calc=%lld\n",pres,calc);
		FOR(i,1,sz)
		{
			if(pit[i].S!=pres)
			{
				//printf("S=%lld F=%lld\n",pit[i].S,pit[i].F);
				if(pit[i].F!=calc)
					ans*=abs(pit[i].F-calc);
				if(ans>=mod)
					ans%=mod;
				pres=pit[i].S;
				calc=pit[i].F;
			}
			pres=pit[i].S;
			calc=pit[i].F;
		}
		ans%=mod;
		pln(ans);
	}
	return 0;
}











