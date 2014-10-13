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
vector<ll> str;
ll p;
void fillit(ll p)
{
	ll i,calc;
	str.pb(1);
	FOR(i,2,p)
	{
		calc=i*i*i;
		if(calc%p==1)
			str.pb(i);
	}
}
ll solve(ll a)
{
	ll sz,i,ans=0;
	sz=str.size();
	rep(i,sz)
	{
		if(str[i]<=a)
		{
			ans++;
			ans+=(a-str[i])/p;
		}
	}
	return ans;
}
int main()
{
	int t;
	ll a,b,calc,calc1,sz;
	si(t);
	while(t--)
	{
		str.clear();
		sl(a);
		sl(b);
		sl(p);
		if(p==1)
		{
			printf("0\n");
			continue;
		}
		fillit(p);
		/*sz=str.size();
		rep(i,sz)
		{
			printf("%d\n",str[i]);
		}*/
		calc=solve(a-1);
		calc1=solve(b);
		calc1-=calc;
		pln(calc1);
	}
	return 0;
}












