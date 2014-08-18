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
ll dp[10000],sum[10000],present[101][11];
int main()
{
	ll calc=0,val,valit,t,n,i,j,flagit,k,valit1,valit2;
	char ch;
	sl(t);
	while(t--)
	{
		calc=0;
		FOR(i,0,101)
		{
			FOR(j,0,11)
				present[i][j]=0;
		}
		dp[0]=1;
		sum[0]=1;
		sl(n);
		val=1<<n;
		FOR(i,1,val)
		{
			dp[i]=sum[i]=0;
		}
		ch=getchar();
		rep(i,n)
		{
			flagit=0;
			ch=getchar();
			while(ch!='\n' && ch!='\0')
			{
				calc=0;
				while(ch!=' ' && ch!='\n')
				{
					calc=calc*10+ch-'0';
					ch=getchar();
				}
				present[calc][i+1]=1;
				if(ch=='\n')
					break;
				ch=getchar();
			}
		}
		FOR(i,1,101)
		{
			FOR(j,1,11)
			{
				if(present[i][j]==1)
				{
					FOR(k,0,val)
					{
						valit=1<<(j-1);
						//printf("i=%lld k=%lld valit=%lld valit1=%lld %lld\n",i,k,valit,valit+k,k&valit);
						valit2=k&valit;
						if(valit2==0)
						{
							//printf("hie\n");
							valit1=valit+k;
							sum[valit1]+=dp[k];
							if(sum[valit1]>=mod)
								sum[valit1]%=mod;
						}
					}
				}
			}
			FOR(k,0,val)
				dp[k]=sum[k];
		}
		pln(dp[val-1]);
	}
	return 0;
}














