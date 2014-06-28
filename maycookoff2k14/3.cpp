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
ll digit(ll n)
{
	ll cnt=0;
	while(n!=0)
	{
		cnt++;
		n/=10;
	}
	return cnt;
}
int main()
{
	int t,i;
	ll ref[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	ll n,cnt=0,calc,a,b,val,calc1,calc2;
	si(t);
	while(t--)
	{
		calc=0;
		sl(n);
		cnt=digit(n);
		rep(i,cnt)
		{
			calc1=9;
			calc2=ref[i]-2;
			while(calc2-->0)
			{
				calc1=calc1*10+9;
			}
			val=calc1;
			if(i==0)
				val=0;
			if(ref[i]==cnt)
				calc+=(n-val)*ref[i];
			else
			{
				if(i==0)
				{
					calc+=9*ref[i];
				}
				else
					calc+=val*((ll)(pow(10,i)))*ref[i];
			}
		}
		a=calc;
		b=n*10;
		calc=gcd(a,b);
		a/=calc;
		b/=calc;
		printf("%lld/%lld\n",a,b);
	}
	return 0;
}





