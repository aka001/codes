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
#define ll long long unsigned
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
#define sl(n) scanf("%llu",&n)
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
vector<ll> primeit;
ll dp[70][70];
ll calc(ll a)
{
	ll i,buffer[300],lenit=0,calc,sizeit,xit=0,j,k,temp,val,ans=0;
	sizeit=primeit.size();
	while(a!=0)
	{
		calc=a&01;
		buffer[lenit++]=calc;
		a/=2;
	}
	rep(i,lenit/2)
	{
		temp=buffer[lenit-i-1];
		buffer[lenit-i-1]=buffer[i];
		buffer[i]=temp;
	}
	/*pln(lenit);
	rep(i,lenit)
		printf("%llu",buffer[i]);
	printf("\n");*/
	calc=lenit;
	rep(i,lenit)
	{
		calc--;
		FOR(j,0,buffer[i])
		{
			FOR(k,0,sizeit)
			{
				val=primeit[k]-xit;
				if(val-j>=0 && val<=100)
				{
					ans+=dp[calc][val-j];
					//if(i==63)
					//	printf("primeit[%llu]=%llu xit=%llu val=%llu\n",k,primeit[k],xit,val);
				}
				//	printf("ans=%llu calc=%llu val=%llu j=%llu dp=%llu\n",ans,calc,val,j,val-j,dp[calc][val-j]);
			}
		}
		xit+=buffer[i];
	}
	return ans;
}
int main()
{
	ll flagit,i,sqrtit,t,j,k,a,b,ans;
	FOR(i,2,70)
	{
		sqrtit=sqrt(i);
		flagit=0;
		for(j=2;j<=sqrtit;j++)
		{
			if(i%j==0)
			{
				flagit=1;
				break;
			}
		}
		if(flagit==0)
			primeit.pb(i);
	}
	dp[0][0]=(ll)1;
	dp[0][1]=(ll)0;
	dp[1][1]=(ll)1;
	dp[1][0]=(ll)1;
	FOR(i,2,70)
	{
		dp[0][i]=0;
		dp[1][i]=0;
	}
	FOR(i,2,70)
	{
		FOR(j,0,70)
		{
			FOR(k,0,2)
			{
				if(j-k<0)
					break;
				dp[i][j]=(ll)((ll)dp[i][j]+(ll)dp[i-1][j-k]);
			}
		}
	}
	sl(t);
	while(t--)
	{
		sl(a);
		sl(b);
		ans=calc(b+1)-calc(a);
		pln(ans);
	}
	return 0;
}












