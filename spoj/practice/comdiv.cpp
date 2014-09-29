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
int cnt[1000006],isprime[1000010];
vector<int> prm;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int seive()
{
	ll MAX=1000006,i,j;
	isprime[1]=1;
	isprime[2]=1;
	isprime[2]=0;
	prm.pb(1);
	for(i=4;i<MAX;i+=2)
	{
		isprime[i]=1;
	}
	for(i=3;i<MAX;i+=2)
	{
		if(isprime[i]==0)
		{
			for(j=i*i;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	for(i=2;i<MAX;i++)
		if(isprime[i]==0)
			prm.pb(i);
}
int main()
{
	ll t,ans,a,b,sqrtit,calc,outit,c,i;
	seive();
	sl(t);
	while(t--)
	{
		sl(a);
		sl(b);
		ans=gcd(a,b);
		outit=0;
		sqrtit=sqrt(ans);
		//printf("ans=%lld sqrtit=%lld\n",ans,sqrtit);
		c=0;
		FOR(i,1,sqrtit)
		{
			if(ans%i==0)
			{
				outit+=2;
			}
			if(isprime[ans]==0)
				break;
			/*calc=prm[c];
		//	printf("calc=%lld\n",calc);
			if(calc>=sqrtit)
				break;
			if(ans%calc==0)
			{
				printf("calc=%lld\n",calc);
				outit+=2;
			}
			c++;*/
		}
		if(ans%sqrtit==0)
		{
			outit++;
			if(ans!=sqrtit*sqrtit)
				outit++;
		}
		pln(outit);
	}
	return 0;
}















