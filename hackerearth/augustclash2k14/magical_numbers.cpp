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
vector<ll> dp;
int isprime[10];
ll countit(ll n)
{
	ll buffer[100],sizeit=0,temp,i,ans=0,calc,flagit=0,j,val;
	calc=(ll)((ll)mod*(ll)mod);
	while(n!=0)
	{
		buffer[sizeit++]=n%10;
		n/=10;
	}
	rep(i,sizeit/2)
	{
		temp=buffer[i];
		buffer[i]=buffer[sizeit-i-1];
		buffer[sizeit-i-1]=temp;
	}
	//printf("sizeit=%lld\n",sizeit);
	rep(i,sizeit)
	{
		val=buffer[i];
		rep(j,val)
		{
			if(isprime[j]!=1 && flagit==0)
			{
				ans+=dp[sizeit-i-1];
				//printf("i=%lld sizeit-i-1=%lld ans=%lld dp=%lld\n",i,sizeit-i-1,ans,dp[sizeit-i-1]);
			}
			else
			{
				ans+=modpow(10,sizeit-i-1,calc);
			}
		}
		//pln(ans);
		if(isprime[val])
			flagit=1;
	}
	return ans;
}
int main()
{
	int t,i;
	ll n,six=6,ten=10,calc,val;
	rep(i,10)
		isprime[i]=0;
	isprime[2]=1;
	isprime[3]=1;
	isprime[5]=1;
	isprime[7]=1;
	dp.pb(0);
	rep(i,19)
	{
		dp.pb(ten-six);
		ten*=10;
		six*=6;
	}
	si(t);
	while(t--)
	{
		sl(n);
		n++;
		calc=countit(n);
		pln(calc);
	}
	return 0;
}








