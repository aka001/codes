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
ll arr[2001],storeit[2001][2001];
int main()
{
	int n,cnt=0,lenit,flagit=1,i,j,k;
	ll calc=1,sumit,x,y;
	char ch;
	si(n);
	ch=getchar();
	FOR(i,0,n)
	{
		lenit=0;
		ch=getchar();
		calc=1;
		sumit=0;
		cnt=0;
		while(ch!='\n' && ch!='\0')
		{
			if(ch!='0')
			{
				x=cnt/64;
				y=cnt%64;
				storeit[i][x]|=(1LL<<y);
			}
			cnt++;
			ch=getchar();
		}
	}
	lenit=(n+63)/64;
	cnt=0;
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if(i==j)
				continue;
			x=j/64;
			y=j%64;
			if(storeit[i][x]&(1LL<<y))
				continue;
			calc=0;
			//printf("i=%d j=%d lenit=%d\n",i,j,lenit);
			rep(k,lenit)
			{
				if(storeit[i][k]&storeit[j][k])
				{
					cnt++;
					break;
				}
			}
		}
	}
	pin(cnt);
	return 0;
}













