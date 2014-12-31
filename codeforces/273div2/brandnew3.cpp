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

int main()
{
	ll r,g,b,a,med,c,ans=0,calc;
	sl(r);
	sl(g);
	sl(b);
	a=r;
	a=min(a,g);
	a=min(a,b);
	c=r;
	c=max(c,g);
	c=max(c,b);
	med=(r+g+b)-(a+c);
	//printf("a=%lld med=%lld c=%lld\n",a,med,c);
	while(a!=0 && med!=0 && c!=0)
	{
		calc=c/2;
		if(calc>=med)
			calc=med;
		ans+=calc;
		med-=calc;
		c-=2*calc;

		r=a;
		g=med;
		b=c;

		a=r;
		a=min(a,g);
		a=min(a,b);
		c=r;
		c=max(c,g);
		c=max(c,b);
		med=(r+g+b)-(a+c);
		//printf("a=%lld med=%lld c=%lld\n",a,med,c);
		if(a==1 && med==1 && c==1)
		{
			ans++;
			a=b=c=0;
			break;
		}
	}
	r=a;
	g=med;
	b=c;

	a=r;
	a=min(a,g);
	a=min(a,b);
	c=r;
	c=max(c,g);
	c=max(c,b);
	med=(r+g+b)-(a+c);

	while(med!=0 && c!=0)
	{
		calc=c/2;
		if(calc>=med)
			calc=med;
		ans+=calc;
		med-=calc;
		c-=2*calc;

		r=med;
		g=c;

		med=r;
		med=min(med,g);

		c=r;
		c=max(c,g);

		if(med+c<3)
			break;
	}
	pln(ans);
	return 0;
}












