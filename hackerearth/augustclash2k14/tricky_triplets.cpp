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

int isprime[1000006]; 
void seive()
{
	int i,j;
	int MAX=1000006;
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
int prime[20],flag[20],checkit[1000006];
vector<int> storeit[11],primeno;
int findit[10][100006];
int main()
{
	ll val,cnt1,cnt2,ans=0,val1,sizeit,cnt,n,i,j,k,val2,l;
	primeno.pb(2);
	primeno.pb(3);
	primeno.pb(5);
	primeno.pb(7);
	prime[2]=1;
	prime[3]=1;
	prime[5]=1;
	prime[7]=1;
	sl(n);
	rep(i,n)
	{
		sl(val);
		rep(j,10)
			flag[j]=0;
		while(val!=0)
		{
			val1=val%10;
			if(flag[val1]==0 && prime[val1]==1)
			{
				storeit[val1].pb(i);
				findit[val1][i]=1;
			}
			flag[val1]=1;
			val/=10;
		}
	}
	ans=0;
	FOR(i,0,4)
	{
		val=primeno[i];
		sizeit=storeit[val].size();
		ans+=(sizeit*(sizeit-1)*(sizeit-2))/6;
	}
	{
		FOR(i,0,4)
		{
			val=primeno[i];
			FOR(j,i+1,4)
			{
				val1=primeno[j];
				cnt=0;
				FOR(k,0,100000)
				{
					if(findit[val][k]==1 && findit[val1][k]==1)
						cnt++;
				}
				ans-=(cnt*(cnt-1)*(cnt-2))/6;
			}
		}
	}
	FOR(i,0,4)
	{
		val=primeno[i];
		FOR(j,i+1,4)
		{
			val1=primeno[j];
			FOR(k,j+1,4)
			{
				val2=primeno[k];
				cnt=0;
				FOR(l,0,100000)
				{
					if(findit[val][l]==1 && findit[val1][l]==1 && findit[val2][l]==1)
						cnt++;
				}
				//printf("val=%lld val1=%lld val2=%lld cnt=%lld\n",val,val1,val2,cnt);
				ans+=(cnt*(cnt-1)*(cnt-2))/6;
			}
		}
	}
	cnt=0;
	FOR(i,0,100000)
	{
		if(findit[2][i]==1 && findit[3][i]==1 && findit[5][i]==1 && findit[7][i]==1)
			cnt++;
	}
	ans-=(cnt*(cnt-1)*(cnt-2))/6;
	pln(ans);
	return 0;
}











