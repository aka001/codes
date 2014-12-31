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
inline ll checkneg(ll n)
{
	while(n<mod)
		n+=mod;
	n%=mod;
	return n;
}
int main()
{
	ll q,n,t,ans,calc,calc1,val;
	sl(q);
	while(q--)
	{
		sl(n);
		sl(t);
		if(t==0)
		{
			printf("1\n");
			continue;
		}
		else
		{
			ans=1;
			if(n!=1)
			{
				t--;
				val=n;
				calc=modpow(val,t+1,mod)-1;
				calc=checkneg(calc);
				calc1=modpow(val-1,mod-2,mod);
				calc*=calc1;
				calc=checkneg(calc);
			}
			else
			{
				calc=t;
			}
			calc=calc*2*n;
			calc=checkneg(calc);
			ans+=calc;
			ans=checkneg(ans);
			pln(ans);
		}
	}
	return 0;
}
















