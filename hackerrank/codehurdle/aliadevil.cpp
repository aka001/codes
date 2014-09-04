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

int fib[1000000];
int main()
{
	int t,n,m,sqrtit,a,b,i,c,calc,ans,j;
	a=0;
	b=1;
	fib[a]=1;
	fib[b]=1;
	rep(i,60)
	{
		c=a+b;
		a=b;
		b=c;
		if(c>=100000)
			break;
		fib[c]=1;
	}
	si(t);
	rep(j,t)
	{
		si(n);
		si(m);
		sqrtit=sqrt(n);
		sqrtit++;
		calc=1;
		FOR(i,2,sqrtit)
		{
			if(n%i==0)
			{
				calc+=i;
				if(n/i!=i)
				{
					calc+=n/i;
				}
				if(calc>m)
					calc%=m;
			}
		}
		calc=calc%m;
		//printf("calc=%d\n",calc);
		ans=1;
		sqrtit=sqrt(calc);
		sqrtit++;
		FOR(i,2,sqrtit)
		{
			if(calc%i==0)
			{
				ans++;
				if(calc/i!=i)
					ans++;
			}
		}
		//printf("ans=%d\n",ans);
		printf("Case #%d : ",j+1);
		if(fib[ans]==1)
			printf("YES.\n");
		else
			printf("NO.\n");
	}
	return 0;
}











