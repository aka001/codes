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

long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
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
}
ll powerit[100000];
int sizeit;
ll findit(ll x)
{
	int low=0,high=sizeit,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(mid==0 || (powerit[mid-1]<x && powerit[mid]>=x))
		{
			break;
		}
		else if(x>powerit[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return powerit[mid];
}
int main()
{
	ll val=1,t,doit,doit1,a,b,c,d,mult[5],ans=1,calc,calc1,calc2,fir,x,y;
	int v,cnt=0;
	sizeit=0;
	/*while(val<=10000000)
	{
		powerit[sizeit++]=val;
		val*=2;
	}
	powerit[sizeit++]=val;*/
	sl(t);
	while(t--)
	{
		sl(fir);
		val=1;
		cnt=0;
		sl(mult[0]);
		sl(mult[1]);
		sl(mult[2]);
		sl(mult[3]);
		sl(x);
		sl(y);
		ans=fir;
		calc1=(ll)ceil(log2(x));
		doit=calc1;
		calc1=1<<calc1;
		//calc1=findit(x);
		calc2=(ll)ceil(log2(y));
		doit1=calc2;
		calc2=1<<calc2;
		//calc2=findit(y);
		calc=max(calc1,calc2);
		calc1=max(doit,doit1);
		v=0;
		while(calc1--)
		{
			cnt++;
			calc/=2;
			//printf("x=%lld y=%lld calc1=%lld mult=%lld v=%d calc=%lld\n",x,y,calc1,mult[v],v,calc);
			if(x>calc && y>calc)
			{
				x-=calc;
				y-=calc;
				v=3;
			}
			else if(x>calc && y<=calc)
			{
				x-=calc;
				v=2;
			}
			else if(x<=calc && y>calc)
			{
				y-=calc;
				v=1;
			}
			else
			{
				v=0;
			}
			ans*=mult[v];
			//printf("x=%lld y=%lld calc1=%lld mult=%lld v=%d calc=%lld\n\n",x,y,calc1,mult[v],v,calc);
			/*cnt++;
			if(cnt>=16)
				break;*/
		}
		pln(ans);
	}
	return 0;
}











