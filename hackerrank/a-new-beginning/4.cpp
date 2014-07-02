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
vector<int> primeit;
void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	primeit.pb(2);
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
			primeit.pb(i);
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
ll dp[50][200];
ll f(int dig, int sum)
{
	int i;
	if(dig==0)
		return (ll)sum==0;
	if(mem[dig][sum])
	{
		//printf("hie dig=%d sum=%d dp=%d\n",dig,sum,dp[dig][sum]);
		return dp[dig][sum];
	}
	mem[dig][sum]=1;
	ll ret=0;
	rep(i,10)
	{
		if(sum-i>=0)
			ret+=f(dig-1,sum-i);
	}
	dp[dig][sum]=ret;
	return ret;
}
vector<int> kmh;
ll solve(ll x,ll sum)
{
	int sizeit,i,quad,j,val,hmm,k;
	ll ansit=0,xit=0;
	sizeit=sprintf(buffer,"%lld",x);
	quad=sizeit;
	hmm=kmh.size();
	rep(i,sizeit)
	{
		quad--;
		val=buffer[i]-'0';
		for(j=0;j<val;j++)
		{
			rep(k,hmm)
			{
				sum=kmh[k]-xit;
				if(sum-j>=0)
				ansit+=f(quad,sum-j);
			}
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
	ll x,y,sum1,ans=0,sum,s1,s2,s3,sqrtit,i,j,num,sizeit,calc,t;
	seive();
	rep(i,150)
	{
		num=i;
		calc=0;
		sqrtit=sqrt(num);
		j=0;
		while(primeit[j]<=sqrtit)
		{
			if(num%primeit[j]==0)
			{
				calc+=primeit[j];
				while(num%primeit[j]==0)
					num/=primeit[j];
			}
			j++;
		}
		if(num!=1)
			calc+=num;
		if(calc!=0 && ((calc)&(calc-1))==0)
			kmh.pb(i);
	}
	sl(t);
	sizeit=kmh.size();
	while(t--)
	{
		ans=0;
		sl(x);
		sl(y);
		sum1=sum;
		s1=solve(y+1,sum);
		s2=solve(x,sum);
		s3=istrue(y,sum);
		ans+=s1-s2;
		pln(ans);
	}
	return 0;
}








