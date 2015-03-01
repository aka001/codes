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
int isprime[1000006]; 
vector<int> primeit;
void seive()
{
	ll i,j;
	ll MAX=1000006;
	isprime[0] = isprime[1] = 1;  
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1;  
	for (i = 3; i * i < MAX; i += 2)
	{
		if (!isprime[i])
		{
			for (j = i * i; j < MAX; j += 2 * i)
			{
				isprime[j] = 1;
			}
		}
	}
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]==0)
			primeit.pb(i);
	}
}
inline ll checkit(ll n)
{
	while(n<0)
		n+=mod;
	return n%mod;
}
int main()
{
	seive();
	ll calc,val,cit,c,n,n1,i1,t,i;
	sl(t);
	while(t--)
	{
		sl(n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		n1=n;
		calc=sqrt(n);
		i=0;
		val=n;
		c=1;
		while(primeit[i]<=calc)
		{
			if(n%primeit[i]==0)
			{
				while(n1%primeit[i]==0)
					n1/=primeit[i];
				i1=primeit[i];
				val*=(i1-1);
				val/=i1;
				c=c*(1-i1);
			}
			i++;
		}
		if(n1!=1)
		{
			c=c*(1-n1);
			val*=(n1-1);
			val/=n1;
		}
		val%=mod;
		cit=n*val;
		cit%=mod;
		cit*=n;
		cit%=mod;
		cit*=modpow(3,mod-2,mod);
		cit%=mod;
		//pln(cit);
		//pln(c);
		c=checkit(c);
		c*=n;
		c=checkit(c);
		c*=modpow(6,mod-2,mod);
		cit+=c;
		cit=checkit(cit);
		//pln(cit);
		pln(cit);
	}
	return 0;
}






