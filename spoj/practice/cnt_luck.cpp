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
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
char buffer[1000];
bool mem[50][200];
ll dp[500][200];
vector<int> lucky;
ll solve(ll x,ll sum)
{
	int sizeit=0,i,quad,j,val,hmm,k,temp;
	ll ansit=0,xit=0;
	while(x!=0)
	{
		buffer[sizeit++]=x&01;
		x>>=1;
	}
	rep(i,sizeit/2)
	{
		temp=buffer[i];
		buffer[i]=buffer[sizeit-i-1];
		buffer[sizeit-i-1]=temp;
	}
	quad=sizeit;
	hmm=lucky.size();
	rep(i,sizeit)
	{
		quad--;
		val=buffer[i];
		//printf("val=%d i=%d\n",val,i);
		for(j=0;j<val;j++)
		{
			rep(k,hmm)
			{
				sum=lucky[k]-xit;
				if(sum-j>=0)
					ansit+=dp[quad][sum-j];
			}
			//printf("ansit=%lld\n",ansit);
		}
		xit+=val;
	}
	return ansit;
}
bool istrue(ll x,ll sum1)
{
	int i,calc=0;
	while(x!=0)
	{
		calc+=x%10;
		x/=10;
	}
	return calc==sum1;
}
int main()
{
	ll x,y,sum1,ans=0,sum,s1,s2,s3,sqrtit,i,j,num,sizeit,calc,t,k;
	lucky.pb(4);
	lucky.pb(7);
	lucky.pb(44);
	lucky.pb(47);
	lucky.pb(74);
	lucky.pb(77);
	dp[0][0]=1;
	dp[1][0]=1;
	dp[1][1]=1;
	for(i=2;i<=60;i++)
		dp[1][i]=0;
	for(i=2;i<=60;i++)
	{
		for(j=0;j<=100;j++)
		{
			for(k=0;k<=1;k++)
			{
				if(j-k>=0)
				{
					dp[i][j]+=dp[i-1][j-k];
				}
				else 
					break;
			}
		}
	}
	sl(t);
	while(t--)
	{
		ans=0;
		sl(x);
		sl(y);
		sum=0;
		sum1=sum;
		s1=solve(y+1,sum);
		s2=solve(x,sum);
		//s3=istrue(y,sum);
		//printf("s1=%lld s2=%lld\n",s1,s2);
		ans+=s1-s2;
		pln(ans);
	}
	return 0;
}








